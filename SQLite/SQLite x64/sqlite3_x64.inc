; /*
; ** 2001-09-15
; **
; ** The author disclaims copyright to this source code.  In place of
; ** a legal notice, here is a blessing:
; **
; **    May you do good and not evil.
; **    May you find forgiveness for yourself and forgive others.
; **    May you share freely, never taking more than you give.
; **
; *************************************************************************

; sqlite_x64.inc converted from sqlite.h source for assembler by fearless 2024
; www.github.com/mrfearless

sqlite3_aggregate_context       PROTO sqlite3_context:QWORD,nBytes:QWORD
sqlite3_aggregate_count         PROTO sqlite3_context:QWORD
sqlite3_auto_extension          PROTO :QWORD
sqlite3_autovacuum_pages        PROTO database:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_backup_finish           PROTO p:QWORD
sqlite3_backup_init             PROTO pDest:QWORD,zDestName:QWORD,pSource:QWORD,zSourceName:QWORD
sqlite3_backup_pagecount        PROTO p:QWORD
sqlite3_backup_remaining        PROTO p:QWORD
sqlite3_backup_step             PROTO p:QWORD,nPage:QWORD
sqlite3_bind_blob64             PROTO sqlite3_stmt:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_bind_blob               PROTO sqlite3_stmt:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_bind_double             PROTO sqlite3_stmt:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_bind_int64              PROTO sqlite3_stmt:QWORD,:QWORD,:QWORD
sqlite3_bind_int                PROTO sqlite3_stmt:QWORD,:QWORD,:QWORD
sqlite3_bind_null               PROTO sqlite3_stmt:QWORD,:QWORD
sqlite3_bind_parameter_count    PROTO sqlite3_stmt:QWORD
sqlite3_bind_parameter_index    PROTO sqlite3_stmt:QWORD,zName:QWORD
sqlite3_bind_parameter_name     PROTO sqlite3_stmt:QWORD,:QWORD
sqlite3_bind_pointer            PROTO sqlite3_stmt:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_bind_text16             PROTO sqlite3_stmt:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_bind_text64             PROTO sqlite3_stmt:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_bind_text               PROTO sqlite3_stmt:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_bind_value              PROTO sqlite3_stmt:QWORD,:QWORD,:QWORD
sqlite3_bind_zeroblob64         PROTO sqlite3_stmt:QWORD,:QWORD,:QWORD
sqlite3_bind_zeroblob           PROTO sqlite3_stmt:QWORD,:QWORD,:QWORD
sqlite3_blob_bytes              PROTO sqlite3_blob:QWORD
sqlite3_blob_close              PROTO sqlite3_blob:QWORD
sqlite3_blob_open               PROTO sqlite3:QWORD,zDb:QWORD,zTable:QWORD,zColumn:QWORD,iRow:QWORD,flags_:QWORD,ppBlob:QWORD
sqlite3_blob_read               PROTO sqlite3_blob:QWORD,Z:QWORD,N:QWORD,iOffset:QWORD
sqlite3_blob_reopen             PROTO sqlite3_blob:QWORD,:QWORD
sqlite3_blob_write              PROTO sqlite3_blob:QWORD,z:QWORD,n:QWORD,iOffset:QWORD
sqlite3_busy_handler            PROTO sqlite3:QWORD,callback:QWORD,callbackArg:QWORD
sqlite3_busy_timeout            PROTO sqlite3:QWORD,ms:QWORD
sqlite3_cancel_auto_extension   PROTO :QWORD
sqlite3_changes64               PROTO sqlite3:QWORD
sqlite3_changes                 PROTO sqlite3:QWORD
sqlite3_clear_bindings          PROTO sqlite3_stmt:QWORD
sqlite3_close                   PROTO sqlite3:QWORD
sqlite3_close_v2                PROTO sqlite3:QWORD
sqlite3_collation_needed16      PROTO sqlite3:QWORD,eTextRep:QWORD,:QWORD
sqlite3_collation_needed        PROTO sqlite3:QWORD,eTextRep:QWORD,:QWORD
sqlite3_column_blob             PROTO sqlite3_stmt:QWORD,iCol:QWORD
sqlite3_column_bytes16          PROTO sqlite3_stmt:QWORD,iCol:QWORD
sqlite3_column_bytes            PROTO sqlite3_stmt:QWORD,iCol:QWORD
sqlite3_column_count            PROTO pStmt:QWORD
sqlite3_column_database_name16  PROTO sqlite3_stmt:QWORD,:QWORD
sqlite3_column_database_name    PROTO sqlite3_stmt:QWORD,:QWORD
sqlite3_column_decltype16       PROTO sqlite3_stmt:QWORD,iCol:QWORD
sqlite3_column_decltype         PROTO sqlite3_stmt:QWORD,iCol:QWORD
sqlite3_column_double           PROTO sqlite3_stmt:QWORD,iCol:QWORD
sqlite3_column_int64            PROTO sqlite3_stmt:QWORD,iCol:QWORD
sqlite3_column_int              PROTO sqlite3_stmt:QWORD,iCol:QWORD
sqlite3_column_name16           PROTO sqlite3_stmt:QWORD,iCol:QWORD
sqlite3_column_name             PROTO sqlite3_stmt:QWORD,iCol:QWORD
sqlite3_column_origin_name16    PROTO sqlite3_stmt:QWORD,:QWORD
sqlite3_column_origin_name      PROTO sqlite3_stmt:QWORD,:QWORD
sqlite3_column_table_name16     PROTO sqlite3_stmt:QWORD,:QWORD
sqlite3_column_table_name       PROTO sqlite3_stmt:QWORD,:QWORD
sqlite3_column_text16           PROTO sqlite3_stmt:QWORD,iCol:QWORD
sqlite3_column_text             PROTO sqlite3_stmt:QWORD,iCol:QWORD
sqlite3_column_type             PROTO sqlite3_stmt:QWORD,iCol:QWORD
sqlite3_column_value            PROTO sqlite3_stmt:QWORD,iCol:QWORD
sqlite3_commit_hook             PROTO sqlite3:QWORD,:QWORD,:QWORD
sqlite3_compileoption_get       PROTO N:QWORD
sqlite3_compileoption_used      PROTO zOptName:QWORD
sqlite3_complete16              PROTO sql:QWORD
sqlite3_complete                PROTO sql:QWORD
sqlite3_config                  PROTO C :VARARG
sqlite3_context_db_handle       PROTO sqlite3_context:QWORD
sqlite3_create_collation16      PROTO sqlite3:QWORD,zName:QWORD,eTextRep:QWORD,pArg:QWORD,xCompare:QWORD
sqlite3_create_collation        PROTO sqlite3:QWORD,zName:QWORD,eTextRep:QWORD,pArg:QWORD,xCompare:QWORD
sqlite3_create_collation_v2     PROTO sqlite3:QWORD,zName:QWORD,eTextRep:QWORD,pArg:QWORD,xCompare:QWORD,xDestroy:QWORD
sqlite3_create_filename         PROTO zDatabase:QWORD,zJournal:QWORD,zWal:QWORD,nParam:QWORD,azParam:QWORD
sqlite3_create_function16       PROTO database:QWORD,zFunctionName:QWORD,nArg:QWORD,eTextRep:QWORD,pApp:QWORD,xFunc:QWORD,xStep:QWORD,xFinal:QWORD
sqlite3_create_function         PROTO database:QWORD,zFunctionName:QWORD,nArg:QWORD,eTextRep:QWORD,pApp:QWORD,xFunc:QWORD,xStep:QWORD,xFinal:QWORD
sqlite3_create_function_v2      PROTO database:QWORD,zFunctionName:QWORD,nArg:QWORD,eTextRep:QWORD,pApp:QWORD,xFunc:QWORD,xStep:QWORD,xFinal:QWORD,xDestroy:QWORD
sqlite3_create_module           PROTO sqlite3:QWORD,zName:QWORD,p:QWORD,pClientData:QWORD
sqlite3_create_module_v2        PROTO sqlite3:QWORD,zName:QWORD,p:QWORD,pClientData:QWORD,xDestroy:QWORD
sqlite3_create_window_function  PROTO database:QWORD,zFunctionName:QWORD,nArg:QWORD,eTextRep:QWORD,pApp:QWORD,xStep:QWORD,xFinal:QWORD,xValue:QWORD,xInverse:QWORD,xDestroy:QWORD
sqlite3_data_count              PROTO pStmt:QWORD
sqlite3_data_directory          PROTO C :VARARG
sqlite3_database_file_object    PROTO :QWORD
sqlite3_db_cacheflush           PROTO sqlite3:QWORD
sqlite3_db_config               PROTO C :VARARG
sqlite3_db_filename             PROTO sqlite3_stmt:QWORD,zDbName:QWORD
sqlite3_db_handle               PROTO sqlite3_stmt:QWORD
sqlite3_db_mutex                PROTO sqlite3:QWORD
sqlite3_db_name                 PROTO database:QWORD,N:QWORD
sqlite3_db_readonly             PROTO database:QWORD,zDbName:QWORD
sqlite3_db_release_memory       PROTO sqlite3:QWORD
sqlite3_db_status               PROTO sqlite3:QWORD,op:QWORD,pCur:QWORD,pHiwtr:QWORD,resetFlg:QWORD
sqlite3_declare_vtab            PROTO sqlite3:QWORD,zSQL:QWORD
sqlite3_deserialize             PROTO sqlite3:QWORD,zSchema:QWORD,pData:QWORD,szDb:QWORD,szBuf:QWORD,mFlags:QWORD
sqlite3_drop_modules            PROTO sqlite3:QWORD,azKeep:QWORD
sqlite3_enable_load_extension   PROTO database:QWORD,onoff:QWORD
sqlite3_enable_shared_cache     PROTO :QWORD
sqlite3_errcode                 PROTO database:QWORD
sqlite3_errmsg16                PROTO sqlite3:QWORD
sqlite3_errmsg                  PROTO sqlite3:QWORD
sqlite3_error_offset            PROTO database:QWORD
sqlite3_errstr                  PROTO sqlite3:QWORD
sqlite3_exec                    PROTO sqlite3:QWORD,sql:QWORD,callback:QWORD,callbackArg:QWORD,errmsg:QWORD
sqlite3_expanded_sql            PROTO pStmt:QWORD
sqlite3_expired                 PROTO sqlite3_stmt:QWORD
sqlite3_extended_errcode        PROTO database:QWORD
sqlite3_extended_result_codes   PROTO sqlite3:QWORD,onoff:QWORD
sqlite3_file_control            PROTO sqlite3:QWORD,zDbName:QWORD,op:QWORD,:QWORD
sqlite3_filename_database       PROTO sqlite3_filename:QWORD
sqlite3_filename_journal        PROTO sqlite3_filename:QWORD
sqlite3_filename_wal            PROTO sqlite3_filename:QWORD
sqlite3_finalize                PROTO pStmt:QWORD
sqlite3_free                    PROTO pmem:QWORD
sqlite3_free_filename           PROTO sqlite3_filename:QWORD
sqlite3_free_table              PROTO result:QWORD
sqlite3_get_autocommit          PROTO sqlite3:QWORD
sqlite3_get_auxdata             PROTO sqlite3_context:QWORD,N:QWORD
sqlite3_get_clientdata          PROTO sqlite3:QWORD,:QWORD
sqlite3_get_table               PROTO database:QWORD,zSql:QWORD,pazResult:QWORD,pnRow:QWORD,pnColumn:QWORD,pzErrmsg:QWORD
sqlite3_global_recover          PROTO 
sqlite3_hard_heap_limit64       PROTO N:QWORD
sqlite3_initialize              PROTO 
sqlite3_interrupt               PROTO sqlite3:QWORD
sqlite3_is_interrupted          PROTO sqlite3:QWORD
sqlite3_keyword_check           PROTO :QWORD,:QWORD
sqlite3_keyword_count           PROTO 
sqlite3_keyword_name            PROTO :QWORD,:QWORD,:QWORD
sqlite3_last_insert_rowid       PROTO sqlite3:QWORD
sqlite3_libversion              PROTO 
sqlite3_libversion_number       PROTO 
sqlite3_limit                   PROTO sqlite3:QWORD,id:QWORD,newVal:QWORD
sqlite3_load_extension          PROTO sqlite3:QWORD,zFile:QWORD,zProc:QWORD,pzErrMsg:QWORD
sqlite3_log                     PROTO C :VARARG
sqlite3_malloc64                PROTO memsize:QWORD
sqlite3_malloc                  PROTO memsize:QWORD
sqlite3_memory_alarm            PROTO :QWORD,:QWORD,:QWORD
sqlite3_memory_highwater        PROTO resetFlag:QWORD
sqlite3_memory_used             PROTO 
sqlite3_mprintf                 PROTO C :VARARG
sqlite3_msize                   PROTO pmem:QWORD
sqlite3_mutex_alloc             PROTO :QWORD
sqlite3_mutex_enter             PROTO sqlite3_mutex:QWORD
sqlite3_mutex_free              PROTO sqlite3_mutex:QWORD
sqlite3_mutex_leave             PROTO sqlite3_mutex:QWORD
sqlite3_mutex_try               PROTO sqlite3_mutex:QWORD
sqlite3_next_stmt               PROTO pDb:QWORD,pStmt:QWORD
sqlite3_open16                  PROTO filename:QWORD,ppDb:QWORD
sqlite3_open                    PROTO filename:QWORD,ppDb:QWORD
sqlite3_open_v2                 PROTO filename:QWORD,ppDb:QWORD,flags_:QWORD,zVfs:QWORD
sqlite3_os_end                  PROTO 
sqlite3_os_init                 PROTO 
sqlite3_overload_function       PROTO sqlite3:QWORD,zFuncName:QWORD,nArg:QWORD
sqlite3_prepare16               PROTO database:QWORD,zSql:QWORD,nByte:QWORD,ppStmt:QWORD,pzTail:QWORD
sqlite3_prepare16_v2            PROTO database:QWORD,zSql:QWORD,nByte:QWORD,ppStmt:QWORD,pzTail:QWORD
sqlite3_prepare16_v3            PROTO database:QWORD,zSql:QWORD,nByte:QWORD,prepFlags:QWORD,ppStmt:QWORD,pzTail:QWORD
sqlite3_prepare                 PROTO database:QWORD,zSql:QWORD,nByte:QWORD,ppStmt:QWORD,pzTail:QWORD
sqlite3_prepare_v2              PROTO database:QWORD,zSql:QWORD,nByte:QWORD,ppStmt:QWORD,pzTail:QWORD
sqlite3_prepare_v3              PROTO database:QWORD,zSql:QWORD,nByte:QWORD,prepFlags:QWORD,ppStmt:QWORD,pzTail:QWORD
sqlite3_profile                 PROTO sqlite3:QWORD,xProfile:QWORD,:QWORD
sqlite3_progress_handler        PROTO sqlite3:QWORD,N:QWORD,callback:QWORD,callbackArg:QWORD
sqlite3_randomness              PROTO N:QWORD,P:QWORD
sqlite3_realloc64               PROTO pmem:QWORD,memsize:QWORD
sqlite3_realloc                 PROTO pmem:QWORD,memsize:QWORD
sqlite3_release_memory          PROTO :QWORD
sqlite3_reset                   PROTO pStmt:QWORD
sqlite3_reset_auto_extension    PROTO 
sqlite3_result_blob64           PROTO sqlite3_context:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_result_blob             PROTO sqlite3_context:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_result_double           PROTO sqlite3_context:QWORD,:QWORD,:QWORD
sqlite3_result_error16          PROTO sqlite3_context:QWORD,:QWORD,:QWORD
sqlite3_result_error            PROTO sqlite3_context:QWORD,:QWORD,:QWORD
sqlite3_result_error_code       PROTO sqlite3_context:QWORD,:QWORD
sqlite3_result_error_nomem      PROTO sqlite3_context:QWORD
sqlite3_result_error_toobig     PROTO sqlite3_context:QWORD
sqlite3_result_int64            PROTO sqlite3_context:QWORD,:QWORD
sqlite3_result_int              PROTO sqlite3_context:QWORD,:QWORD
sqlite3_result_null             PROTO sqlite3_context:QWORD
sqlite3_result_pointer          PROTO sqlite3_context:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_result_subtype          PROTO sqlite3_context:QWORD,:QWORD
sqlite3_result_text16           PROTO sqlite3_context:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_result_text16be         PROTO sqlite3_context:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_result_text16le         PROTO sqlite3_context:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_result_text64           PROTO sqlite3_context:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,encoding:QWORD
sqlite3_result_text             PROTO sqlite3_context:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_result_value            PROTO sqlite3_context:QWORD,sqlite3_value:QWORD
sqlite3_result_zeroblob64       PROTO sqlite3_context:QWORD,n:QWORD
sqlite3_result_zeroblob         PROTO sqlite3_context:QWORD,:QWORD
sqlite3_rollback_hook           PROTO sqlite3:QWORD,:QWORD,:QWORD
sqlite3_serialize               PROTO sqlite3:QWORD,zSchema:QWORD,piSize:QWORD,mFlags:QWORD
sqlite3_set_authorizer          PROTO sqlite3:QWORD,xAuth:QWORD,pUserData:QWORD
sqlite3_set_auxdata             PROTO sqlite3_context:QWORD,N:QWORD,:QWORD,:QWORD
sqlite3_set_clientdata          PROTO sqlite3:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_set_last_insert_rowid   PROTO sqlite3:QWORD,rowid:QWORD
sqlite3_shutdown                PROTO 
sqlite3_sleep                   PROTO :QWORD
sqlite3_snprintf                PROTO C :VARARG
sqlite3_soft_heap_limit64       PROTO N:QWORD
sqlite3_soft_heap_limit         PROTO N:QWORD
sqlite3_sourceid                PROTO 
sqlite3_sql                     PROTO pStmt:QWORD
sqlite3_status64                PROTO op:QWORD,pCurrent:QWORD,pHighwater:QWORD,resetFlag:QWORD
sqlite3_status                  PROTO op:QWORD,pCurrent:QWORD,pHighwater:QWORD,resetFlag:QWORD
sqlite3_step                    PROTO :QWORD
sqlite3_stmt_busy               PROTO pStmt:QWORD
sqlite3_stmt_explain            PROTO pStmt:QWORD,eMode:QWORD
sqlite3_stmt_isexplain          PROTO pStmt:QWORD
sqlite3_stmt_readonly           PROTO pStmt:QWORD
sqlite3_stmt_status             PROTO sqlite3_stmt:QWORD,op:QWORD,resetFlg:QWORD
sqlite3_str_append              PROTO sqlite3_str:QWORD,zIn:QWORD,N:QWORD
sqlite3_str_appendall           PROTO sqlite3_str:QWORD,zIn:QWORD
sqlite3_str_appendchar          PROTO sqlite3_str:QWORD,N:QWORD,char:QWORD
sqlite3_str_appendf             PROTO C :VARARG
sqlite3_str_errcode             PROTO sqlite3_str:QWORD
sqlite3_str_finish              PROTO sqlite3_str:QWORD
sqlite3_str_length              PROTO sqlite3_str:QWORD
sqlite3_str_new                 PROTO sqlite3:QWORD
sqlite3_str_reset               PROTO sqlite3_str:QWORD
sqlite3_str_value               PROTO sqlite3_str:QWORD
sqlite3_str_vappendf            PROTO :QWORD,:QWORD,:QWORD
sqlite3_strglob                 PROTO zGlob:QWORD,zStr:QWORD
sqlite3_stricmp                 PROTO :QWORD,:QWORD
sqlite3_strlike                 PROTO zGlob:QWORD,zStr:QWORD,cEsc:QWORD
sqlite3_strnicmp                PROTO :QWORD,:QWORD,:QWORD
sqlite3_system_errno            PROTO sqlite3:QWORD
sqlite3_table_column_metadata   PROTO sqlite3:QWORD,zDbName:QWORD,zTableName:QWORD,zColumnName:QWORD,pzDataType:QWORD,pzCollSeq:QWORD,pNotNull:QWORD,pPrimaryKey:QWORD,pAutoinc:QWORD
sqlite3_temp_directory          PROTO C :VARARG
sqlite3_test_control            PROTO C :VARARG
sqlite3_thread_cleanup          PROTO 
sqlite3_threadsafe              PROTO 
sqlite3_total_changes64         PROTO sqlite3:QWORD
sqlite3_total_changes           PROTO sqlite3:QWORD
sqlite3_trace                   PROTO sqlite3:QWORD,xTrace:QWORD,:QWORD
sqlite3_trace_v2                PROTO sqlite3:QWORD,uMask:QWORD,xCallback:QWORD,pCtx:QWORD
sqlite3_transfer_bindings       PROTO sqlite3_stmt:QWORD,sqlite3_stmt:QWORD
sqlite3_txn_state               PROTO sqlite3:QWORD,zSchema:QWORD
sqlite3_update_hook             PROTO sqlite3:QWORD,:QWORD,:QWORD
sqlite3_uri_boolean             PROTO z:QWORD,zParam:QWORD,bDefault:QWORD
sqlite3_uri_int64               PROTO z:QWORD,zParam:QWORD,:QWORD
sqlite3_uri_key                 PROTO z:QWORD,N:QWORD
sqlite3_uri_parameter           PROTO z:QWORD,zParam:QWORD
sqlite3_user_data               PROTO sqlite3_context:QWORD
sqlite3_value_blob              PROTO sqlite3_value:QWORD
sqlite3_value_bytes16           PROTO sqlite3_value:QWORD
sqlite3_value_bytes             PROTO sqlite3_value:QWORD
sqlite3_value_double            PROTO sqlite3_value:QWORD
sqlite3_value_dup               PROTO sqlite3_value:QWORD
sqlite3_value_encoding          PROTO sqlite3_value:QWORD
sqlite3_value_free              PROTO sqlite3_value:QWORD
sqlite3_value_frombind          PROTO sqlite3_value:QWORD
sqlite3_value_int64             PROTO sqlite3_value:QWORD
sqlite3_value_int               PROTO sqlite3_value:QWORD
sqlite3_value_nochange          PROTO sqlite3_value:QWORD
sqlite3_value_numeric_type      PROTO sqlite3_value:QWORD
sqlite3_value_pointer           PROTO sqlite3_value:QWORD,:QWORD
sqlite3_value_subtype           PROTO sqlite3_value:QWORD
sqlite3_value_text16            PROTO sqlite3_value:QWORD
sqlite3_value_text16be          PROTO sqlite3_value:QWORD
sqlite3_value_text16le          PROTO sqlite3_value:QWORD
sqlite3_value_text              PROTO sqlite3_value:QWORD
sqlite3_value_type              PROTO sqlite3_value:QWORD
sqlite3_version                 PROTO C :VARARG
sqlite3_vfs_find                PROTO zVfsName:QWORD
sqlite3_vfs_register            PROTO sqlite3_vfs:QWORD,makeDflt:QWORD
sqlite3_vfs_unregister          PROTO sqlite3_vfs:QWORD
sqlite3_vmprintf                PROTO :QWORD,:QWORD
sqlite3_vsnprintf               PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_vtab_collation          PROTO sqlite3_index_info:QWORD,:QWORD
sqlite3_vtab_config             PROTO C :VARARG
sqlite3_vtab_distinct           PROTO sqlite3_index_info:QWORD
sqlite3_vtab_in                 PROTO sqlite3_index_info:QWORD,iCons:QWORD,bHandle:QWORD
sqlite3_vtab_in_first           PROTO pVal:QWORD,ppOut:QWORD
sqlite3_vtab_in_next            PROTO pVal:QWORD,ppOut:QWORD
sqlite3_vtab_nochange           PROTO sqlite3_context:QWORD
sqlite3_vtab_on_conflict        PROTO sqlite3:QWORD
sqlite3_vtab_rhs_value          PROTO sqlite3_index_info:QWORD,:QWORD,ppVal:QWORD
sqlite3_wal_autocheckpoint      PROTO sqlite3:QWORD,N:QWORD
sqlite3_wal_checkpoint          PROTO sqlite3:QWORD,N:QWORD
sqlite3_wal_checkpoint_v2       PROTO sqlite3:QWORD,zDb:QWORD,eMode:QWORD,pnLog:QWORD,pnCkpt:QWORD
sqlite3_wal_hook                PROTO sqlite3:QWORD,:QWORD,:QWORD
sqlite3_win32_is_nt             PROTO 
sqlite3_win32_mbcs_to_utf8      PROTO :QWORD
sqlite3_win32_mbcs_to_utf8_v2   PROTO :QWORD,:QWORD
sqlite3_win32_set_directory16   PROTO type:QWORD,zValue:QWORD
sqlite3_win32_set_directory8    PROTO type:QWORD,zValue:QWORD
sqlite3_win32_set_directory     PROTO type:QWORD,zValue:QWORD
sqlite3_win32_sleep             PROTO :QWORD
sqlite3_win32_unicode_to_utf8   PROTO :QWORD
sqlite3_win32_utf8_to_mbcs      PROTO :QWORD
sqlite3_win32_utf8_to_mbcs_v2   PROTO :QWORD,:QWORD
sqlite3_win32_utf8_to_unicode   PROTO :QWORD
sqlite3_win32_write_debug       PROTO :QWORD,:QWORD

IFNDEF POINTER
POINTER TYPEDEF QWORD
ENDIF

sqlite3_file                STRUCT 8 ; 8 bytes
    pMethods                POINTER ?
sqlite3_file                ENDS

sqlite3_io_methods          STRUCT 8 ; 152 bytes
    iVersion                DWORD ?
    xClose                  POINTER ? ; (*xClose)(sqlite3_file*);
    xRead                   POINTER ? ; (sqlite3_file*, void*, int iAmt, sqlite3_int64 iOfst);
    xWrite                  POINTER ? ; (sqlite3_file*, const void*, int iAmt, sqlite3_int64 iOfst);
    xTruncate               POINTER ? ; (sqlite3_file*, sqlite3_int64 size);
    xSync                   POINTER ? ; (sqlite3_file*, int flags);
    xFileSize               POINTER ? ; (sqlite3_file*, sqlite3_int64 *pSize);
    xLock                   POINTER ? ; (sqlite3_file*, int);
    xUnlock                 POINTER ? ; (sqlite3_file*, int);
    xCheckReservedLock      POINTER ? ; (sqlite3_file*, int *pResOut);
    xFileControl            POINTER ? ; (sqlite3_file*, int op, void *pArg);
    xSectorSize             POINTER ? ; (sqlite3_file*);
    xDeviceCharacteristics  POINTER ? ; (sqlite3_file*);
    xShmMap                 POINTER ? ; (sqlite3_file*, int iPg, int pgsz, int, void volatile**);
    xShmLock                POINTER ? ; (sqlite3_file*, int offset, int n, int flags);
    xShmBarrier             POINTER ? ; (sqlite3_file*);
    xShmUnmap               POINTER ? ; (sqlite3_file*, int deleteFlag);
    xFetch                  POINTER ? ; (sqlite3_file*, sqlite3_int64 iOfst, int iAmt, void **pp);
    xUnfetch                POINTER ? ; (sqlite3_file*, sqlite3_int64 iOfst, void *p);
sqlite3_io_methods          ENDS

sqlite3_vfs                 STRUCT 8 ; 168 bytes
    iVersion                DWORD ? ; Structure version number (currently 3)
    szOsFile                DWORD ? ; Size of subclassed sqlite3_file
    mxPathname              DWORD ? ; Maximum file pathname length
    pNext                   POINTER ? ; sqlite3_vfs ; Next registered VFS
    zName                   POINTER ? ; Name of this virtual file system
    pAppData                POINTER ? ; Pointer to application-specific data
    xOpen                   POINTER ? ; (sqlite3_vfs*, sqlite3_filename zName, sqlite3_file*, int flags, int *pOutFlags);
    xDelete                 POINTER ? ; (sqlite3_vfs*, const char *zName, int syncDir);
    xAccess                 POINTER ? ; (sqlite3_vfs*, const char *zName, int flags, int *pResOut);
    xFullPathname           POINTER ? ; (sqlite3_vfs*, const char *zName, int nOut, char *zOut);
    xDlOpen                 POINTER ? ; (sqlite3_vfs*, const char *zFilename);
    xDlError                POINTER ? ; (sqlite3_vfs*, int nByte, char *zErrMsg);
    xDlSym                  POINTER ? ; (sqlite3_vfs*,void*, const char *zSymbol))(void);
    xDlClose                POINTER ? ; (sqlite3_vfs*, void*);
    xRandomness             POINTER ? ; (sqlite3_vfs*, int nByte, char *zOut);
    xSleep                  POINTER ? ; (sqlite3_vfs*, int microseconds);
    xCurrentTime            POINTER ? ; (sqlite3_vfs*, double*);
    xGetLastError           POINTER ? ; (sqlite3_vfs*, int, char *);
    xCurrentTimeInt64       POINTER ? ; (sqlite3_vfs*, sqlite3_int64*);
    xSetSystemCall          POINTER ? ; (sqlite3_vfs*, const char *zName, sqlite3_syscall_ptr);
    xGetSystemCall          POINTER ? ; (sqlite3_vfs*, const char *zName);
    xNextSystemCall         POINTER ? ; (sqlite3_vfs*, const char *zName);
sqlite3_vfs                 ENDS

sqlite3_mem_methods         STRUCT 8 ; 64 bytes
    xMalloc                 POINTER ? ; Memory allocation function
    xFree                   POINTER ? ; Free a prior allocation
    xRealloc                POINTER ? ; Resize an allocation
    xSize                   POINTER ? ; Return the size of an allocation
    xRoundup                POINTER ? ; Round up request size to allocation size
    xInit                   POINTER ? ; Initialize the memory allocator
    xShutdown               POINTER ? ; Deinitialize the memory allocator
    pAppData                POINTER ? ; Argument to xInit() and xShutdown()
sqlite3_mem_methods         ENDS

sqlite3_module              STRUCT 8 ; 200 bytes
    iVersion                DWORD ?
    xCreate                 POINTER ? ; (sqlite3*, void *pAux, int argc, const char *const*argv, sqlite3_vtab **ppVTab, char**);
    xConnect                POINTER ? ; (sqlite3*, void *pAux, int argc, const char *const*argv, sqlite3_vtab **ppVTab, char**);
    xBestIndex              POINTER ? ; (sqlite3_vtab *pVTab, sqlite3_index_info*);
    xDisconnect             POINTER ? ; (sqlite3_vtab *pVTab);
    xDestroy                POINTER ? ; (sqlite3_vtab *pVTab);
    xOpen                   POINTER ? ; (sqlite3_vtab *pVTab, sqlite3_vtab_cursor **ppCursor);
    xClose                  POINTER ? ; (sqlite3_vtab_cursor*);
    xFilter                 POINTER ? ; (sqlite3_vtab_cursor*, int idxNum, const char *idxStr, int argc, sqlite3_value **argv);
    xNext                   POINTER ? ; (sqlite3_vtab_cursor*);
    xEof                    POINTER ? ; (sqlite3_vtab_cursor*);
    xColumn                 POINTER ? ; (sqlite3_vtab_cursor*, sqlite3_context*, int);
    xRowid                  POINTER ? ; (sqlite3_vtab_cursor*, sqlite3_int64 *pRowid);
    xUpdate                 POINTER ? ; (sqlite3_vtab *, int, sqlite3_value **, sqlite3_int64 *);
    xBegin                  POINTER ? ; (sqlite3_vtab *pVTab);
    xSync                   POINTER ? ; (sqlite3_vtab *pVTab);
    xCommit                 POINTER ? ; (sqlite3_vtab *pVTab);
    xRollback               POINTER ? ; (sqlite3_vtab *pVTab);
    xFindFunction           POINTER ? ; (sqlite3_vtab *pVtab, int nArg, const char *zName, void (**pxFunc)(sqlite3_context*,int,sqlite3_value**), void **ppArg);
    xRename                 POINTER ? ; (sqlite3_vtab *pVtab, const char *zNew);
    xSavepoint              POINTER ? ; (sqlite3_vtab *pVTab, int);
    xRelease                POINTER ? ; (sqlite3_vtab *pVTab, int);
    xRollbackTo             POINTER ? ; (sqlite3_vtab *pVTab, int);
    xShadowName             POINTER ? ; (const char*);
    xIntegrity              POINTER ? ; (sqlite3_vtab *pVTab, const char *zSchema, const char *zTabName, int mFlags, char **pzErr);
sqlite3_module              ENDS

sqlite3_index_constraint    STRUCT 4 ; 12 bytes
      iColumn               DWORD ? ; Column constrained.  -1 for ROWID
      op                    BYTE ?  ; Constraint operator
      usable                BYTE ?  ; True if this constraint is usable
      iTermOffset           DWORD ? ; Used internally - xBestIndex should ignore
sqlite3_index_constraint    ENDS

sqlite3_index_orderby       STRUCT 4 ; 8 bytes
      iColumn               DWORD ? ; Column number
      desc                  BYTE ?  ; True for DESC.  False for ASC
sqlite3_index_orderby       ENDS

sqlite3_index_constraint_usage STRUCT 4 ; 8 bytes
      argvIndex             DWORD ? ; if >0, constraint is part of argv to xFilter
      omit                  BYTE ?  ; Do not code a test for this constraint
sqlite3_index_constraint_usage ENDS

sqlite3_index_info          STRUCT 8 ; 96 bytes
    nConstraint             DWORD ? ; Number of entries in aConstraint
    aConstraint             sqlite3_index_constraint <> ; Table of WHERE clause constraints
    nOrderBy                DWORD ? ; Number of terms in the ORDER BY clause
    aOrderBy                sqlite3_index_orderby <> ; The ORDER BY clause
    aConstraintUsage        sqlite3_index_constraint_usage <>
    idxNum                  DWORD ? ; Number used to identify the index
    idxStr                  POINTER ? ;  String, possibly obtained from sqlite3_malloc
    needToFreeIdxStr        DWORD ? ; Free idxStr using sqlite3_free() if true
    orderByConsumed         DWORD ? ; True if output is already ordered
    estimatedCost           REAL8 ? ; Estimated cost of using this index
    estimatedRows           sqlite3_int64 ? ; Estimated number of rows returned
    idxFlags                DWORD ? ; Mask of SQLITE_INDEX_SCAN_* flags
    colUsed                 sqlite3_uint64 ? ; Input: Mask of columns used by statement
sqlite3_index_info          ENDS

sqlite3_vtab                STRUCT 8 ; 24 bytes
    pModule                 POINTER ? ; sqlite3_module ; The module for this virtual table
    nRef                    DWORD ? ; Number of open cursors
    zErrMsg                 POINTER ? ; Error message from sqlite3_mprintf()
sqlite3_vtab                ENDS

sqlite3_vtab_cursor         STRUCT 8 ; 8 bytes
    pVtab                   POINTER ? ; sqlite3_vtab ; Virtual table of this cursor
sqlite3_vtab_cursor         ENDS

sqlite3_mutex_methods       STRUCT 8 ; 72 bytes
    xMutexInit              POINTER ? ; (void);
    xMutexEnd               POINTER ? ; (void);
    xMutexAlloc             POINTER ? ; (int);
    xMutexFree              POINTER ? ; (sqlite3_mutex *);
    xMutexEnter             POINTER ? ; (sqlite3_mutex *);
    xMutexTry               POINTER ? ; (sqlite3_mutex *);
    xMutexLeave             POINTER ? ; (sqlite3_mutex *);
    xMutexHeld              POINTER ? ; (sqlite3_mutex *);
    xMutexNotheld           POINTER ? ; (sqlite3_mutex *);
sqlite3_mutex_methods       ENDS

sqlite3_pcache_page         STRUCT 8 ; 16 bytes
    pBuf                    POINTER ? ; The content of the page
    pExtra                  POINTER ? ; Extra information associated with the page
sqlite3_pcache_page         ENDS

sqlite3_pcache_methods2     STRUCT 8 ; 104 bytes
    iVersion                DWORD ?
    pArg                    POINTER ? ; 
    xInit                   POINTER ? ; (void*);
    xShutdown               POINTER ? ; (void*);
    xCreate                 POINTER ? ; (int szPage, int szExtra, int bPurgeable);
    xCachesize              POINTER ? ; (sqlite3_pcache*, int nCachesize);
    xPagecount              POINTER ? ; (sqlite3_pcache*);
    xFetch                  POINTER ? ; (sqlite3_pcache*, unsigned key, int createFlag);
    xUnpin                  POINTER ? ; (sqlite3_pcache*, sqlite3_pcache_page*, int discard);
    xRekey                  POINTER ? ; (sqlite3_pcache*, sqlite3_pcache_page*, unsigned oldKey, unsigned newKey);
    xTruncate               POINTER ? ; (sqlite3_pcache*, unsigned iLimit);
    xDestroy                POINTER ? ; (sqlite3_pcache*);
    xShrink                 POINTER ? ; (sqlite3_pcache*);
sqlite3_pcache_methods2     ENDS

sqlite3_pcache_methods      STRUCT 8 ; 88 bytes
    pArg                    POINTER ? ; 
    xInit                   POINTER ? ; (void*);
    xShutdown               POINTER ? ; (void*);
    xCreate                 POINTER ? ; (int szPage, int bPurgeable);
    xCachesize              POINTER ? ; (sqlite3_pcache*, int nCachesize);
    xPagecount              POINTER ? ; (sqlite3_pcache*);
    xFetch                  POINTER ? ; (sqlite3_pcache*, unsigned key, int createFlag);
    xUnpin                  POINTER ? ; (sqlite3_pcache*, void*, int discard);
    xRekey                  POINTER ? ; (sqlite3_pcache*, void*, unsigned oldKey, unsigned newKey);
    xTruncate               POINTER ? ; (sqlite3_pcache*, unsigned iLimit);
    xDestroy                POINTER ? ; (sqlite3_pcache*);
sqlite3_pcache_methods      ENDS

sqlite3_snapshot            STRUCT 1 ; 48 bytes
    hidden                  BYTE 48 dup (?)
sqlite3_snapshot            ENDS

sqlite3_rtree_geometry      STRUCT 8 ; 40 bytes
    pContext                POINTER ? ; Copy of pContext passed to s_r_g_c()
    nParam                  DWORD ? ; Size of array aParam[]
    aParam                  POINTER ? ; sqlite3_rtree_dbl ; Parameters passed to SQL geom function
    pUser                   POINTER ? ; Callback implementation user data 
    xDelUser                POINTER ? ; Called by SQLite to clean up pUser
sqlite3_rtree_geometry      ENDS

ifdef SQLITE_RTREE_INT_ONLY
sqlite3_rtree_dbl typedef sqlite3_int64
else
sqlite3_rtree_dbl typedef REAL8
endif

sqlite3_rtree_query_info    STRUCT 8 ; 112 bytes
    pContext                POINTER ?
    nParam                  DWORD ?
    aParam                  POINTER ?
    pUser                   POINTER ?
    xDelUser                POINTER ?
    aCoord                  POINTER ?
    anQueue                 POINTER ?
    nCoord                  DWORD ?
    iLevel                  DWORD ?
    mxLevel                 DWORD ?
    iRowid                  sqlite3_int64 ?
    rParentScore            sqlite3_rtree_dbl ?
    eParentWithin           DWORD ?
    eWithin                 DWORD ?
    rScore                  sqlite3_rtree_dbl ?
    apSqlParam              POINTER ?
sqlite3_rtree_query_info    ENDS

Fts5PhraseIter              STRUCT 8 ; 16 bytes
    a                       POINTER ?
    b                       POINTER ?
Fts5PhraseIter              ENDS

Fts5ExtensionApi            STRUCT 8 ; 176 bytes
    iVersion                DWORD ? ; Currently always set to 3
    xUserData               POINTER ?
    xColumnCount            POINTER ?
    xRowCount               POINTER ?
    xColumnTotalSize        POINTER ?
    xTokenize               POINTER ?
    xPhraseCount            POINTER ?
    xPhraseSize             POINTER ?
    xInstCount              POINTER ?
    xInst                   POINTER ?
    xRowid                  POINTER ?
    xColumnText             POINTER ?
    xColumnSize             POINTER ?
    xQueryPhrase            POINTER ?
    xSetAuxdata             POINTER ?
    xGetAuxdata             POINTER ?
    xPhraseFirst            POINTER ?
    xPhraseNext             POINTER ?
    xPhraseFirstColumn      POINTER ?
    xPhraseNextColumn       POINTER ?
    xQueryToken             POINTER ?
    xInstToken              POINTER ?
Fts5ExtensionApi            ENDS

fts5_tokenizer              STRUCT 8 ; 24 bytes
    xCreate                 POINTER ?
    xDelete                 POINTER ?
    xTokenize               POINTER ?
fts5_tokenizer              ENDS

fts5_api                    STRUCT 8 ; 32 bytes
    iVersion                DWORD ? ; Currently always set to 2
    xCreateTokenizer        POINTER ?
    xFindTokenizer          POINTER ?
    xCreateFunction         POINTER ?
fts5_api                    ENDS

sqlite3_int64               TYPEDEF QWORD
sqlite3_uint64              TYPEDEF QWORD
sqlite_int64                TYPEDEF QWORD
sqlite_uint64               TYPEDEF QWORD
SQLITE_INT64_TYPE           TYPEDEF QWORD

.CONST

SQLITE_VERSION              TEXTEQU <"3.47.0",0>
SQLITE_VERSION_NUMBER       EQU 3047000
SQLITE_SOURCE_ID            TEXTEQU <2024-10-21 16:30:22 03a9703e27c44437c39363d0baf82db4ebc94538a0f28411c85dda156f82636e",0>

; Result Codes
SQLITE_OK                   EQU 0    ; Successful result
; beginning-of-error-codes
SQLITE_ERROR                EQU  1   ; Generic error
SQLITE_INTERNAL             EQU  2   ; Internal logic error in SQLite
SQLITE_PERM                 EQU  3   ; Access permission denied
SQLITE_ABORT                EQU  4   ; Callback routine requested an abort
SQLITE_BUSY                 EQU  5   ; The database file is locked
SQLITE_LOCKED               EQU  6   ; A table in the database is locked
SQLITE_NOMEM                EQU  7   ; A malloc() failed
SQLITE_READONLY             EQU  8   ; Attempt to write a readonly database
SQLITE_INTERRUPT            EQU  9   ; Operation terminated by sqlite3_interrupt()*/
SQLITE_IOERR                EQU 10   ; Some kind of disk I/O error occurred
SQLITE_CORRUPT              EQU 11   ; The database disk image is malformed
SQLITE_NOTFOUND             EQU 12   ; Unknown opcode in sqlite3_file_control()
SQLITE_FULL                 EQU 13   ; Insertion failed because database is full
SQLITE_CANTOPEN             EQU 14   ; Unable to open the database file
SQLITE_PROTOCOL             EQU 15   ; Database lock protocol error
SQLITE_EMPTY                EQU 16   ; Internal use only
SQLITE_SCHEMA               EQU 17   ; The database schema changed
SQLITE_TOOBIG               EQU 18   ; String or BLOB exceeds size limit
SQLITE_CONSTRAINT           EQU 19   ; Abort due to constraint violation
SQLITE_MISMATCH             EQU 20   ; Data type mismatch
SQLITE_MISUSE               EQU 21   ; Library used incorrectly
SQLITE_NOLFS                EQU 22   ; Uses OS features not supported on host
SQLITE_AUTH                 EQU 23   ; Authorization denied
SQLITE_FORMAT               EQU 24   ; Not used
SQLITE_RANGE                EQU 25   ; 2nd parameter to sqlite3_bind out of range
SQLITE_NOTADB               EQU 26   ; File opened that is not a database file
SQLITE_NOTICE               EQU 27   ; Notifications from sqlite3_log()
SQLITE_WARNING              EQU 28   ; Warnings from sqlite3_log()
SQLITE_ROW                  EQU 100  ; sqlite3_step() has another row ready
SQLITE_DONE                 EQU 101  ; sqlite3_step() has finished executing

; Extended Result Codes
SQLITE_ERROR_MISSING_COLLSEQ   EQU (SQLITE_ERROR OR (1<<8))
SQLITE_ERROR_RETRY             EQU (SQLITE_ERROR OR (2<<8))
SQLITE_ERROR_SNAPSHOT          EQU (SQLITE_ERROR OR (3<<8))
SQLITE_IOERR_READ              EQU (SQLITE_IOERR OR (1<<8))
SQLITE_IOERR_SHORT_READ        EQU (SQLITE_IOERR OR (2<<8))
SQLITE_IOERR_WRITE             EQU (SQLITE_IOERR OR (3<<8))
SQLITE_IOERR_FSYNC             EQU (SQLITE_IOERR OR (4<<8))
SQLITE_IOERR_DIR_FSYNC         EQU (SQLITE_IOERR OR (5<<8))
SQLITE_IOERR_TRUNCATE          EQU (SQLITE_IOERR OR (6<<8))
SQLITE_IOERR_FSTAT             EQU (SQLITE_IOERR OR (7<<8))
SQLITE_IOERR_UNLOCK            EQU (SQLITE_IOERR OR (8<<8))
SQLITE_IOERR_RDLOCK            EQU (SQLITE_IOERR OR (9<<8))
SQLITE_IOERR_DELETE            EQU (SQLITE_IOERR OR (10<<8))
SQLITE_IOERR_BLOCKED           EQU (SQLITE_IOERR OR (11<<8))
SQLITE_IOERR_NOMEM             EQU (SQLITE_IOERR OR (12<<8))
SQLITE_IOERR_ACCESS            EQU (SQLITE_IOERR OR (13<<8))
SQLITE_IOERR_CHECKRESERVEDLOCK EQU (SQLITE_IOERR OR (14<<8))
SQLITE_IOERR_LOCK              EQU (SQLITE_IOERR OR (15<<8))
SQLITE_IOERR_CLOSE             EQU (SQLITE_IOERR OR (16<<8))
SQLITE_IOERR_DIR_CLOSE         EQU (SQLITE_IOERR OR (17<<8))
SQLITE_IOERR_SHMOPEN           EQU (SQLITE_IOERR OR (18<<8))
SQLITE_IOERR_SHMSIZE           EQU (SQLITE_IOERR OR (19<<8))
SQLITE_IOERR_SHMLOCK           EQU (SQLITE_IOERR OR (20<<8))
SQLITE_IOERR_SHMMAP            EQU (SQLITE_IOERR OR (21<<8))
SQLITE_IOERR_SEEK              EQU (SQLITE_IOERR OR (22<<8))
SQLITE_IOERR_DELETE_NOENT      EQU (SQLITE_IOERR OR (23<<8))
SQLITE_IOERR_MMAP              EQU (SQLITE_IOERR OR (24<<8))
SQLITE_IOERR_GETTEMPPATH       EQU (SQLITE_IOERR OR (25<<8))
SQLITE_IOERR_CONVPATH          EQU (SQLITE_IOERR OR (26<<8))
SQLITE_IOERR_VNODE             EQU (SQLITE_IOERR OR (27<<8))
SQLITE_IOERR_AUTH              EQU (SQLITE_IOERR OR (28<<8))
SQLITE_IOERR_BEGIN_ATOMIC      EQU (SQLITE_IOERR OR (29<<8))
SQLITE_IOERR_COMMIT_ATOMIC     EQU (SQLITE_IOERR OR (30<<8))
SQLITE_IOERR_ROLLBACK_ATOMIC   EQU (SQLITE_IOERR OR (31<<8))
SQLITE_IOERR_DATA              EQU (SQLITE_IOERR OR (32<<8))
SQLITE_IOERR_CORRUPTFS         EQU (SQLITE_IOERR OR (33<<8))
SQLITE_IOERR_IN_PAGE           EQU (SQLITE_IOERR OR (34<<8))
SQLITE_LOCKED_SHAREDCACHE      EQU (SQLITE_LOCKED OR  (1<<8))
SQLITE_LOCKED_VTAB             EQU (SQLITE_LOCKED OR  (2<<8))
SQLITE_BUSY_RECOVERY           EQU (SQLITE_BUSY   OR  (1<<8))
SQLITE_BUSY_SNAPSHOT           EQU (SQLITE_BUSY   OR  (2<<8))
SQLITE_BUSY_TIMEOUT            EQU (SQLITE_BUSY   OR  (3<<8))
SQLITE_CANTOPEN_NOTEMPDIR      EQU (SQLITE_CANTOPEN OR (1<<8))
SQLITE_CANTOPEN_ISDIR          EQU (SQLITE_CANTOPEN OR (2<<8))
SQLITE_CANTOPEN_FULLPATH       EQU (SQLITE_CANTOPEN OR (3<<8))
SQLITE_CANTOPEN_CONVPATH       EQU (SQLITE_CANTOPEN OR (4<<8))
SQLITE_CANTOPEN_DIRTYWAL       EQU (SQLITE_CANTOPEN OR (5<<8)) ; Not Used
SQLITE_CANTOPEN_SYMLINK        EQU (SQLITE_CANTOPEN OR (6<<8))
SQLITE_CORRUPT_VTAB            EQU (SQLITE_CORRUPT OR (1<<8))
SQLITE_CORRUPT_SEQUENCE        EQU (SQLITE_CORRUPT OR (2<<8))
SQLITE_CORRUPT_INDEX           EQU (SQLITE_CORRUPT OR (3<<8))
SQLITE_READONLY_RECOVERY       EQU (SQLITE_READONLY OR (1<<8))
SQLITE_READONLY_CANTLOCK       EQU (SQLITE_READONLY OR (2<<8))
SQLITE_READONLY_ROLLBACK       EQU (SQLITE_READONLY OR (3<<8))
SQLITE_READONLY_DBMOVED        EQU (SQLITE_READONLY OR (4<<8))
SQLITE_READONLY_CANTINIT       EQU (SQLITE_READONLY OR (5<<8))
SQLITE_READONLY_DIRECTORY      EQU (SQLITE_READONLY OR (6<<8))
SQLITE_ABORT_ROLLBACK          EQU (SQLITE_ABORT OR (2<<8))
SQLITE_CONSTRAINT_CHECK        EQU (SQLITE_CONSTRAINT OR (1<<8))
SQLITE_CONSTRAINT_COMMITHOOK   EQU (SQLITE_CONSTRAINT OR (2<<8))
SQLITE_CONSTRAINT_FOREIGNKEY   EQU (SQLITE_CONSTRAINT OR (3<<8))
SQLITE_CONSTRAINT_FUNCTION     EQU (SQLITE_CONSTRAINT OR (4<<8))
SQLITE_CONSTRAINT_NOTNULL      EQU (SQLITE_CONSTRAINT OR (5<<8))
SQLITE_CONSTRAINT_PRIMARYKEY   EQU (SQLITE_CONSTRAINT OR (6<<8))
SQLITE_CONSTRAINT_TRIGGER      EQU (SQLITE_CONSTRAINT OR (7<<8))
SQLITE_CONSTRAINT_UNIQUE       EQU (SQLITE_CONSTRAINT OR (8<<8))
SQLITE_CONSTRAINT_VTAB         EQU (SQLITE_CONSTRAINT OR (9<<8))
SQLITE_CONSTRAINT_ROWID        EQU (SQLITE_CONSTRAINT OR(10<<8))
SQLITE_CONSTRAINT_PINNED       EQU (SQLITE_CONSTRAINT OR(11<<8))
SQLITE_CONSTRAINT_DATATYPE     EQU (SQLITE_CONSTRAINT OR(12<<8))
SQLITE_NOTICE_RECOVER_WAL      EQU (SQLITE_NOTICE OR (1<<8))
SQLITE_NOTICE_RECOVER_ROLLBACK EQU (SQLITE_NOTICE OR (2<<8))
SQLITE_NOTICE_RBU              EQU (SQLITE_NOTICE OR (3<<8))
SQLITE_WARNING_AUTOINDEX       EQU (SQLITE_WARNING OR (1<<8))
SQLITE_AUTH_USER               EQU (SQLITE_AUTH OR (1<<8))
SQLITE_OK_LOAD_PERMANENTLY     EQU (SQLITE_OK OR (1<<8))
SQLITE_OK_SYMLINK              EQU (SQLITE_OK OR (2<<8)); internal use only

; Flags For File Open Operations
SQLITE_OPEN_READONLY        EQU 00000001h ; Ok for sqlite3_open_v2()
SQLITE_OPEN_READWRITE       EQU 00000002h ; Ok for sqlite3_open_v2()
SQLITE_OPEN_CREATE          EQU 00000004h ; Ok for sqlite3_open_v2()
SQLITE_OPEN_DELETEONCLOSE   EQU 00000008h ; VFS only
SQLITE_OPEN_EXCLUSIVE       EQU 00000010h ; VFS only
SQLITE_OPEN_AUTOPROXY       EQU 00000020h ; VFS only
SQLITE_OPEN_URI             EQU 00000040h ; Ok for sqlite3_open_v2()
SQLITE_OPEN_MEMORY          EQU 00000080h ; Ok for sqlite3_open_v2()
SQLITE_OPEN_MAIN_DB         EQU 00000100h ; VFS only
SQLITE_OPEN_TEMP_DB         EQU 00000200h ; VFS only
SQLITE_OPEN_TRANSIENT_DB    EQU 00000400h ; VFS only
SQLITE_OPEN_MAIN_JOURNAL    EQU 00000800h ; VFS only
SQLITE_OPEN_TEMP_JOURNAL    EQU 00001000h ; VFS only
SQLITE_OPEN_SUBJOURNAL      EQU 00002000h ; VFS only
SQLITE_OPEN_SUPER_JOURNAL   EQU 00004000h ; VFS only
SQLITE_OPEN_NOMUTEX         EQU 00008000h ; Ok for sqlite3_open_v2()
SQLITE_OPEN_FULLMUTEX       EQU 00010000h ; Ok for sqlite3_open_v2()
SQLITE_OPEN_SHAREDCACHE     EQU 00020000h ; Ok for sqlite3_open_v2()
SQLITE_OPEN_PRIVATECACHE    EQU 00040000h ; Ok for sqlite3_open_v2()
SQLITE_OPEN_WAL             EQU 00080000h ; VFS only
SQLITE_OPEN_NOFOLLOW        EQU 01000000h ; Ok for sqlite3_open_v2()
SQLITE_OPEN_EXRESCODE       EQU 02000000h ; Extended result codes
;Reserved:                  EQU 00F00000h
Legacy compatibility:
SQLITE_OPEN_MASTER_JOURNAL  EQU 00004000h  ; VFS only

; Device Characteristics
SQLITE_IOCAP_ATOMIC                EQU 00000001h
SQLITE_IOCAP_ATOMIC512             EQU 00000002h
SQLITE_IOCAP_ATOMIC1K              EQU 00000004h
SQLITE_IOCAP_ATOMIC2K              EQU 00000008h
SQLITE_IOCAP_ATOMIC4K              EQU 00000010h
SQLITE_IOCAP_ATOMIC8K              EQU 00000020h
SQLITE_IOCAP_ATOMIC16K             EQU 00000040h
SQLITE_IOCAP_ATOMIC32K             EQU 00000080h
SQLITE_IOCAP_ATOMIC64K             EQU 00000100h
SQLITE_IOCAP_SAFE_APPEND           EQU 00000200h
SQLITE_IOCAP_SEQUENTIAL            EQU 00000400h
SQLITE_IOCAP_UNDELETABLE_WHEN_OPEN EQU 00000800h
SQLITE_IOCAP_POWERSAFE_OVERWRITE   EQU 00001000h
SQLITE_IOCAP_IMMUTABLE             EQU 00002000h
SQLITE_IOCAP_BATCH_ATOMIC          EQU 00004000h

; File Locking Levels
SQLITE_LOCK_NONE            EQU 0 ; xUnlock() only */
SQLITE_LOCK_SHARED          EQU 1 ; xLock() or xUnlock() */
SQLITE_LOCK_RESERVED        EQU 2 ; xLock() only */
SQLITE_LOCK_PENDING         EQU 3 ; xLock() only */
SQLITE_LOCK_EXCLUSIVE       EQU 4 ; xLock() only */

; Synchronization Type Flags
SQLITE_SYNC_NORMAL          EQU 00002h
SQLITE_SYNC_FULL            EQU 00003h
SQLITE_SYNC_DATAONLY        EQU 00010h

OS Interface Open File Handle



; Standard File Control Opcodes
SQLITE_FCNTL_LOCKSTATE             EQU  1
SQLITE_FCNTL_GET_LOCKPROXYFILE     EQU  2
SQLITE_FCNTL_SET_LOCKPROXYFILE     EQU  3
SQLITE_FCNTL_LAST_ERRNO            EQU  4
SQLITE_FCNTL_SIZE_HINT             EQU  5
SQLITE_FCNTL_CHUNK_SIZE            EQU  6
SQLITE_FCNTL_FILE_POINTER          EQU  7
SQLITE_FCNTL_SYNC_OMITTED          EQU  8
SQLITE_FCNTL_WIN32_AV_RETRY        EQU  9
SQLITE_FCNTL_PERSIST_WAL           EQU 10
SQLITE_FCNTL_OVERWRITE             EQU 11
SQLITE_FCNTL_VFSNAME               EQU 12
SQLITE_FCNTL_POWERSAFE_OVERWRITE   EQU 13
SQLITE_FCNTL_PRAGMA                EQU 14
SQLITE_FCNTL_BUSYHANDLER           EQU 15
SQLITE_FCNTL_TEMPFILENAME          EQU 16
SQLITE_FCNTL_MMAP_SIZE             EQU 18
SQLITE_FCNTL_TRACE                 EQU 19
SQLITE_FCNTL_HAS_MOVED             EQU 20
SQLITE_FCNTL_SYNC                  EQU 21
SQLITE_FCNTL_COMMIT_PHASETWO       EQU 22
SQLITE_FCNTL_WIN32_SET_HANDLE      EQU 23
SQLITE_FCNTL_WAL_BLOCK             EQU 24
SQLITE_FCNTL_ZIPVFS                EQU 25
SQLITE_FCNTL_RBU                   EQU 26
SQLITE_FCNTL_VFS_POINTER           EQU 27
SQLITE_FCNTL_JOURNAL_POINTER       EQU 28
SQLITE_FCNTL_WIN32_GET_HANDLE      EQU 29
SQLITE_FCNTL_PDB                   EQU 30
SQLITE_FCNTL_BEGIN_ATOMIC_WRITE    EQU 31
SQLITE_FCNTL_COMMIT_ATOMIC_WRITE   EQU 32
SQLITE_FCNTL_ROLLBACK_ATOMIC_WRITE EQU 33
SQLITE_FCNTL_LOCK_TIMEOUT          EQU 34
SQLITE_FCNTL_DATA_VERSION          EQU 35
SQLITE_FCNTL_SIZE_LIMIT            EQU 36
SQLITE_FCNTL_CKPT_DONE             EQU 37
SQLITE_FCNTL_RESERVE_BYTES         EQU 38
SQLITE_FCNTL_CKPT_START            EQU 39
SQLITE_FCNTL_EXTERNAL_READER       EQU 40
SQLITE_FCNTL_CKSM_FILE             EQU 41
SQLITE_FCNTL_RESET_CACHE           EQU 42

;  deprecated names
SQLITE_GET_LOCKPROXYFILE        EQU SQLITE_FCNTL_GET_LOCKPROXYFILE
SQLITE_SET_LOCKPROXYFILE        EQU SQLITE_FCNTL_SET_LOCKPROXYFILE
SQLITE_LAST_ERRNO               EQU SQLITE_FCNTL_LAST_ERRNO

; Flags for the xAccess VFS method
SQLITE_ACCESS_EXISTS            EQU 0
SQLITE_ACCESS_READWRITE         EQU 1 ; Used by PRAGMA temp_store_directory */
SQLITE_ACCESS_READ              EQU 2 ; Unused */

; Flags for the xShmLock VFS method
SQLITE_SHM_UNLOCK               EQU 1
SQLITE_SHM_LOCK                 EQU 2
SQLITE_SHM_SHARED               EQU 4
SQLITE_SHM_EXCLUSIVE            EQU 8

; Maximum xShmLock index
SQLITE_SHM_NLOCK                EQU 8

; Configuration Options
SQLITE_CONFIG_SINGLETHREAD        EQU  1 ; nil */
SQLITE_CONFIG_MULTITHREAD         EQU  2 ; nil */
SQLITE_CONFIG_SERIALIZED          EQU  3 ; nil */
SQLITE_CONFIG_MALLOC              EQU  4 ; sqlite3_mem_methods* */
SQLITE_CONFIG_GETMALLOC           EQU  5 ; sqlite3_mem_methods* */
SQLITE_CONFIG_SCRATCH             EQU  6 ; No longer used */
SQLITE_CONFIG_PAGECACHE           EQU  7 ; void*, int sz, int N */
SQLITE_CONFIG_HEAP                EQU  8 ; void*, int nByte, int min */
SQLITE_CONFIG_MEMSTATUS           EQU  9 ; boolean */
SQLITE_CONFIG_MUTEX               EQU 10 ; sqlite3_mutex_methods* */
SQLITE_CONFIG_GETMUTEX            EQU 11 ; sqlite3_mutex_methods* */
; previously SQLITE_CONFIG_CHUNKALLOC EQU 12 ; which is now unused. */
SQLITE_CONFIG_LOOKASIDE           EQU 13 ; int int */
SQLITE_CONFIG_PCACHE              EQU 14 ; no-op */
SQLITE_CONFIG_GETPCACHE           EQU 15 ; no-op */
SQLITE_CONFIG_LOG                 EQU 16 ; xFunc, void* */
SQLITE_CONFIG_URI                 EQU 17 ; int */
SQLITE_CONFIG_PCACHE2             EQU 18 ; sqlite3_pcache_methods2* */
SQLITE_CONFIG_GETPCACHE2          EQU 19 ; sqlite3_pcache_methods2* */
SQLITE_CONFIG_COVERING_INDEX_SCAN EQU 20 ; int */
SQLITE_CONFIG_SQLLOG              EQU 21 ; xSqllog, void* */
SQLITE_CONFIG_MMAP_SIZE           EQU 22 ; sqlite3_int64, sqlite3_int64 */
SQLITE_CONFIG_WIN32_HEAPSIZE      EQU 23 ; int nByte */
SQLITE_CONFIG_PCACHE_HDRSZ        EQU 24 ; int *psz */
SQLITE_CONFIG_PMASZ               EQU 25 ; unsigned int szPma */
SQLITE_CONFIG_STMTJRNL_SPILL      EQU 26 ; int nByte */
SQLITE_CONFIG_SMALL_MALLOC        EQU 27 ; boolean */
SQLITE_CONFIG_SORTERREF_SIZE      EQU 28 ; int nByte */
SQLITE_CONFIG_MEMDB_MAXSIZE       EQU 29 ; sqlite3_int64 */

; Database Connection Configuration Options
SQLITE_DBCONFIG_MAINDBNAME            EQU 1000 ; const char* */
SQLITE_DBCONFIG_LOOKASIDE             EQU 1001 ; void* int int */
SQLITE_DBCONFIG_ENABLE_FKEY           EQU 1002 ; int int* */
SQLITE_DBCONFIG_ENABLE_TRIGGER        EQU 1003 ; int int* */
SQLITE_DBCONFIG_ENABLE_FTS3_TOKENIZER EQU 1004 ; int int* */
SQLITE_DBCONFIG_ENABLE_LOAD_EXTENSION EQU 1005 ; int int* */
SQLITE_DBCONFIG_NO_CKPT_ON_CLOSE      EQU 1006 ; int int* */
SQLITE_DBCONFIG_ENABLE_QPSG           EQU 1007 ; int int* */
SQLITE_DBCONFIG_TRIGGER_EQP           EQU 1008 ; int int* */
SQLITE_DBCONFIG_RESET_DATABASE        EQU 1009 ; int int* */
SQLITE_DBCONFIG_DEFENSIVE             EQU 1010 ; int int* */
SQLITE_DBCONFIG_WRITABLE_SCHEMA       EQU 1011 ; int int* */
SQLITE_DBCONFIG_LEGACY_ALTER_TABLE    EQU 1012 ; int int* */
SQLITE_DBCONFIG_DQS_DML               EQU 1013 ; int int* */
SQLITE_DBCONFIG_DQS_DDL               EQU 1014 ; int int* */
SQLITE_DBCONFIG_ENABLE_VIEW           EQU 1015 ; int int* */
SQLITE_DBCONFIG_LEGACY_FILE_FORMAT    EQU 1016 ; int int* */
SQLITE_DBCONFIG_TRUSTED_SCHEMA        EQU 1017 ; int int* */
SQLITE_DBCONFIG_STMT_SCANSTATUS       EQU 1018 ; int int* */
SQLITE_DBCONFIG_REVERSE_SCANORDER     EQU 1019 ; int int* */
SQLITE_DBCONFIG_MAX                   EQU 1019 ; Largest DBCONFIG */

; Authorizer Action Codes
;*************************************** 3rd *********** 4th *************
SQLITE_CREATE_INDEX             EQU  1 ; Index Name      Table Name      *
SQLITE_CREATE_TABLE             EQU  2 ; Table Name      NULL            *
SQLITE_CREATE_TEMP_INDEX        EQU  3 ; Index Name      Table Name      *
SQLITE_CREATE_TEMP_TABLE        EQU  4 ; Table Name      NULL            *
SQLITE_CREATE_TEMP_TRIGGER      EQU  5 ; Trigger Name    Table Name      *
SQLITE_CREATE_TEMP_VIEW         EQU  6 ; View Name       NULL            *
SQLITE_CREATE_TRIGGER           EQU  7 ; Trigger Name    Table Name      *
SQLITE_CREATE_VIEW              EQU  8 ; View Name       NULL            *
SQLITE_DELETE                   EQU  9 ; Table Name      NULL            *
SQLITE_DROP_INDEX               EQU 10 ; Index Name      Table Name      *
SQLITE_DROP_TABLE               EQU 11 ; Table Name      NULL            *
SQLITE_DROP_TEMP_INDEX          EQU 12 ; Index Name      Table Name      *
SQLITE_DROP_TEMP_TABLE          EQU 13 ; Table Name      NULL            *
SQLITE_DROP_TEMP_TRIGGER        EQU 14 ; Trigger Name    Table Name      *
SQLITE_DROP_TEMP_VIEW           EQU 15 ; View Name       NULL            *
SQLITE_DROP_TRIGGER             EQU 16 ; Trigger Name    Table Name      *
SQLITE_DROP_VIEW                EQU 17 ; View Name       NULL            *
SQLITE_INSERT                   EQU 18 ; Table Name      NULL            *
SQLITE_PRAGMA                   EQU 19 ; Pragma Name     1st arg or NULL *
SQLITE_READ                     EQU 20 ; Table Name      Column Name     *
SQLITE_SELECT                   EQU 21 ; NULL            NULL            *
SQLITE_TRANSACTION              EQU 22 ; Operation       NULL            *
SQLITE_UPDATE                   EQU 23 ; Table Name      Column Name     *
SQLITE_ATTACH                   EQU 24 ; Filename        NULL            *
SQLITE_DETACH                   EQU 25 ; Database Name   NULL            *
SQLITE_ALTER_TABLE              EQU 26 ; Database Name   Table Name      *
SQLITE_REINDEX                  EQU 27 ; Index Name      NULL            *
SQLITE_ANALYZE                  EQU 28 ; Table Name      NULL            *
SQLITE_CREATE_VTABLE            EQU 29 ; Table Name      Module Name     *
SQLITE_DROP_VTABLE              EQU 30 ; Table Name      Module Name     *
SQLITE_FUNCTION                 EQU 31 ; NULL            Function Name   *
SQLITE_SAVEPOINT                EQU 32 ; Operation       Savepoint Name  *
SQLITE_COPY                     EQU  0 ; No longer used                  *
SQLITE_RECURSIVE                EQU 33 ; NULL            NULL            *

; SQL Trace Event Codes
SQLITE_TRACE_STMT               EQU 01h
SQLITE_TRACE_PROFILE            EQU 02h
SQLITE_TRACE_ROW                EQU 04h
SQLITE_TRACE_CLOSE              EQU 08h

; Run-Time Limit Categories
SQLITE_LIMIT_LENGTH              EQU  0
SQLITE_LIMIT_SQL_LENGTH          EQU  1
SQLITE_LIMIT_COLUMN              EQU  2
SQLITE_LIMIT_EXPR_DEPTH          EQU  3
SQLITE_LIMIT_COMPOUND_SELECT     EQU  4
SQLITE_LIMIT_VDBE_OP             EQU  5
SQLITE_LIMIT_FUNCTION_ARG        EQU  6
SQLITE_LIMIT_ATTACHED            EQU  7
SQLITE_LIMIT_LIKE_PATTERN_LENGTH EQU  8
SQLITE_LIMIT_VARIABLE_NUMBER     EQU  9
SQLITE_LIMIT_TRIGGER_DEPTH       EQU 10
SQLITE_LIMIT_WORKER_THREADS      EQU 11

; Prepare Flags
SQLITE_PREPARE_PERSISTENT       EQU 01h
SQLITE_PREPARE_NORMALIZE        EQU 02h
SQLITE_PREPARE_NO_VTAB          EQU 04h

; Fundamental Datatypes
SQLITE_INTEGER                  EQU 1
SQLITE_FLOAT                    EQU 2
SQLITE_TEXT                     EQU 3
SQLITE3_TEXT                    EQU 3
SQLITE_BLOB                     EQU 4
SQLITE_NULL                     EQU 5

; Text Encodings
SQLITE_UTF8                     EQU 1 ; IMP: R-37514-35566 */
SQLITE_UTF16LE                  EQU 2 ; IMP: R-03371-37637 */
SQLITE_UTF16BE                  EQU 3 ; IMP: R-51971-34154 */
SQLITE_UTF16                    EQU 4 ; Use native byte order */
SQLITE_ANY                      EQU 5 ; Deprecated */
SQLITE_UTF16_ALIGNED            EQU 8 ; sqlite3_create_collation only */

; Function Flags
SQLITE_DETERMINISTIC            EQU 000000800h
SQLITE_DIRECTONLY               EQU 000080000h
SQLITE_SUBTYPE                  EQU 000100000h
SQLITE_INNOCUOUS                EQU 000200000h
SQLITE_RESULT_SUBTYPE           EQU 001000000h

; Allowed return values from sqlite3_txn_state()
SQLITE_TXN_NONE                 EQU 0
SQLITE_TXN_READ                 EQU 1
SQLITE_TXN_WRITE                EQU 2

; Virtual Table Constraint Operator Codes
SQLITE_INDEX_CONSTRAINT_EQ        EQU   2
SQLITE_INDEX_CONSTRAINT_GT        EQU   4
SQLITE_INDEX_CONSTRAINT_LE        EQU   8
SQLITE_INDEX_CONSTRAINT_LT        EQU  16
SQLITE_INDEX_CONSTRAINT_GE        EQU  32
SQLITE_INDEX_CONSTRAINT_MATCH     EQU  64
SQLITE_INDEX_CONSTRAINT_LIKE      EQU  65
SQLITE_INDEX_CONSTRAINT_GLOB      EQU  66
SQLITE_INDEX_CONSTRAINT_REGEXP    EQU  67
SQLITE_INDEX_CONSTRAINT_NE        EQU  68
SQLITE_INDEX_CONSTRAINT_ISNOT     EQU  69
SQLITE_INDEX_CONSTRAINT_ISNOTNULL EQU  70
SQLITE_INDEX_CONSTRAINT_ISNULL    EQU  71
SQLITE_INDEX_CONSTRAINT_IS        EQU  72
SQLITE_INDEX_CONSTRAINT_LIMIT     EQU  73
SQLITE_INDEX_CONSTRAINT_OFFSET    EQU  74
SQLITE_INDEX_CONSTRAINT_FUNCTION  EQU 150

; Mutex Types
SQLITE_MUTEX_FAST               EQU  0
SQLITE_MUTEX_RECURSIVE          EQU  1
SQLITE_MUTEX_STATIC_MAIN        EQU  2
SQLITE_MUTEX_STATIC_MEM         EQU  3 ; sqlite3_malloc() */
SQLITE_MUTEX_STATIC_MEM2        EQU  4 ; NOT USED */
SQLITE_MUTEX_STATIC_OPEN        EQU  4 ; sqlite3BtreeOpen() */
SQLITE_MUTEX_STATIC_PRNG        EQU  5 ; sqlite3_randomness() */
SQLITE_MUTEX_STATIC_LRU         EQU  6 ; lru page list */
SQLITE_MUTEX_STATIC_LRU2        EQU  7 ; NOT USED */
SQLITE_MUTEX_STATIC_PMEM        EQU  7 ; sqlite3PageMalloc() */
SQLITE_MUTEX_STATIC_APP1        EQU  8 ; For use by application */
SQLITE_MUTEX_STATIC_APP2        EQU  9 ; For use by application */
SQLITE_MUTEX_STATIC_APP3        EQU 10 ; For use by application */
SQLITE_MUTEX_STATIC_VFS1        EQU 11 ; For use by built-in VFS */
SQLITE_MUTEX_STATIC_VFS2        EQU 12 ; For use by extension VFS */
SQLITE_MUTEX_STATIC_VFS3        EQU 13 ; For use by application VFS */

; Legacy compatibility:
SQLITE_MUTEX_STATIC_MASTER      EQU 2

; Testing Interface Operation Codes
SQLITE_TESTCTRL_FIRST                EQU  5
SQLITE_TESTCTRL_PRNG_SAVE            EQU  5
SQLITE_TESTCTRL_PRNG_RESTORE         EQU  6
SQLITE_TESTCTRL_PRNG_RESET           EQU  7  ; NOT USED */
SQLITE_TESTCTRL_FK_NO_ACTION         EQU  7
SQLITE_TESTCTRL_BITVEC_TEST          EQU  8
SQLITE_TESTCTRL_FAULT_INSTALL        EQU  9
SQLITE_TESTCTRL_BENIGN_MALLOC_HOOKS  EQU 10
SQLITE_TESTCTRL_PENDING_BYTE         EQU 11
SQLITE_TESTCTRL_ASSERT               EQU 12
SQLITE_TESTCTRL_ALWAYS               EQU 13
SQLITE_TESTCTRL_RESERVE              EQU 14  ; NOT USED */
SQLITE_TESTCTRL_JSON_SELFCHECK       EQU 14
SQLITE_TESTCTRL_OPTIMIZATIONS        EQU 15
SQLITE_TESTCTRL_ISKEYWORD            EQU 16  ; NOT USED */
SQLITE_TESTCTRL_SCRATCHMALLOC        EQU 17  ; NOT USED */
SQLITE_TESTCTRL_INTERNAL_FUNCTIONS   EQU 17
SQLITE_TESTCTRL_LOCALTIME_FAULT      EQU 18
SQLITE_TESTCTRL_EXPLAIN_STMT         EQU 19  ; NOT USED */
SQLITE_TESTCTRL_ONCE_RESET_THRESHOLD EQU 19
SQLITE_TESTCTRL_NEVER_CORRUPT        EQU 20
SQLITE_TESTCTRL_VDBE_COVERAGE        EQU 21
SQLITE_TESTCTRL_BYTEORDER            EQU 22
SQLITE_TESTCTRL_ISINIT               EQU 23
SQLITE_TESTCTRL_SORTER_MMAP          EQU 24
SQLITE_TESTCTRL_IMPOSTER             EQU 25
SQLITE_TESTCTRL_PARSER_COVERAGE      EQU 26
SQLITE_TESTCTRL_RESULT_INTREAL       EQU 27
SQLITE_TESTCTRL_PRNG_SEED            EQU 28
SQLITE_TESTCTRL_EXTRA_SCHEMA_CHECKS  EQU 29
SQLITE_TESTCTRL_SEEK_COUNT           EQU 30
SQLITE_TESTCTRL_TRACEFLAGS           EQU 31
SQLITE_TESTCTRL_TUNE                 EQU 32
SQLITE_TESTCTRL_LOGEST               EQU 33
SQLITE_TESTCTRL_USELONGDOUBLE        EQU 34
SQLITE_TESTCTRL_LAST                 EQU 34  ; Largest TESTCTRL */

; Status Parameters
SQLITE_STATUS_MEMORY_USED        EQU 0
SQLITE_STATUS_PAGECACHE_USED     EQU 1
SQLITE_STATUS_PAGECACHE_OVERFLOW EQU 2
SQLITE_STATUS_SCRATCH_USED       EQU 3  ; NOT USED */
SQLITE_STATUS_SCRATCH_OVERFLOW   EQU 4  ; NOT USED */
SQLITE_STATUS_MALLOC_SIZE        EQU 5
SQLITE_STATUS_PARSER_STACK       EQU 6
SQLITE_STATUS_PAGECACHE_SIZE     EQU 7
SQLITE_STATUS_SCRATCH_SIZE       EQU 8  ; NOT USED */
SQLITE_STATUS_MALLOC_COUNT       EQU 9

; Status Parameters for database connections
SQLITE_DBSTATUS_LOOKASIDE_USED      EQU  0
SQLITE_DBSTATUS_CACHE_USED          EQU  1
SQLITE_DBSTATUS_SCHEMA_USED         EQU  2
SQLITE_DBSTATUS_STMT_USED           EQU  3
SQLITE_DBSTATUS_LOOKASIDE_HIT       EQU  4
SQLITE_DBSTATUS_LOOKASIDE_MISS_SIZE EQU  5
SQLITE_DBSTATUS_LOOKASIDE_MISS_FULL EQU  6
SQLITE_DBSTATUS_CACHE_HIT           EQU  7
SQLITE_DBSTATUS_CACHE_MISS          EQU  8
SQLITE_DBSTATUS_CACHE_WRITE         EQU  9
SQLITE_DBSTATUS_DEFERRED_FKS        EQU 10
SQLITE_DBSTATUS_CACHE_USED_SHARED   EQU 11
SQLITE_DBSTATUS_CACHE_SPILL         EQU 12
SQLITE_DBSTATUS_MAX                 EQU 12  ; Largest defined DBSTATUS */

; Status Parameters for prepared statements
SQLITE_STMTSTATUS_FULLSCAN_STEP EQU 1
SQLITE_STMTSTATUS_SORT          EQU 2
SQLITE_STMTSTATUS_AUTOINDEX     EQU 3
SQLITE_STMTSTATUS_VM_STEP       EQU 4
SQLITE_STMTSTATUS_REPREPARE     EQU 5
SQLITE_STMTSTATUS_RUN           EQU 6
SQLITE_STMTSTATUS_FILTER_MISS   EQU 7
SQLITE_STMTSTATUS_FILTER_HIT    EQU 8
SQLITE_STMTSTATUS_MEMUSED       EQU 99

; Checkpoint Mode Values
SQLITE_CHECKPOINT_PASSIVE       EQU 0 ; Do as much as possible w/o blocking */
SQLITE_CHECKPOINT_FULL          EQU 1 ; Wait for writers, then checkpoint */
SQLITE_CHECKPOINT_RESTART       EQU 2 ; Like FULL but wait for readers */
SQLITE_CHECKPOINT_TRUNCATE      EQU 3 ; Like RESTART but also truncate WAL */

; Virtual Table Configuration Options
SQLITE_VTAB_CONSTRAINT_SUPPORT  EQU 1
SQLITE_VTAB_INNOCUOUS           EQU 2
SQLITE_VTAB_DIRECTONLY          EQU 3
SQLITE_VTAB_USES_ALL_SCHEMAS    EQU 4

; Conflict resolution modes
SQLITE_ROLLBACK                 EQU 1
;SQLITE_IGNORE                  EQU 2 ; Also used by sqlite3_authorizer() callback */
SQLITE_FAIL                     EQU 3
;SQLITE_ABORT                   EQU 4 ; Also an error code */
SQLITE_REPLACE                  EQU 5

; Prepared Statement Scan Status Opcodes
SQLITE_SCANSTAT_NLOOP           EQU 0
SQLITE_SCANSTAT_NVISIT          EQU 1
SQLITE_SCANSTAT_EST             EQU 2
SQLITE_SCANSTAT_NAME            EQU 3
SQLITE_SCANSTAT_EXPLAIN         EQU 4
SQLITE_SCANSTAT_SELECTID        EQU 5
SQLITE_SCANSTAT_PARENTID        EQU 6
SQLITE_SCANSTAT_NCYCLE          EQU 7

; Prepared Statement Scan Status
SQLITE_SCANSTAT_COMPLEX         EQU 0001h

; Flags for sqlite3_deserialize()
SQLITE_DESERIALIZE_FREEONCLOSE  EQU 1 ; Call sqlite3_free() on close */
SQLITE_DESERIALIZE_RESIZEABLE   EQU 2 ; Resize using sqlite3_realloc64() */
SQLITE_DESERIALIZE_READONLY     EQU 4 ; Database is read-only */

; Options for sqlite3session_object_config
SQLITE_SESSION_OBJCONFIG_SIZE   EQU 1
SQLITE_SESSION_OBJCONFIG_ROWID  EQU 2

; Flags for sqlite3changeset_start_v2
SQLITE_CHANGESETSTART_INVERT    EQU 0002h

; Flags for sqlite3changeset_apply_v2
SQLITE_CHANGESETAPPLY_NOSAVEPOINT EQU 0001h
SQLITE_CHANGESETAPPLY_INVERT      EQU 0002h
SQLITE_CHANGESETAPPLY_IGNORENOOP  EQU 0004h
SQLITE_CHANGESETAPPLY_FKNOACTION  EQU 0008h

; Constants Passed To The Conflict Handler
SQLITE_CHANGESET_DATA           EQU 1
SQLITE_CHANGESET_NOTFOUND       EQU 2
SQLITE_CHANGESET_CONFLICT       EQU 3
SQLITE_CHANGESET_CONSTRAINT     EQU 4
SQLITE_CHANGESET_FOREIGN_KEY    EQU 5

; Constants Returned By The Conflict Handler
SQLITE_CHANGESET_OMIT           EQU 0
SQLITE_CHANGESET_REPLACE        EQU 1
SQLITE_CHANGESET_ABORT          EQU 2

; Values for sqlite3session_config()
SQLITE_SESSION_CONFIG_STRMSIZE      EQU 1

; Flags that may be passed as the third argument to xTokenize()
FTS5_TOKENIZE_QUERY             EQU 0001h
FTS5_TOKENIZE_PREFIX            EQU 0002h
FTS5_TOKENIZE_DOCUMENT          EQU 0004h
FTS5_TOKENIZE_AUX               EQU 0008h
FTS5_TOKEN_COLOCATED            EQU 0001h ; Same position as prev. token */

























