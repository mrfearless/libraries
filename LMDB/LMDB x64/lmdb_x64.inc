;/** @file lmdb.h
; *	@brief Lightning memory-mapped database library
; *
; *	@mainpage	Lightning Memory-Mapped Database Manager (LMDB)
; *
; *	@section intro_sec Introduction
; *	LMDB is a Btree-based database management library modeled loosely on the
; *	BerkeleyDB API, but much simplified. The entire database is exposed
; *	in a memory map, and all data fetches return data directly
; *	from the mapped memory, so no malloc's or memcpy's occur during
; *	data fetches. As such, the library is extremely simple because it
; *	requires no page caching layer of its own, and it is extremely high
; *	performance and memory-efficient. It is also fully transactional with
; *	full ACID semantics, and when the memory map is read-only, the
; *	database integrity cannot be corrupted by stray pointer writes from
; *	application code.
; *
; *	The library is fully thread-aware and supports concurrent read/write
; *	access from multiple processes and threads. Data pages use a copy-on-
; *	write strategy so no active data pages are ever overwritten, which
; *	also provides resistance to corruption and eliminates the need of any
; *	special recovery procedures after a system crash. Writes are fully
; *	serialized; only one write transaction may be active at a time, which
; *	guarantees that writers can never deadlock. The database structure is
; *	multi-versioned so readers run with no locks; writers cannot block
; *	readers, and readers don't block writers.
; *
; *	Unlike other well-known database mechanisms which use either write-ahead
; *	transaction logs or append-only data writes, LMDB requires no maintenance
; *	during operation. Both write-ahead loggers and append-only databases
; *	require periodic checkpointing and/or compaction of their log or database
; *	files otherwise they grow without bound. LMDB tracks free pages within
; *	the database and re-uses them for new write operations, so the database
; *	size does not grow without bound in normal use.
; *
; *	The memory map can be used as a read-only or read-write map. It is
; *	read-only by default as this provides total immunity to corruption.
; *	Using read-write mode offers much higher write performance, but adds
; *	the possibility for stray application writes thru pointers to silently
; *	corrupt the database. Of course if your application code is known to
; *	be bug-free (...) then this is not an issue.
; *
; *	If this is your first time using a transactional embedded key/value
; *	store, you may find the \ref starting page to be helpful.
; *
; *	@section caveats_sec Caveats
; *	Troubleshooting the lock file, plus semaphores on BSD systems:
; *
; *	- A broken lockfile can cause sync issues.
; *	  Stale reader transactions left behind by an aborted program
; *	  cause further writes to grow the database quickly, and
; *	  stale locks can block further operation.
; *
; *	  Fix: Check for stale readers periodically, using the
; *	  #mdb_reader_check function or the \ref mdb_stat_1 "mdb_stat" tool.
; *	  Stale writers will be cleared automatically on most systems:
; *	  - Windows - automatic
; *	  - BSD, systems using SysV semaphores - automatic
; *	  - Linux, systems using POSIX mutexes with Robust option - automatic
; *	  Otherwise just make all programs using the database close it;
; *	  the lockfile is always reset on first open of the environment.
; *
; *	- On BSD systems or others configured with MDB_USE_SYSV_SEM or
; *	  MDB_USE_POSIX_SEM,
; *	  startup can fail due to semaphores owned by another userid.
; *
; *	  Fix: Open and close the database as the user which owns the
; *	  semaphores (likely last user) or as root, while no other
; *	  process is using the database.
; *
; *	Restrictions/caveats (in addition to those listed for some functions):
; *
; *	- Only the database owner should normally use the database on
; *	  BSD systems or when otherwise configured with MDB_USE_POSIX_SEM.
; *	  Multiple users can cause startup to fail later, as noted above.
; *
; *	- There is normally no pure read-only mode, since readers need write
; *	  access to locks and lock file. Exceptions: On read-only filesystems
; *	  or with the #MDB_NOLOCK flag described under #mdb_env_open().
; *
; *	- An LMDB configuration will often reserve considerable \b unused
; *	  memory address space and maybe file size for future growth.
; *	  This does not use actual memory or disk space, but users may need
; *	  to understand the difference so they won't be scared off.
; *
; *	- By default, in versions before 0.9.10, unused portions of the data
; *	  file might receive garbage data from memory freed by other code.
; *	  (This does not happen when using the #MDB_WRITEMAP flag.) As of
; *	  0.9.10 the default behavior is to initialize such memory before
; *	  writing to the data file. Since there may be a slight performance
; *	  cost due to this initialization, applications may disable it using
; *	  the #MDB_NOMEMINIT flag. Applications handling sensitive data
; *	  which must not be written should not use this flag. This flag is
; *	  irrelevant when using #MDB_WRITEMAP.
; *
; *	- A thread can only use one transaction at a time, plus any child
; *	  transactions.  Each transaction belongs to one thread.  See below.
; *	  The #MDB_NOTLS flag changes this for read-only transactions.
; *
; *	- Use an MDB_env* in the process which opened it, not after fork().
; *
; *	- Do not have open an LMDB database twice in the same process at
; *	  the same time.  Not even from a plain open() call - close()ing it
; *	  breaks fcntl() advisory locking.  (It is OK to reopen it after
; *	  fork() - exec*(), since the lockfile has FD_CLOEXEC set.)
; *
; *	- Avoid long-lived transactions.  Read transactions prevent
; *	  reuse of pages freed by newer write transactions, thus the
; *	  database can grow quickly.  Write transactions prevent
; *	  other write transactions, since writes are serialized.
; *
; *	- Avoid suspending a process with active transactions.  These
; *	  would then be "long-lived" as above.  Also read transactions
; *	  suspended when writers commit could sometimes see wrong data.
; *
; *	...when several processes can use a database concurrently:
; *
; *	- Avoid aborting a process with an active transaction.
; *	  The transaction becomes "long-lived" as above until a check
; *	  for stale readers is performed or the lockfile is reset,
; *	  since the process may not remove it from the lockfile.
; *
; *	  This does not apply to write transactions if the system clears
; *	  stale writers, see above.
; *
; *	- If you do that anyway, do a periodic check for stale readers. Or
; *	  close the environment once in a while, so the lockfile can get reset.
; *
; *	- Do not use LMDB databases on remote filesystems, even between
; *	  processes on the same host.  This breaks flock() on some OSes,
; *	  possibly memory map sync, and certainly sync between programs
; *	  on different hosts.
; *
; *	- Opening a database can fail if another process is opening or
; *	  closing it at exactly the same time.
; *
; *	@author	Howard Chu, Symas Corporation.
; *
; *	@copyright Copyright 2011-2021 Howard Chu, Symas Corp. All rights reserved.
; *
; * Redistribution and use in source and binary forms, with or without
; * modification, are permitted only as authorized by the OpenLDAP
; * Public License.
; *
; * A copy of this license is available in the file LICENSE in the
; * top-level directory of the distribution or, alternatively, at
; * <http://www.OpenLDAP.org/license.html>.
; *
; *	@par Derived From:
; * This code is derived from btree.c written by Martin Hedenfalk.
; *
; * Copyright (c) 2009, 2010 Martin Hedenfalk <martin@bzero.se>
; *
; * Permission to use, copy, modify, and distribute this software for any
; * purpose with or without fee is hereby granted, provided that the above
; * copyright notice and this permission notice appear in all copies.
; *
; * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
; * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
; * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
; * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
; * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
; * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
; * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
; */

; https://www.symas.com/lmdb
; https://github.com/LMDB/lmdb
; http://www.lmdb.tech/doc/group__mdb.html
; https://blogs.kolabnow.com/2018/06/07/a-short-guide-to-lmdb

; LMDB_x64.inc converted from LMDB source for assembler by fearless 2024
; www.github.com/mrfearless


include advapi32.inc
includelib advapi32.lib

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib


; MDB_assert_func       PROTO env:QWORD,msg:QWORD ; callback function
mdb_cmp                 PROTO txn:QWORD,dbi:QWORD,a:QWORD,b:QWORD
mdb_cursor_close        PROTO cursor:QWORD
mdb_cursor_count        PROTO cursor:QWORD,countp:QWORD
mdb_cursor_dbi          PROTO cursor:QWORD
mdb_cursor_del          PROTO cursor:QWORD,flags:QWORD
mdb_cursor_get          PROTO cursor:QWORD,key:QWORD,data:QWORD,op:QWORD
mdb_cursor_open         PROTO txn:QWORD,dbi:QWORD,cursor:QWORD
mdb_cursor_put          PROTO cursor:QWORD,key:QWORD,data:QWORD,flags:QWORD
mdb_cursor_renew        PROTO txn:QWORD,cursor:QWORD
mdb_cursor_txn          PROTO cursor:QWORD
mdb_dbi_close           PROTO env:QWORD,dbi:QWORD
mdb_dbi_flags           PROTO txn:QWORD,dbi:QWORD,flags:QWORD
mdb_dbi_open            PROTO txn:QWORD,dbname:QWORD,flags:QWORD,dbi:QWORD
mdb_dcmp                PROTO txn:QWORD,dbi:QWORD,a:QWORD,b:QWORD
mdb_del                 PROTO txn:QWORD,dbi:QWORD,key:QWORD,data:QWORD
mdb_drop                PROTO txn:QWORD,dbi:QWORD,del:QWORD
mdb_env_close           PROTO env:QWORD
mdb_env_copy2           PROTO env:QWORD,path:QWORD,flags:QWORD
mdb_env_copy            PROTO env:QWORD,path:QWORD
mdb_env_copyfd2         PROTO env:QWORD,fd:QWORD,flags:QWORD
mdb_env_copyfd          PROTO env:QWORD,fd:QWORD
mdb_env_create          PROTO env:QWORD
mdb_env_get_fd          PROTO env:QWORD,fd:QWORD
mdb_env_get_flags       PROTO env:QWORD,flags:QWORD
mdb_env_get_maxkeysize  PROTO env:QWORD
mdb_env_get_maxreaders  PROTO env:QWORD,readers:QWORD
mdb_env_get_path        PROTO env:QWORD,path:QWORD
mdb_env_get_userctx     PROTO env:QWORD
mdb_env_info            PROTO env:QWORD,stat:QWORD
mdb_env_open            PROTO env:QWORD,path:QWORD,flags:QWORD,mode:QWORD
mdb_env_set_assert      PROTO env:QWORD,func:QWORD
mdb_env_set_flags       PROTO env:QWORD,flags:QWORD,onoff:QWORD
mdb_env_set_mapsize     PROTO env:QWORD,mapsize:QWORD
mdb_env_set_maxdbs      PROTO env:QWORD,dbs:QWORD
mdb_env_set_maxreaders  PROTO env:QWORD,readers:QWORD
mdb_env_set_userctx     PROTO env:QWORD,ctx:QWORD
mdb_env_stat            PROTO env:QWORD,stat:QWORD
mdb_env_sync0           PROTO :QWORD,:QWORD,:QWORD
mdb_env_sync            PROTO env:QWORD,force:QWORD
mdb_get                 PROTO txn:QWORD,dbi:QWORD,key:QWORD,data:QWORD
; MDB_msg_func          PROTO msg:QWORD,ctx:QWORD ; callback function
mdb_put                 PROTO txn:QWORD,dbi:QWORD,key:QWORD,data:QWORD,flags:QWORD
mdb_reader_check        PROTO env:QWORD,dead:QWORD
mdb_reader_list         PROTO env:QWORD,func:QWORD,ctx:QWORD
mdb_set_compare         PROTO txn:QWORD,dbi:QWORD,cmp_func:QWORD
mdb_set_dupsort         PROTO txn:QWORD,dbi:QWORD,cmp_func:QWORD
mdb_set_relctx          PROTO txn:QWORD,dbi:QWORD,ctx:QWORD
mdb_set_relfunc         PROTO txn:QWORD,dbi:QWORD,rel:QWORD
mdb_stat                PROTO txn:QWORD,dbi:QWORD,stat:QWORD
mdb_strerror            PROTO err:QWORD
mdb_tls_cbp             PROTO C :VARARG
mdb_txn_abort           PROTO txn:QWORD
mdb_txn_begin           PROTO env:QWORD,parent:QWORD,flags:QWORD,txn:QWORD
mdb_txn_commit          PROTO txn:QWORD
mdb_txn_env             PROTO txn:QWORD
mdb_txn_id              PROTO txn:QWORD
mdb_txn_renew           PROTO txn:QWORD
mdb_txn_reset           PROTO txn:QWORD
mdb_version             PROTO major:QWORD,minor:QWORD,patch:QWORD

mdb_mid2l_append        PROTO :QWORD,:QWORD
mdb_mid2l_insert        PROTO :QWORD,:QWORD
mdb_mid2l_search        PROTO :QWORD,:QWORD
mdb_midl_alloc          PROTO :QWORD
mdb_midl_append         PROTO :QWORD,:QWORD
mdb_midl_append_list    PROTO :QWORD,:QWORD
mdb_midl_append_range   PROTO :QWORD,:QWORD,:QWORD
mdb_midl_free           PROTO :QWORD
mdb_midl_need           PROTO :QWORD,:QWORD
mdb_midl_search         PROTO :QWORD,:QWORD
mdb_midl_shrink         PROTO :QWORD
mdb_midl_sort           PROTO :QWORD
mdb_midl_xmerge         PROTO :QWORD,:QWORD

IFNDEF size_t
size_t                  TYPEDEF QWORD
ENDIF

mdb_mode_t              TYPEDEF QWORD
mdb_size_t              TYPEDEF size_t
mdb_filehandle_t        TYPEDEF QWORD
MDB_env                 TYPEDEF QWORD
MDB_txn                 TYPEDEF QWORD
MDB_dbi                 TYPEDEF QWORD
MDB_cursor              TYPEDEF QWORD
MDB_cursor_op           TYPEDEF QWORD
IFNDEF POINTER
POINTER                 TYPEDEF QWORD
ENDIF


; Generic structure used for passing keys and data in and out of the database
MDB_val                 STRUCT 8
    mv_size             size_t ? ; size of the data item
    mv_data             POINTER ? ; address of the data item
MDB_val                 ENDS

; Statistics for a database in the environment
MDB_stat                STRUCT 8
    ms_psize            DWORD ? ; Size of a database page
    ms_depth            DWORD ? ; Depth (height) of the B-tree
    ms_branch_pages     mdb_size_t ? ; Number of internal (non-leaf) pages
    ms_leaf_pages       mdb_size_t ? ; Number of leaf pages
    ms_overflow_pages   mdb_size_t ? ; Number of overflow pages
    ms_entries          mdb_size_t ? ; Number of data items
MDB_stat                ENDS

; Information about the environment
MDB_envinfo             STRUCT 8
    me_mapaddr          POINTER ? ; Address of map, if fixed
    me_mapsize          mdb_size_t ? ; Size of the data memory map
    me_last_pgno        mdb_size_t ? ; ID of the last used page
    me_last_txnid       mdb_size_t ? ; ID of the last committed transaction
    me_maxreaders       DWORD ? ; max reader slots in the environment
    me_numreaders       DWORD ? ; max reader slots used in the environment
MDB_envinfo             ENDS



.CONST
MDB_VERSION_MAJOR       EQU 0
MDB_VERSION_MINOR       EQU 9
MDB_VERSION_PATCH       EQU 70

MDB_VERSION_DATE        TEXTEQU <"December 19, 2015",0>
ifdef _WIN32
    MDB_FMT_Z           EQU <"I",0>
else
    MDB_FMT_Z           EQU <"z",0>
endif

; mdb_env Environment Flags
MDB_FIXEDMAP            EQU 01h
MDB_NOSUBDIR            EQU 4000h
MDB_NOSYNC              EQU 10000h
MDB_RDONLY              EQU 20000h
MDB_NOMETASYNC          EQU 40000h
MDB_WRITEMAP            EQU 80000h
MDB_MAPASYNC            EQU 100000h
MDB_NOTLS               EQU 200000h
MDB_NOLOCK              EQU 400000h
MDB_NORDAHEAD           EQU 800000h
MDB_NOMEMINIT           EQU 1000000h
MDB_PREVSNAPSHOT        EQU 2000000h
  
; mdb_dbi_open Database Flags
MDB_REVERSEKEY          EQU 02h
MDB_DUPSORT             EQU 04h
MDB_INTEGERKEY          EQU 08h
MDB_DUPFIXED            EQU 10h
MDB_INTEGERDUP          EQU 20h
MDB_REVERSEDUP          EQU 40h
MDB_CREATE              EQU 40000h

; mdb_put Write Flags
MDB_NOOVERWRITE         EQU 10h
MDB_NODUPDATA           EQU 20h
MDB_CURRENT             EQU 40h
MDB_RESERVE             EQU 10000h
MDB_APPEND              EQU 20000h
MDB_APPENDDUP           EQU 40000h
MDB_MULTIPLE            EQU 80000h

; mdb_copy Copy Flags
MDB_CP_COMPACT          EQU 01h

; MDB_cursor_op Cursor Get operations.
MDB_FIRST               EQU 0
MDB_FIRST_DUP           EQU 1
MDB_GET_BOTH            EQU 2
MDB_GET_BOTH_RANGE      EQU 3
MDB_GET_CURRENT         EQU 4
MDB_GET_MULTIPLE        EQU 5
MDB_LAST                EQU 6
MDB_LAST_DUP            EQU 7
MDB_NEXT                EQU 8
MDB_NEXT_DUP            EQU 9
MDB_NEXT_MULTIPLE       EQU 10
MDB_NEXT_NODUP          EQU 11
MDB_PREV                EQU 12
MDB_PREV_DUP            EQU 13
MDB_PREV_NODUP          EQU 14
MDB_SET                 EQU 15
MDB_SET_KEY             EQU 16
MDB_SET_RANGE           EQU 17
MDB_PREV_MULTIPLE       EQU 18

; errors Return Codes
MDB_SUCCESS             EQU 0
MDB_KEYEXIST            EQU -30799
MDB_NOTFOUND            EQU -30798
MDB_PAGE_NOTFOUND       EQU -30797
MDB_CORRUPTED           EQU -30796
MDB_PANIC               EQU -30795
MDB_VERSION_MISMATCH    EQU -30794
MDB_INVALID             EQU -30793
MDB_MAP_FULL            EQU -30792
MDB_DBS_FULL            EQU -30791
MDB_READERS_FULL        EQU -30790
MDB_TLS_FULL            EQU -30789
MDB_TXN_FULL            EQU -30788
MDB_CURSOR_FULL         EQU -30787
MDB_PAGE_FULL           EQU -30786
MDB_MAP_RESIZED         EQU -30785
MDB_INCOMPATIBLE        EQU -30784
MDB_BAD_RSLOT           EQU -30783
MDB_BAD_TXN             EQU -30782
MDB_BAD_VALSIZE         EQU -30781
MDB_BAD_DBI             EQU -30780
MDB_PROBLEM             EQU -30779
MDB_LAST_ERRCODE        EQU <MDB_PROBLEM>










