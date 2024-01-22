
sqlite3_aggregate_context PROTO STDCALL :DWORD,:DWORD
sqlite3_aggregate_count PROTO STDCALL :DWORD
sqlite3_auto_extension PROTO STDCALL :DWORD
sqlite3_autovacuum_pages PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_backup_finish PROTO STDCALL :DWORD
sqlite3_backup_init PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_backup_pagecount PROTO STDCALL :DWORD
sqlite3_backup_remaining PROTO STDCALL :DWORD
sqlite3_backup_step PROTO STDCALL :DWORD,:DWORD
sqlite3_bind_blob64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_bind_blob PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_bind_double PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_bind_int64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_bind_int PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_bind_null PROTO STDCALL :DWORD,:DWORD
sqlite3_bind_parameter_count PROTO STDCALL :DWORD
sqlite3_bind_parameter_index PROTO STDCALL :DWORD,:DWORD
sqlite3_bind_parameter_name PROTO STDCALL :DWORD,:DWORD
sqlite3_bind_pointer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_bind_text16 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_bind_text64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_bind_text PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_bind_value PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_bind_zeroblob64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_bind_zeroblob PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_blob_bytes PROTO STDCALL :DWORD
sqlite3_blob_close PROTO STDCALL :DWORD
sqlite3_blob_open PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_blob_read PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_blob_reopen PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_blob_write PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_busy_handler PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_busy_timeout PROTO STDCALL :DWORD,:DWORD
sqlite3_cancel_auto_extension PROTO STDCALL :DWORD
sqlite3_changes64 PROTO STDCALL :DWORD
sqlite3_changes PROTO STDCALL :DWORD
sqlite3_clear_bindings PROTO STDCALL :DWORD
sqlite3_close PROTO STDCALL :DWORD
sqlite3_close_v2 PROTO STDCALL :DWORD
sqlite3_collation_needed16 PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_collation_needed PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_column_blob PROTO STDCALL :DWORD,:DWORD
sqlite3_column_bytes16 PROTO STDCALL :DWORD,:DWORD
sqlite3_column_bytes PROTO STDCALL :DWORD,:DWORD
sqlite3_column_count PROTO STDCALL :DWORD
sqlite3_column_decltype16 PROTO STDCALL :DWORD,:DWORD
sqlite3_column_decltype PROTO STDCALL :DWORD,:DWORD
sqlite3_column_double PROTO STDCALL :DWORD,:DWORD
sqlite3_column_int64 PROTO STDCALL :DWORD,:DWORD
sqlite3_column_int PROTO STDCALL :DWORD,:DWORD
sqlite3_column_name16 PROTO STDCALL :DWORD,:DWORD
sqlite3_column_name PROTO STDCALL :DWORD,:DWORD
sqlite3_column_text16 PROTO STDCALL :DWORD,:DWORD
sqlite3_column_text PROTO STDCALL :DWORD,:DWORD
sqlite3_column_type PROTO STDCALL :DWORD,:DWORD
sqlite3_column_value PROTO STDCALL :DWORD,:DWORD
sqlite3_commit_hook PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_compileoption_get PROTO STDCALL :DWORD
sqlite3_compileoption_used PROTO STDCALL :DWORD
sqlite3_complete16 PROTO STDCALL :DWORD
sqlite3_complete PROTO STDCALL :DWORD
sqlite3_config PROTO C :VARARG
sqlite3_context_db_handle PROTO STDCALL :DWORD
sqlite3_create_collation16 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_create_collation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_create_collation_v2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_create_filename PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_create_function16 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_create_function PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_create_function_v2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_create_module PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_create_module_v2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_create_window_function PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_data_count PROTO STDCALL :DWORD
sqlite3_data_directory PROTO C :VARARG
sqlite3_database_file_object PROTO STDCALL :DWORD
sqlite3_db_cacheflush PROTO STDCALL :DWORD
sqlite3_db_config PROTO C :VARARG
sqlite3_db_filename PROTO STDCALL :DWORD,:DWORD
sqlite3_db_handle PROTO STDCALL :DWORD
sqlite3_db_mutex PROTO STDCALL :DWORD
sqlite3_db_name PROTO STDCALL :DWORD,:DWORD
sqlite3_db_readonly PROTO STDCALL :DWORD,:DWORD
sqlite3_db_release_memory PROTO STDCALL :DWORD
sqlite3_db_status PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_declare_vtab PROTO STDCALL :DWORD,:DWORD
sqlite3_deserialize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_drop_modules PROTO STDCALL :DWORD,:DWORD
sqlite3_enable_load_extension PROTO STDCALL :DWORD,:DWORD
sqlite3_enable_shared_cache PROTO STDCALL :DWORD
sqlite3_errcode PROTO STDCALL :DWORD
sqlite3_errmsg16 PROTO STDCALL :DWORD
sqlite3_errmsg PROTO STDCALL :DWORD
sqlite3_error_offset PROTO STDCALL :DWORD
sqlite3_errstr PROTO STDCALL :DWORD
sqlite3_exec PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_expanded_sql PROTO STDCALL :DWORD
sqlite3_expired PROTO STDCALL :DWORD
sqlite3_extended_errcode PROTO STDCALL :DWORD
sqlite3_extended_result_codes PROTO STDCALL :DWORD,:DWORD
sqlite3_file_control PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_filename_database PROTO STDCALL :DWORD
sqlite3_filename_journal PROTO STDCALL :DWORD
sqlite3_filename_wal PROTO STDCALL :DWORD
sqlite3_finalize PROTO STDCALL :DWORD
sqlite3_free PROTO STDCALL :DWORD
sqlite3_free_filename PROTO STDCALL :DWORD
sqlite3_free_table PROTO STDCALL :DWORD
sqlite3_get_autocommit PROTO STDCALL :DWORD
sqlite3_get_auxdata PROTO STDCALL :DWORD,:DWORD
sqlite3_get_clientdata PROTO STDCALL :DWORD,:DWORD
sqlite3_get_table PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_global_recover PROTO STDCALL 
sqlite3_hard_heap_limit64 PROTO STDCALL :DWORD,:DWORD
sqlite3_initialize PROTO STDCALL 
sqlite3_interrupt PROTO STDCALL :DWORD
sqlite3_is_interrupted PROTO STDCALL :DWORD
sqlite3_keyword_check PROTO STDCALL :DWORD,:DWORD
sqlite3_keyword_count PROTO STDCALL 
sqlite3_keyword_name PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_last_insert_rowid PROTO STDCALL :DWORD
sqlite3_libversion PROTO STDCALL 
sqlite3_libversion_number PROTO STDCALL 
sqlite3_limit PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_load_extension PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_log PROTO C :VARARG
sqlite3_malloc64 PROTO STDCALL :DWORD,:DWORD
sqlite3_malloc PROTO STDCALL :DWORD
sqlite3_memory_alarm PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_memory_highwater PROTO STDCALL :DWORD
sqlite3_memory_used PROTO STDCALL 
sqlite3_mprintf PROTO C :VARARG
sqlite3_msize PROTO STDCALL :DWORD
sqlite3_mutex_alloc PROTO STDCALL :DWORD
sqlite3_mutex_enter PROTO STDCALL :DWORD
sqlite3_mutex_free PROTO STDCALL :DWORD
sqlite3_mutex_leave PROTO STDCALL :DWORD
sqlite3_mutex_try PROTO STDCALL :DWORD
sqlite3_next_stmt PROTO STDCALL :DWORD,:DWORD
sqlite3_open16 PROTO STDCALL :DWORD,:DWORD
sqlite3_open PROTO STDCALL :DWORD,:DWORD
sqlite3_open_v2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_os_end PROTO STDCALL 
sqlite3_os_init PROTO STDCALL 
sqlite3_overload_function PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_prepare16 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_prepare16_v2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_prepare16_v3 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_prepare PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_prepare_v2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_prepare_v3 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_profile PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_progress_handler PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_randomness PROTO STDCALL :DWORD,:DWORD
sqlite3_realloc64 PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_realloc PROTO STDCALL :DWORD,:DWORD
sqlite3_release_memory PROTO STDCALL :DWORD
sqlite3_reset PROTO STDCALL :DWORD
sqlite3_reset_auto_extension PROTO STDCALL 
sqlite3_result_blob64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_result_blob PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_result_double PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_result_error16 PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_result_error PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_result_error_code PROTO STDCALL :DWORD,:DWORD
sqlite3_result_error_nomem PROTO STDCALL :DWORD
sqlite3_result_error_toobig PROTO STDCALL :DWORD
sqlite3_result_int64 PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_result_int PROTO STDCALL :DWORD,:DWORD
sqlite3_result_null PROTO STDCALL :DWORD
sqlite3_result_pointer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_result_subtype PROTO STDCALL :DWORD,:DWORD
sqlite3_result_text16 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_result_text16be PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_result_text16le PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_result_text64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_result_text PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_result_value PROTO STDCALL :DWORD,:DWORD
sqlite3_result_zeroblob64 PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_result_zeroblob PROTO STDCALL :DWORD,:DWORD
sqlite3_rollback_hook PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_serialize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_set_authorizer PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_set_auxdata PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_set_clientdata PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_set_last_insert_rowid PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_shutdown PROTO STDCALL 
sqlite3_sleep PROTO STDCALL :DWORD
sqlite3_snprintf PROTO C :VARARG
sqlite3_soft_heap_limit64 PROTO STDCALL :DWORD,:DWORD
sqlite3_soft_heap_limit PROTO STDCALL :DWORD
sqlite3_sourceid PROTO STDCALL 
sqlite3_sql PROTO STDCALL :DWORD
sqlite3_status64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_status PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_step PROTO STDCALL :DWORD
sqlite3_stmt_busy PROTO STDCALL :DWORD
sqlite3_stmt_explain PROTO STDCALL :DWORD,:DWORD
sqlite3_stmt_isexplain PROTO STDCALL :DWORD
sqlite3_stmt_readonly PROTO STDCALL :DWORD
sqlite3_stmt_status PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_str_append PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_str_appendall PROTO STDCALL :DWORD,:DWORD
sqlite3_str_appendchar PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_str_appendf PROTO C :VARARG
sqlite3_str_errcode PROTO STDCALL :DWORD
sqlite3_str_finish PROTO STDCALL :DWORD
sqlite3_str_length PROTO STDCALL :DWORD
sqlite3_str_new PROTO STDCALL :DWORD
sqlite3_str_reset PROTO STDCALL :DWORD
sqlite3_str_value PROTO STDCALL :DWORD
sqlite3_str_vappendf PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_strglob PROTO STDCALL :DWORD,:DWORD
sqlite3_stricmp PROTO STDCALL :DWORD,:DWORD
sqlite3_strlike PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_strnicmp PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_system_errno PROTO STDCALL :DWORD
sqlite3_table_column_metadata PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_temp_directory PROTO C :VARARG
sqlite3_test_control PROTO C :VARARG
sqlite3_thread_cleanup PROTO STDCALL 
sqlite3_threadsafe PROTO STDCALL 
sqlite3_total_changes64 PROTO STDCALL :DWORD
sqlite3_total_changes PROTO STDCALL :DWORD
sqlite3_trace PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_trace_v2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_transfer_bindings PROTO STDCALL :DWORD,:DWORD
sqlite3_txn_state PROTO STDCALL :DWORD,:DWORD
sqlite3_update_hook PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_uri_boolean PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_uri_int64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_uri_key PROTO STDCALL :DWORD,:DWORD
sqlite3_uri_parameter PROTO STDCALL :DWORD,:DWORD
sqlite3_user_data PROTO STDCALL :DWORD
sqlite3_value_blob PROTO STDCALL :DWORD
sqlite3_value_bytes16 PROTO STDCALL :DWORD
sqlite3_value_bytes PROTO STDCALL :DWORD
sqlite3_value_double PROTO STDCALL :DWORD
sqlite3_value_dup PROTO STDCALL :DWORD
sqlite3_value_encoding PROTO STDCALL :DWORD
sqlite3_value_free PROTO STDCALL :DWORD
sqlite3_value_frombind PROTO STDCALL :DWORD
sqlite3_value_int64 PROTO STDCALL :DWORD
sqlite3_value_int PROTO STDCALL :DWORD
sqlite3_value_nochange PROTO STDCALL :DWORD
sqlite3_value_numeric_type PROTO STDCALL :DWORD
sqlite3_value_pointer PROTO STDCALL :DWORD,:DWORD
sqlite3_value_subtype PROTO STDCALL :DWORD
sqlite3_value_text16 PROTO STDCALL :DWORD
sqlite3_value_text16be PROTO STDCALL :DWORD
sqlite3_value_text16le PROTO STDCALL :DWORD
sqlite3_value_text PROTO STDCALL :DWORD
sqlite3_value_type PROTO STDCALL :DWORD
sqlite3_version PROTO C :VARARG
sqlite3_vfs_find PROTO STDCALL :DWORD
sqlite3_vfs_register PROTO STDCALL :DWORD,:DWORD
sqlite3_vfs_unregister PROTO STDCALL :DWORD
sqlite3_vmprintf PROTO STDCALL :DWORD,:DWORD
sqlite3_vsnprintf PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
sqlite3_vtab_collation PROTO STDCALL :DWORD,:DWORD
sqlite3_vtab_config PROTO C :VARARG
sqlite3_vtab_distinct PROTO STDCALL :DWORD
sqlite3_vtab_in PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_vtab_in_first PROTO STDCALL :DWORD,:DWORD
sqlite3_vtab_in_next PROTO STDCALL :DWORD,:DWORD
sqlite3_vtab_nochange PROTO STDCALL :DWORD
sqlite3_vtab_on_conflict PROTO STDCALL :DWORD
sqlite3_vtab_rhs_value PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_wal_autocheckpoint PROTO STDCALL :DWORD,:DWORD
sqlite3_wal_checkpoint PROTO STDCALL :DWORD,:DWORD
sqlite3_wal_checkpoint_v2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlite3_wal_hook PROTO STDCALL :DWORD,:DWORD,:DWORD
sqlite3_win32_is_nt PROTO STDCALL 
sqlite3_win32_mbcs_to_utf8 PROTO STDCALL :DWORD
sqlite3_win32_mbcs_to_utf8_v2 PROTO STDCALL :DWORD,:DWORD
sqlite3_win32_set_directory16 PROTO STDCALL :DWORD,:DWORD
sqlite3_win32_set_directory8 PROTO STDCALL :DWORD,:DWORD
sqlite3_win32_set_directory PROTO STDCALL :DWORD,:DWORD
sqlite3_win32_sleep PROTO STDCALL :DWORD
sqlite3_win32_unicode_to_utf8 PROTO STDCALL :DWORD
sqlite3_win32_utf8_to_mbcs PROTO STDCALL :DWORD
sqlite3_win32_utf8_to_mbcs_v2 PROTO STDCALL :DWORD,:DWORD
sqlite3_win32_utf8_to_unicode PROTO STDCALL :DWORD
sqlite3_win32_write_debug PROTO STDCALL :DWORD,:DWORD

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
    iColumnl                DD ?    ; Column on left-hand side of constraint 
    op                      DD ?    ; Constraint operator 
    usable                  DD ?    ; True if this constraint is usable 
    iTermOffset             DD ?    ; Used internally - xBestIndex should ignore 
SQLITE3_INDEX_CONSTRAINT    ENDS

SQLITE3_INDEX_ORDERBY       STRUCT 
    iColumn                 DD ?    ; Column number 
    desc                    DD ?    ; True for DESC.  False for ASC. 
SQLITE3_INDEX_ORDERBY       ENDS

SQLITE3_INDEX_CONSTRAINT_USAGE STRUCT 
    argvIndex               DD ?    ; if >0, constraint is part of argv to xFilter 
    omit                    DD ?    ; Do not code a test for this constraint 
SQLITE3_INDEX_CONSTRAINT_USAGE ENDS

SQLITE3_INDEX_INFO          STRUCT 
    nConstraint             DD ?    ; Number of entries in aConstraint 
    SQLITE3_INDEX_CONSTRAINT <>
    nOrderBy                DD ?    ; Number of terms in the ORDER BY clause 
    SQLITE3_INDEX_ORDERBY <>
    SQLITE3_INDEX_CONSTRAINT_USAGE <>
    idxNum                  DD ?    ; Number used to identify the index 
    idxStr                  DD ?    ; String, possibly obtained from sqlite3_malloc 
    needToFreeIdxStr        DD ?    ; Free idxStr using sqlite3_free() if true 
    orderByConsumed         DD ?    ; True if output is already ordered 
    estimatedCost           DD ?    ; Estimated cost of using this index 
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
    iVersion                DD ?
    xCreate                 DD ?    ; (sqlite3*,pAux,argc,argv,ppVTab,char*)
    xConnect                DD ?    ; (sqlite3*,pAux,argc,argv,ppVTab,char*)
    xBestIndex              DD ?    ; (pVTab,sqlite3_index_info*)
    xDisconnect             DD ?    ; (pVTab)
    xDestroy                DD ?    ; (pVTab)
    xOpen                   DD ?    ; (pVTab,ppCursor)
    xClose                  DD ?    ; (sqlite3_vtab_cursor*)
    xFilter                 DD ?    ; (sqlite3_vtab_cursor*,idxNum,idxStr,argc,argv)
    xNext                   DD ?    ; (sqlite3_vtab_cursor*)
    xEof                    DD ?    ; (sqlite3_vtab_cursor*)
    xColumn                 DD ?    ; (sqlite3_vtab_cursor*,sqlite3_context*,int)
    xRowid                  DD ?    ; (sqlite3_vtab_cursor*,pRowid)
    xUpdate                 DD ?    ; (sqlite3_vtab*,int,sqlite3_value*,sqlite_int64*)
    xBegin                  DD ?    ; (pVTab)
    xSync                   DD ?    ; (pVTab)
    xCommit                 DD ?    ; (pVTab)
    xRollback               DD ?    ; (pVTab)
    xFindFunction           DD ?    ; (pVtab,nArg,zName,pxFunc,ppArg)
    xRename                 DD ?    ; (pVtab,zNew)
SQLITE3_MODULE              ENDS

SQLITE3_VFS                 STRUCT
	iVersion 		        DD ?    ; Structure version number 
	szOsFile 		        DD ?    ; Size of subclassed sqlite3_file 
	mxPathname 		        DD ?    ; Maximum file pathname length 
	pNext 			        DD ?    ; Next registered VFS 
	zName 			        DD ?    ; Name of this virtual file system 
	pAppData 		        DD ?    ; Pointer to application-specific data 
	func1 			        DD ?
	func2 			        DD ?
	func3 			        DD ?
	func4 			        DD ?
	func5 			        DD ?
	func6 			        DD ?
	func7 			        DD ?
	func8 			        DD ?
	func9 			        DD ?
	func10 			        DD ?
	func11 			        DD ?
	func12 			        DD ?
SQLITE3_VFS                 ENDS














