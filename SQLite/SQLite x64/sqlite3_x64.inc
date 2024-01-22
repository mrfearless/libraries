include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

sqlite3_aggregate_context PROTO :QWORD,:QWORD
sqlite3_aggregate_count PROTO :QWORD
sqlite3_auto_extension PROTO :QWORD
sqlite3_backup_finish PROTO :QWORD
sqlite3_backup_init PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_backup_pagecount PROTO :QWORD
sqlite3_backup_remaining PROTO :QWORD
sqlite3_backup_step PROTO :QWORD,:QWORD
sqlite3_bind_blob64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_bind_blob PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_bind_double PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_bind_int64 PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_bind_int PROTO :QWORD,:QWORD,:QWORD
sqlite3_bind_null PROTO :QWORD,:QWORD
sqlite3_bind_parameter_count PROTO :QWORD
sqlite3_bind_parameter_index PROTO :QWORD,:QWORD
sqlite3_bind_parameter_name PROTO :QWORD,:QWORD
sqlite3_bind_pointer PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_bind_text16 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_bind_text64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_bind_text PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_bind_value PROTO :QWORD,:QWORD,:QWORD
sqlite3_bind_zeroblob64 PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_bind_zeroblob PROTO :QWORD,:QWORD,:QWORD
sqlite3_blob_bytes PROTO :QWORD
sqlite3_blob_close PROTO :QWORD
sqlite3_blob_open PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_blob_read PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_blob_reopen PROTO :QWORD,:QWORD,:QWORD
sqlite3_blob_write PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_busy_handler PROTO :QWORD,:QWORD,:QWORD
sqlite3_busy_timeout PROTO :QWORD,:QWORD
sqlite3_cancel_auto_extension PROTO :QWORD
sqlite3_changes PROTO :QWORD
sqlite3_clear_bindings PROTO :QWORD
sqlite3_close PROTO :QWORD
sqlite3_close_v2 PROTO :QWORD
sqlite3_collation_needed16 PROTO :QWORD,:QWORD,:QWORD
sqlite3_collation_needed PROTO :QWORD,:QWORD,:QWORD
sqlite3_column_blob PROTO :QWORD,:QWORD
sqlite3_column_bytes16 PROTO :QWORD,:QWORD
sqlite3_column_bytes PROTO :QWORD,:QWORD
sqlite3_column_count PROTO :QWORD
sqlite3_column_decltype16 PROTO :QWORD,:QWORD
sqlite3_column_decltype PROTO :QWORD,:QWORD
sqlite3_column_double PROTO :QWORD,:QWORD
sqlite3_column_int64 PROTO :QWORD,:QWORD
sqlite3_column_int PROTO :QWORD,:QWORD
sqlite3_column_name16 PROTO :QWORD,:QWORD
sqlite3_column_name PROTO :QWORD,:QWORD
sqlite3_column_text16 PROTO :QWORD,:QWORD
sqlite3_column_text PROTO :QWORD,:QWORD
sqlite3_column_type PROTO :QWORD,:QWORD
sqlite3_column_value PROTO :QWORD,:QWORD
sqlite3_commit_hook PROTO :QWORD,:QWORD,:QWORD
sqlite3_compileoption_get PROTO :QWORD
sqlite3_compileoption_used PROTO :QWORD
sqlite3_complete16 PROTO :QWORD
sqlite3_complete PROTO :QWORD
sqlite3_config PROTO C :VARARG
sqlite3_context_db_handle PROTO :QWORD
sqlite3_create_collation16 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_create_collation PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_create_collation_v2 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_create_function16 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_create_function PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_create_function_v2 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_create_module PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_create_module_v2 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_data_count PROTO :QWORD
sqlite3_data_directory PROTO C :VARARG
sqlite3_db_cacheflush PROTO :QWORD
sqlite3_db_config PROTO C :VARARG
sqlite3_db_filename PROTO :QWORD,:QWORD
sqlite3_db_handle PROTO :QWORD
sqlite3_db_mutex PROTO :QWORD
sqlite3_db_readonly PROTO :QWORD,:QWORD
sqlite3_db_release_memory PROTO :QWORD
sqlite3_db_status PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_declare_vtab PROTO :QWORD,:QWORD
sqlite3_enable_load_extension PROTO :QWORD,:QWORD
sqlite3_enable_shared_cache PROTO :QWORD
sqlite3_errcode PROTO :QWORD
sqlite3_errmsg16 PROTO :QWORD
sqlite3_errmsg PROTO :QWORD
sqlite3_errstr PROTO :QWORD
sqlite3_exec PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_expanded_sql PROTO :QWORD
sqlite3_expired PROTO :QWORD
sqlite3_extended_errcode PROTO :QWORD
sqlite3_extended_result_codes PROTO :QWORD,:QWORD
sqlite3_file_control PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_finalize PROTO :QWORD
sqlite3_free PROTO :QWORD
sqlite3_free_table PROTO :QWORD
sqlite3_get_autocommit PROTO :QWORD
sqlite3_get_auxdata PROTO :QWORD,:QWORD
sqlite3_get_table PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_global_recover PROTO 
sqlite3_initialize PROTO 
sqlite3_interrupt PROTO :QWORD
sqlite3_last_insert_rowid PROTO :QWORD
sqlite3_libversion PROTO 
sqlite3_libversion_number PROTO 
sqlite3_limit PROTO :QWORD,:QWORD,:QWORD
sqlite3_load_extension PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_log PROTO C :VARARG
sqlite3_malloc64 PROTO :QWORD,:QWORD
sqlite3_malloc PROTO :QWORD
sqlite3_memory_alarm PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_memory_highwater PROTO :QWORD
sqlite3_memory_used PROTO 
sqlite3_mprintf PROTO C :VARARG
sqlite3_msize PROTO :QWORD
sqlite3_mutex_alloc PROTO :QWORD
sqlite3_mutex_enter PROTO :QWORD
sqlite3_mutex_free PROTO :QWORD
sqlite3_mutex_leave PROTO :QWORD
sqlite3_mutex_try PROTO :QWORD
sqlite3_next_stmt PROTO :QWORD,:QWORD
sqlite3_open16 PROTO :QWORD,:QWORD
sqlite3_open PROTO :QWORD,:QWORD
sqlite3_open_v2 PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_os_end PROTO 
sqlite3_os_init PROTO 
sqlite3_overload_function PROTO :QWORD,:QWORD,:QWORD
sqlite3_prepare16 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_prepare16_v2 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_prepare16_v3 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_prepare PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_prepare_v2 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_prepare_v3 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_profile PROTO :QWORD,:QWORD,:QWORD
sqlite3_progress_handler PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_randomness PROTO :QWORD,:QWORD
sqlite3_realloc64 PROTO :QWORD,:QWORD,:QWORD
sqlite3_realloc PROTO :QWORD,:QWORD
sqlite3_release_memory PROTO :QWORD
sqlite3_reset PROTO :QWORD
sqlite3_reset_auto_extension PROTO 
sqlite3_result_blob64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_result_blob PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_result_double PROTO :QWORD,:QWORD,:QWORD
sqlite3_result_error16 PROTO :QWORD,:QWORD,:QWORD
sqlite3_result_error PROTO :QWORD,:QWORD,:QWORD
sqlite3_result_error_code PROTO :QWORD,:QWORD
sqlite3_result_error_nomem PROTO :QWORD
sqlite3_result_error_toobig PROTO :QWORD
sqlite3_result_int64 PROTO :QWORD,:QWORD,:QWORD
sqlite3_result_int PROTO :QWORD,:QWORD
sqlite3_result_null PROTO :QWORD
sqlite3_result_pointer PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_result_subtype PROTO :QWORD,:QWORD
sqlite3_result_text16 PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_result_text16be PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_result_text16le PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_result_text64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_result_text PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_result_value PROTO :QWORD,:QWORD
sqlite3_result_zeroblob64 PROTO :QWORD,:QWORD,:QWORD
sqlite3_result_zeroblob PROTO :QWORD,:QWORD
sqlite3_rollback_hook PROTO :QWORD,:QWORD,:QWORD
sqlite3_set_authorizer PROTO :QWORD,:QWORD,:QWORD
sqlite3_set_auxdata PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_set_last_insert_rowid PROTO :QWORD,:QWORD,:QWORD
sqlite3_shutdown PROTO 
sqlite3_sleep PROTO :QWORD
sqlite3_snprintf PROTO C :VARARG
sqlite3_soft_heap_limit64 PROTO :QWORD,:QWORD
sqlite3_soft_heap_limit PROTO :QWORD
sqlite3_sourceid PROTO 
sqlite3_sql PROTO :QWORD
sqlite3_status64 PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_status PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_step PROTO :QWORD
sqlite3_stmt_busy PROTO :QWORD
sqlite3_stmt_readonly PROTO :QWORD
sqlite3_stmt_status PROTO :QWORD,:QWORD,:QWORD
sqlite3_strglob PROTO :QWORD,:QWORD
sqlite3_stricmp PROTO :QWORD,:QWORD
sqlite3_strlike PROTO :QWORD,:QWORD,:QWORD
sqlite3_strnicmp PROTO :QWORD,:QWORD,:QWORD
sqlite3_system_errno PROTO :QWORD
sqlite3_table_column_metadata PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_temp_directory PROTO C :VARARG
sqlite3_test_control PROTO C :VARARG
sqlite3_thread_cleanup PROTO 
sqlite3_threadsafe PROTO 
sqlite3_total_changes PROTO :QWORD
sqlite3_trace PROTO :QWORD,:QWORD,:QWORD
sqlite3_trace_v2 PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_transfer_bindings PROTO :QWORD,:QWORD
sqlite3_update_hook PROTO :QWORD,:QWORD,:QWORD
sqlite3_uri_boolean PROTO :QWORD,:QWORD,:QWORD
sqlite3_uri_int64 PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_uri_parameter PROTO :QWORD,:QWORD
sqlite3_user_data PROTO :QWORD
sqlite3_value_blob PROTO :QWORD
sqlite3_value_bytes16 PROTO :QWORD
sqlite3_value_bytes PROTO :QWORD
sqlite3_value_double PROTO :QWORD
sqlite3_value_dup PROTO :QWORD
sqlite3_value_free PROTO :QWORD
sqlite3_value_int64 PROTO :QWORD
sqlite3_value_int PROTO :QWORD
sqlite3_value_numeric_type PROTO :QWORD
sqlite3_value_pointer PROTO :QWORD,:QWORD
sqlite3_value_subtype PROTO :QWORD
sqlite3_value_text16 PROTO :QWORD
sqlite3_value_text16be PROTO :QWORD
sqlite3_value_text16le PROTO :QWORD
sqlite3_value_text PROTO :QWORD
sqlite3_value_type PROTO :QWORD
sqlite3_version PROTO C :VARARG
sqlite3_vfs_find PROTO :QWORD
sqlite3_vfs_register PROTO :QWORD,:QWORD
sqlite3_vfs_unregister PROTO :QWORD
sqlite3_vmprintf PROTO :QWORD,:QWORD
sqlite3_vsnprintf PROTO :QWORD,:QWORD,:QWORD,:QWORD
sqlite3_vtab_config PROTO C :VARARG
sqlite3_vtab_on_conflict PROTO :QWORD
sqlite3_wal_autocheckpoint PROTO :QWORD,:QWORD
sqlite3_wal_checkpoint PROTO :QWORD,:QWORD
sqlite3_wal_checkpoint_v2 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
sqlite3_wal_hook PROTO :QWORD,:QWORD,:QWORD
sqlite3_win32_is_nt PROTO 
sqlite3_win32_mbcs_to_utf8 PROTO :QWORD
sqlite3_win32_mbcs_to_utf8_v2 PROTO :QWORD,:QWORD
sqlite3_win32_set_directory PROTO :QWORD,:QWORD
sqlite3_win32_sleep PROTO :QWORD
sqlite3_win32_unicode_to_utf8 PROTO :QWORD
sqlite3_win32_utf8_to_mbcs PROTO :QWORD
sqlite3_win32_utf8_to_mbcs_v2 PROTO :QWORD,:QWORD
sqlite3_win32_utf8_to_unicode PROTO :QWORD
sqlite3_win32_write_debug PROTO :QWORD,:QWORD

SQLITE_INTEGER              EQU 1   ; data types
SQLITE_FLOAT                EQU 2
SQLITE_TEXT                 EQU 3
SQLITE3_TEXT                EQU 3
SQLITE_BLOB                 EQU 4
SQLITE_NULL                 EQU 5

SQLITE_OK                   EQU 0   ;  Successful result 
SQLITE_ERROR                EQU 1   ;  SQL error or missing database 
SQLITE_INTERNAL             EQU 2   ;  NOT USED. Internal logic error in SQLite 
SQLITE_PERM                 EQU 3   ;  Access permission denied 
SQLITE_ABORT                EQU 4   ;  Callback routine requested an abort 
SQLITE_BUSY                 EQU 5   ;  The database file is locked 
SQLITE_LOCKED               EQU 6   ;  A table in the database is locked 
SQLITE_NOMEM                EQU 7   ;  A malloc() failed 
SQLITE_READONLY             EQU 8   ;  Attempt to write a readonly database 
SQLITE_INTERRUPT            EQU 9   ;  Operation terminated by sqlite3_interrupt()*/
SQLITE_IOERR                EQU 10  ;  Some kind of disk I/O error occurred 
SQLITE_IOERR_READ           EQU (10 or (1*256)) ; (SQLITE_IOERR | (1<<8))
SQLITE_IOERR_SHORT_READ     EQU (10 or (2*256))
SQLITE_IOERR_WRITE          EQU (10 or (3*256))
SQLITE_IOERR_FSYNC          EQU (10 or (4*256))
SQLITE_IOERR_DIR_FSYNC      EQU (10 or (5*256))
SQLITE_IOERR_TRUNCATE       EQU (10 or (6*256))
SQLITE_IOERR_FSTAT          EQU (10 or (7*256))
SQLITE_IOERR_UNLOCK         EQU (10 or (8*256))
SQLITE_IOERR_RDLOCK         EQU (10 or (9*256))
SQLITE_IOERR_DELETE         EQU (10 or (10*256))
SQLITE_IOERR_BLOCKED        EQU (10 or (11*256))
SQLITE_CORRUPT              EQU 11  ;  The database disk image is malformed 
SQLITE_NOTFOUND             EQU 12  ;  NOT USED. Table or record not found 
SQLITE_FULL                 EQU 13  ;  Insertion failed because database is full 
SQLITE_CANTOPEN             EQU 14  ;  Unable to open the database file 
SQLITE_PROTOCOL             EQU 15  ;  NOT USED. Database lock protocol error 
SQLITE_EMPTY                EQU 16  ;  Database is empty 
SQLITE_SCHEMA               EQU 17  ;  The database schema changed 
SQLITE_TOOBIG               EQU 18  ;  String or BLOB exceeds size limit 
SQLITE_CONSTRAINT           EQU 19  ;  Abort due to contraint violation 
SQLITE_MISMATCH             EQU 20  ;  Data type mismatch 
SQLITE_MISUSE               EQU 21  ;  Library used incorrectly 
SQLITE_NOLFS                EQU 22  ;  Uses OS features not supported on host 
SQLITE_AUTH                 EQU 23  ;  Authorization denied 
SQLITE_FORMAT               EQU 24  ;  Auxiliary database format error 
SQLITE_RANGE                EQU 25  ;  2nd parameter to sqlite3_bind out of range 
SQLITE_NOTADB               EQU 26  ;  File opened that is not a database file 
SQLITE_ROW                  EQU 100 ;  sqlite3_step() has another row ready 
SQLITE_DONE                 EQU 101 ;  sqlite3_step() has finished executing 

SQLITE_COPY                 EQU 0   ;  Table Name      File Name       
SQLITE_CREATE_INDEX         EQU 1   ;  Index Name      Table Name      
SQLITE_CREATE_TABLE         EQU 2   ;  Table Name      NULL            
SQLITE_CREATE_TEMP_INDEX    EQU 3   ;  Index Name      Table Name      
SQLITE_CREATE_TEMP_TABLE    EQU 4   ;  Table Name      NULL            
SQLITE_CREATE_TEMP_TRIGGER  EQU 5   ;  Trigger Name    Table Name      
SQLITE_CREATE_TEMP_VIEW     EQU 6   ;  View Name       NULL            
SQLITE_CREATE_TRIGGER       EQU 7   ;  Trigger Name    Table Name      
SQLITE_CREATE_VIEW          EQU 8   ;  View Name       NULL            
SQLITE_DELETE               EQU 9   ;  Table Name      NULL            
SQLITE_DROP_INDEX           EQU 10  ;  Index Name      Table Name      
SQLITE_DROP_TABLE           EQU 11  ;  Table Name      NULL            
SQLITE_DROP_TEMP_INDEX      EQU 12  ;  Index Name      Table Name      
SQLITE_DROP_TEMP_TABLE      EQU 13  ;  Table Name      NULL            
SQLITE_DROP_TEMP_TRIGGER    EQU 14  ;  Trigger Name    Table Name      
SQLITE_DROP_TEMP_VIEW       EQU 15  ;  View Name       NULL            
SQLITE_DROP_TRIGGER         EQU 16  ;  Trigger Name    Table Name      
SQLITE_DROP_VIEW            EQU 17  ;  View Name       NULL            
SQLITE_INSERT               EQU 18  ;  Table Name      NULL            
SQLITE_PRAGMA               EQU 19  ;  Pragma Name     1st arg or NULL 
SQLITE_READ                 EQU 20  ;  Table Name      Column Name     
SQLITE_SELECT               EQU 21  ;  NULL            NULL            
SQLITE_TRANSACTION          EQU 22  ;  NULL            NULL            
SQLITE_UPDATE               EQU 23  ;  Table Name      Column Name     
SQLITE_ATTACH               EQU 24  ;  Filename        NULL            
SQLITE_DETACH               EQU 25  ;  Database Name   NULL            
SQLITE_ALTER_TABLE          EQU 26  ;  Database Name   Table Name      
SQLITE_REINDEX              EQU 27  ;  Index Name      NULL            
SQLITE_ANALYZE              EQU 28  ;  Table Name      NULL            
SQLITE_CREATE_VTABLE        EQU 29  ;  Table Name      Module Name     
SQLITE_DROP_VTABLE          EQU 30  ;  Table Name      Module Name     
SQLITE_FUNCTION             EQU 31  ;  Function Name   NULL            
SQLITE_COPY                 EQU 0   ;  No longer used 

SQLITE_DENY                 EQU 1   ;  Abort the SQL statement with an error 
SQLITE_IGNORE               EQU 2   ;  Don't allow access, but don't generate an error 

SQLITE_UTF8                 EQU 1   ; supported text encodings
SQLITE_UTF16LE              EQU 2
SQLITE_UTF16BE              EQU 3
SQLITE_UTF16                EQU 4   ;  Use native byte order 
SQLITE_ANY                  EQU 5   ;  sqlite3_create_function only 
SQLITE_UTF16_ALIGNED        EQU 8   ;  sqlite3_create_collation only 

SQLITE3_INDEX_CONSTRAINT    STRUCT 
    iColumnl                DQ ?    ; Column on left-hand side of constraint 
    op                      DQ ?    ; Constraint operator 
    usable                  DQ ?    ; True if this constraint is usable 
    iTermOffset             DQ ?    ; Used internally - xBestIndex should ignore 
SQLITE3_INDEX_CONSTRAINT    ENDS

SQLITE3_INDEX_ORDERBY       STRUCT 
    iColumn                 DQ ?    ; Column number 
    desc                    DQ ?    ; True for DESC.  False for ASC. 
SQLITE3_INDEX_ORDERBY       ENDS

SQLITE3_INDEX_CONSTRAINT_USAGE STRUCT 
    argvIndex               DQ ?    ; if >0, constraint is part of argv to xFilter 
    omit                    DQ ?    ; Do not code a test for this constraint 
SQLITE3_INDEX_CONSTRAINT_USAGE ENDS

SQLITE3_INDEX_INFO          STRUCT 
    nConstraint             DQ ?    ; Number of entries in aConstraint 
    SQLITE3_INDEX_CONSTRAINT <>
    nOrderBy                DQ ?    ; Number of terms in the ORDER BY clause 
    SQLITE3_INDEX_ORDERBY <>
    SQLITE3_INDEX_CONSTRAINT_USAGE <>
    idxNum                  DQ ?    ; Number used to identify the index 
    idxStr                  DQ ?    ; String, possibly obtained from sqlite3_malloc 
    needToFreeIdxStr        DQ ?    ; Free idxStr using sqlite3_free() if true 
    orderByConsumed         DQ ?    ; True if output is already ordered 
    estimatedCost           DQ ?    ; Estimated cost of using this index 
SQLITE3_INDEX_INFO          ENDS

SQLITE_INDEX_CONSTRAINT_EQ    EQU 2
SQLITE_INDEX_CONSTRAINT_GT    EQU 4
SQLITE_INDEX_CONSTRAINT_LE    EQU 8
SQLITE_INDEX_CONSTRAINT_LT    EQU 16
SQLITE_INDEX_CONSTRAINT_GE    EQU 32
SQLITE_INDEX_CONSTRAINT_MATCH EQU 64

SQLITE_STATIC               EQU 0
SQLITE_TRANSIENT            EQU -1

SQLITE3_MODULE              STRUCT 
    iVersion                DQ ?
    xCreate                 DQ ?    ; (sqlite3*,pAux,argc,argv,ppVTab,char*)
    xConnect                DQ ?    ; (sqlite3*,pAux,argc,argv,ppVTab,char*)
    xBestIndex              DQ ?    ; (pVTab,sqlite3_index_info*)
    xDisconnect             DQ ?    ; (pVTab)
    xDestroy                DQ ?    ; (pVTab)
    xOpen                   DQ ?    ; (pVTab,ppCursor)
    xClose                  DQ ?    ; (sqlite3_vtab_cursor*)
    xFilter                 DQ ?    ; (sqlite3_vtab_cursor*,idxNum,idxStr,argc,argv)
    xNext                   DQ ?    ; (sqlite3_vtab_cursor*)
    xEof                    DQ ?    ; (sqlite3_vtab_cursor*)
    xColumn                 DQ ?    ; (sqlite3_vtab_cursor*,sqlite3_context*,int)
    xRowid                  DQ ?    ; (sqlite3_vtab_cursor*,pRowid)
    xUpdate                 DQ ?    ; (sqlite3_vtab*,int,sqlite3_value*,sqlite_int64*)
    xBegin                  DQ ?    ; (pVTab)
    xSync                   DQ ?    ; (pVTab)
    xCommit                 DQ ?    ; (pVTab)
    xRollback               DQ ?    ; (pVTab)
    xFindFunction           DQ ?    ; (pVtab,nArg,zName,pxFunc,ppArg)
    xRename                 DQ ?    ; (pVtab,zNew)
SQLITE3_MODULE              ENDS

SQLITE3_VFS                 STRUCT
	iVersion 		        DQ ?    ; Structure version number 
	szOsFile 		        DQ ?    ; Size of subclassed sqlite3_file 
	mxPathname 		        DQ ?    ; Maximum file pathname length 
	pNext 			        DQ ?    ; Next registered VFS 
	zName 			        DQ ?    ; Name of this virtual file system 
	pAppData 		        DQ ?    ; Pointer to application-specific data 
	func1 			        DQ ?
	func2 			        DQ ?
	func3 			        DQ ?
	func4 			        DQ ?
	func5 			        DQ ?
	func6 			        DQ ?
	func7 			        DQ ?
	func8 			        DQ ?
	func9 			        DQ ?
	func10 			        DQ ?
	func11 			        DQ ?
	func12 			        DQ ?
SQLITE3_VFS                 ENDS














