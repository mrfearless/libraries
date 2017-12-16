; Example SQLite3 database application for MASM32 by Mark Jones 2007
; A good admin tool for SQLite3 databases is SQLite Database Browser
; available from   http://sourceforge.net/projects/sqlitebrowser/

include masm32rt.inc                                ; MASM32 v8.2 SP2a+ RTL's

include msvcrt.inc
includelib msvcrt.lib
includelib msvcrt12.lib

include sqlite3.inc                                 ; SQLite3 v3.4.2 libs
includelib sqlite3.lib

CallbackProcColumnNames proto :DWORD,:DWORD,:DWORD,:DWORD
CallbackProc proto :DWORD,:DWORD,:DWORD,:DWORD
printit proto :DWORD

.data                                               ; preinitialized (file) data
    
.data?                                              ; runtime (ram) data
    DBFile      db  MAX_PATH dup(?)                 ; name of .db file, misc buffer
    DBase       dd  ?                               ; pointer to DB struct
    errMsg      dd  ?                               ; pointer to error msg
    
.code
main:                                               ; entrypoint
    invoke GetCommandLine                           ; get our current commandline
    mov esi,eax                                     ; source = commandline
    lea edi,DBFile                                  ; dest = path string
    cmp byte ptr [esi],'"'                          ; does source start with " ?
    je EL                                           ; if so, go to end of LFN
@@: movsb                                           ; copy chr edi<--esi, both ++
    cmp byte ptr [esi-1]," "                        ; stop after space copied
    jne @B                                          ; loop until space copied
    mov byte ptr [edi-1],"."                        ; overwrite space with a .
    jmp WR                                          ; and write extension
EL: inc esi                                         ; point to next char
    cmp byte ptr [esi],'"'                          ; is it the trailing " ?
    jne EL                                          ; loop until found
@@: dec esi                                         ; search reverse from end
    cmp byte ptr [esi-1],"\"                        ; until the last \ is found
    jnz @B                                          ; loop
@@: movsb                                           ; copy chr edi<--esi, ++   
    cmp byte ptr [edi-1],"."                        ; did we write the . ?
    jne @B                                          ; loop until copied
WR: mov dword ptr [edi],00006264h                   ; overwrite 'exe' with 'db  '


    print chr$(" SQLite3 Sample Application by MCJ 2007",13,10)
    print chr$(" DB File: ")
    print addr DBFile                               ; SQLiteTest.db
    print chr$(13,10)
; ----------------------------------------------------------------------------
.data
SQLCreateDB db  "BEGIN EXCLUSIVE TRANSACTION;",13,10
            db  "CREATE TABLE IF NOT EXISTS 'Table1'(",13,10
            db  "[ID] int PRIMARY KEY",13,10
            db  ",[Name] varchar",13,10
            db  ",[Handle] varchar",13,10
            db  ",[Likes] varchar",13,10
            db  ",[Dislikes] varchar",13,10
            db  ");",13,10
            db  "INSERT INTO Table1 VALUES(0,'Melody Tsu','9ustydolem','Programming','Liver Pie');",13,10
            db  "INSERT INTO Table1 VALUES(1,'Fred Dusty','411Freddie','Jovaan Musk','Politics!!!');",13,10
            db  "INSERT INTO Table1 VALUES(2,'Gary Tager','YoDaddy227','Rice Pilaaf','Celibacy');",13,10
            db  "INSERT INTO Table1 VALUES(3,'Jen Brewki','JenBob2521','Budweiseeer','Visual J++');",13,10
            db  "ANALYZE;",13,10    ; creates sqlite_stat1
SQLCommit   db  "COMMIT TRANSACTION;",0
.code
    ; use CTXT to store chars in .data section (sloppy but compatible), or 
    ; use CADD to store chars in .code section (may confuse debugger.)
    inkey CTXT(13,10," Press a key to open/create database.")
    invoke sqlite3_open,addr DBFile,addr DBase      ; will not open quoted LFN's
    call DispErr
    invoke sqlite3_exec,DBase,addr SQLCreateDB,0,0,0
    invoke sqlite3_exec,DBase,addr SQLCommit,0,0,addr errMsg    ; needed
    print chr$(" ...Done.",13,10)   ; do not display any possible errors
; ----------------------------------------------------------------------------
    inkey CTXT(13,10," Press a key to query SQLite_Master.")
    invoke sqlite3_exec,DBase,CTXT("SELECT * FROM sqlite_master WHERE TYPE='table';"),\
        addr CallbackProc,0,addr errMsg     ; callback is executed once per row
    call DispErr
; ----------------------------------------------------------------------------
    inkey CTXT(13,10," Press a key to show Table1 contents.")
    invoke sqlite3_exec,DBase,CTXT("SELECT * FROM Table1 WHERE ID==0;"),\
        addr CallbackProcColumnNames,0,addr errMsg  ; show column names
    call DispErr
    invoke sqlite3_exec,DBase,CTXT("SELECT * FROM Table1;"),\
        addr CallbackProc,0,addr errMsg             ; show all of Table1
    call DispErr
; ----------------------------------------------------------------------------
    inkey CTXT(13,10," Press a key to sort Table1 by Dislikes (descending).")
    invoke sqlite3_exec,DBase,CTXT("SELECT * FROM Table1 ORDER BY Dislikes DESC;"),\
        addr CallbackProc,0,addr errMsg
    call DispErr
; ----------------------------------------------------------------------------
    inkey CTXT(13,10," Press a key to show only Table1 Handles.")
    invoke sqlite3_exec,DBase,CTXT("SELECT Handle FROM Table1 ORDER BY ID;"),\
        addr CallbackProc,0,addr errMsg
    call DispErr
; ----------------------------------------------------------------------------
    inkey CTXT(13,10," Press a key to show only Table1 Handles containing '2'.")
    invoke sqlite3_exec,DBase,CTXT("SELECT Handle FROM Table1 WHERE Handle LIKE '%2%';"),\
        addr CallbackProc,0,addr errMsg
    call DispErr
; ----------------------------------------------------------------------------
    inkey CTXT(13,10," Press a key to write a new entry into Table1.")
.data
SQLInsert   db  "INSERT INTO Table1 VALUES(4,'Sammy Hagu','FuManchu69',"
            db  "'Kalifournia','Turmonater!');",0
.code
    invoke sqlite3_exec,DBase,addr SQLInsert,0,0,addr errMsg ; callback uneeded
    call DispErr
    invoke sqlite3_exec,DBase,CTXT("SELECT * FROM Table1 where ID==4;"),\
        addr CallbackProc,0,addr errMsg
    call DispErr
; ----------------------------------------------------------------------------
    inkey CTXT(13,10," Press a key to update a value in Table1.")
    invoke sqlite3_exec,DBase,CTXT("UPDATE Table1 SET Name=='Jimmi Dale' WHERE ID==4;"),\
        0,0,addr errMsg
    call DispErr
    invoke sqlite3_exec,DBase,CTXT("SELECT * FROM Table1 where ID==4;"),\
        addr CallbackProc,0,addr errMsg
    call DispErr
; ----------------------------------------------------------------------------
    inkey CTXT(13,10," Press a key to delete that entry from Table1.")
    invoke sqlite3_exec,DBase,CTXT("DELETE FROM Table1 WHERE ID==4;"),\
        0,0,addr errMsg
    .if eax==0
        print chr$(" ...Done.",13,10)
    .else
        call DispErr
    .endif
; ----------------------------------------------------------------------------
    inkey CTXT(13,10," Press a key to create a Table2.")
.data
SQLTable2   db  "CREATE TABLE Table2 ("
            db  "LastName varchar,"
            db  "FirstName varchar,"
            db  "Age int,"
            db  "Address );",0
SQLInsert2  db  "INSERT INTO Table2 VALUES('Colombus','Christopher',"
            db  "35,'123 Anystreet');",0
.code
    invoke sqlite3_exec,DBase,addr SQLTable2,0,0,addr errMsg
    call DispErr
    invoke sqlite3_exec,DBase,addr SQLInsert2,0,0,addr errMsg
    call DispErr
    invoke sqlite3_exec,DBase,CTXT("SELECT * FROM Table2;"),\
        addr CallbackProcColumnNames,0,addr errMsg  ; show columns
    call DispErr
    invoke sqlite3_exec,DBase,CTXT("SELECT * FROM Table2;"),\
        addr CallbackProc,0,addr errMsg             ; show contents
    call DispErr
; ----------------------------------------------------------------------------
    inkey CTXT(13,10," Press a key to add a 'City' column to Table2.")
    invoke sqlite3_exec,DBase,CTXT("ALTER TABLE Table2 ADD City varchar;"),\
        0,0,addr errMsg
    call DispErr
    invoke sqlite3_exec,DBase,CTXT("UPDATE Table2 SET City=='Anytown' WHERE LastName=='Colombus';"),\
        0,0,addr errMsg
    call DispErr
    invoke sqlite3_exec,DBase,CTXT("SELECT * FROM Table2;"),\
        addr CallbackProcColumnNames,0,addr errMsg
    call DispErr
    invoke sqlite3_exec,DBase,CTXT("SELECT * FROM Table2;"),\
        addr CallbackProc,0,addr errMsg
    call DispErr
; ----------------------------------------------------------------------------
    inkey CTXT(13,10," Press a key to drop the 'City' column from Table2.")
.data       ; SQLite3 provides no simple method for dropping columns.
SQLDropCol  db  "BEGIN TRANSACTION;"
            db  "CREATE TEMPORARY TABLE t2_backup(LastName,FirstName,Age,Address);"
            db  "INSERT INTO t2_backup SELECT LastName,FirstName,Age,Address FROM Table2;"
            db  "DROP TABLE Table2;"
            db  "CREATE TABLE Table2(LastName,FirstName,Age int,Address);"
            db  "INSERT INTO Table2 SELECT LastName,FirstName,Age,Address FROM T2_backup;"
            db  "DROP TABLE t2_backup;"
            db  "COMMIT;",0
.code
    invoke sqlite3_exec,DBase,addr SQLDropCol,0,0,addr errMsg
    call DispErr
    invoke sqlite3_exec,DBase,CTXT("SELECT * FROM Table2;"),\
        addr CallbackProcColumnNames,0,addr errMsg
    call DispErr
    invoke sqlite3_exec,DBase,CTXT("SELECT * FROM Table2;"),\
        addr CallbackProc,0,addr errMsg
    call DispErr
; ----------------------------------------------------------------------------
    inkey CTXT(13,10," Press a key to create an index to Table2 names.")
.data
SQLIndex    db  "CREATE INDEX PersonIndex ON Table2 (LastName,FirstName);",0
.code
    invoke sqlite3_exec,DBase,addr SQLIndex,0,0,addr errMsg
    call DispErr
    .if eax==0
        print chr$(" ...Done.",13,10)
    .else
        call DispErr
    .endif
; ----------------------------------------------------------------------------
    inkey CTXT(13,10," Press a key to drop index to Table2 names.")
    invoke sqlite3_exec,DBase,CTXT("DROP INDEX PersonIndex;"),0,0,addr errMsg
    call DispErr
    .if eax==0
        print chr$(" ...Done.",13,10)
    .else
        call DispErr
    .endif
; ----------------------------------------------------------------------------
    inkey CTXT(13,10," Press a key to drop Table2.")
    invoke sqlite3_exec,DBase,CTXT("DROP TABLE Table2;"),0,0,addr errMsg
    call DispErr
    .if eax==0
        print chr$(" ...Done.",13,10)
    .else
        call DispErr
    .endif
; ----------------------------------------------------------------------------
    inkey CTXT(13,10," Press a key to defragment db (file will deflate by ~2kb.)")
    invoke sqlite3_exec,DBase,CTXT("VACUUM Table1;"),0,0,addr errMsg
    .if eax==0
        print chr$(" ...Done.",13,10)
    .else
        call DispErr
    .endif
; ----------------------------------------------------------------------------
    inkey CTXT(13,10," Press any key to close database.")
    invoke sqlite3_close,DBase
    .if eax==0
        print chr$(" ...Done.",13,10)
    .else
        call DispErr
    .endif
; ----------------------------------------------------------------------------
    inkey CTXT(13,10," Press any key to exit...")
    invoke ExitProcess,0                            ; exit gracefully



OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE
CallbackProc proc not_used:DWORD,argc:DWORD,argv:DWORD,azColName:DWORD
; this is called once per row by sqlite3_exec, see sqlite3.h
    push ebp                                        ; create manual stack frame
    mov ebp,esp
    push edi                                        ; must preserve edi and esi
    xor edi,edi
    push esi

@@: mov esi,argv            ; argv is a char** (pointer to an array of pointers)
    mov esi,[esi+edi*4]     ; de-reference one of these to a char* pointer
    print esi               ; display that member
    inc edi                 ; point to next column (edi*4 = offset in DWORDs)
    
    cmp edi,argc            ; while arg count != edi
    je @F                   ; if argc==edi, end the line with CR+LF
    print chr$(", ")        ; else comma-separate values
    jmp @B                  ; and loop
    
@@: print chr$(13,10)       ; terminate with CR+LF
    pop esi
    pop edi
    pop ebp
    xor eax,eax                                     ; return 0 (success)
    ret
CallbackProc endp
OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef


OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE
CallbackProcColumnNames proc not_used:DWORD,argc:DWORD,argv:DWORD,azColName:DWORD
    push ebp
    mov ebp,esp
    push edi
    xor edi,edi
    push esi

@@: mov esi,azColName
    mov esi,[esi+edi*4]
    print esi
    inc edi
    
    cmp edi,argc
    jge @F
    print chr$(", ")
    jmp @B
    
@@: print chr$(13,10)
    pop esi
    pop edi
    pop ebp
    xor eax,eax
    ret
CallbackProcColumnNames endp
OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef


DispErr:
.data
    szSQLerr    db  " ...SQLite: %s.",13,10,0
.code
    .if eax==0                                      ; return on no error
        ret
    .elseif eax==SQLITE_ERROR                       ; all syntax errors
        invoke printit,errMsg
    .elseif eax==SQLITE_INTERNAL                    ; specific errors
        invoke printit,CTXT("internal error")
    .elseif eax==SQLITE_PERM
        invoke printit,CTXT("access permission denied")
    .elseif eax==SQLITE_ABORT
        invoke printit,CTXT("callback routine requested an abort")
    .elseif eax==SQLITE_BUSY
        invoke printit,CTXT("database file locked")
    .elseif eax==SQLITE_LOCKED
        invoke printit,CTXT("database table locked")
    .elseif eax==SQLITE_NOMEM
        invoke printit,CTXT("malloc() failed")
    .elseif eax==SQLITE_READONLY
        invoke printit,CTXT("database is read-only")
    .elseif eax==SQLITE_INTERRUPT
        invoke printit,CTXT("operation terminated by sqlite3_interrupt()")
    .elseif eax==SQLITE_IOERR
        invoke printit,CTXT("disk I/O error")       ; generalized
    .elseif eax==SQLITE_CORRUPT
        invoke printit,CTXT("the database disk image is malformed")
    .elseif eax==SQLITE_NOTFOUND
        invoke printit,CTXT("table or record not found")
    .elseif eax==SQLITE_FULL
        invoke printit,CTXT("insertion failed because database is full")
    .elseif eax==SQLITE_CANTOPEN
        invoke printit,CTXT("unable to open the database file")
    .elseif eax==SQLITE_PROTOCOL
        invoke printit,CTXT("database lock protocol error")
    .elseif eax==SQLITE_EMPTY
        invoke printit,CTXT("database is empty")
    .elseif eax==SQLITE_SCHEMA
        invoke printit,CTXT("the database schema changed")
    .elseif eax==SQLITE_TOOBIG
        invoke printit,CTXT("string or BLOB exceeds size limit")
    .elseif eax==SQLITE_CONSTRAINT
        invoke printit,CTXT("abort due to constraint violation")
    .elseif eax==SQLITE_MISMATCH
        invoke printit,CTXT("data type mismatch")
    .elseif eax==SQLITE_MISUSE
        invoke printit,CTXT("library used incorrectly")
    .elseif eax==SQLITE_NOLFS
        invoke printit,CTXT("uses OS features not supported on host")
    .elseif eax==SQLITE_AUTH
        invoke printit,CTXT("authorization denied")
    .elseif eax==SQLITE_FORMAT
        invoke printit,CTXT("auxiliary database format error")
    .elseif eax==SQLITE_RANGE
        invoke printit,CTXT("2nd parameter to sqlite3_bind out of range")
    .elseif eax==SQLITE_NOTADB
        invoke printit,CTXT("file opened is not a database file")
    .elseif eax==SQLITE_ROW
        invoke printit,CTXT("sqlite3_step() has another row ready")
    .elseif eax==SQLITE_DONE
        invoke printit,CTXT("sqlite3_step() has finished executing")
    .endif
    ret


printit proc msg:dword
    invoke wsprintf,addr DBFile,addr szSQLerr,msg
    print addr DBFile
    ret
printit endp


end main
