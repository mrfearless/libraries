; https://sourceforge.net/projects/luabinaries/files/5.3.5/Windows%20Libraries/Static/
; lua-5.3.5_Win32_vc12_lib.zip

luaC_barrier_ PROTO C :VARARG
luaC_barrierback_ PROTO C :VARARG
luaC_checkfinalizer PROTO C :VARARG
luaC_fix PROTO C :VARARG
luaC_freeallobjects PROTO C :VARARG
luaC_fullgc PROTO C :VARARG
luaC_newobj PROTO C :VARARG
luaC_runtilstate PROTO C :VARARG
luaC_step PROTO C :VARARG
luaC_upvalbarrier_ PROTO C :VARARG
luaC_upvdeccount PROTO C :VARARG
luaD_call PROTO C :VARARG
luaD_callnoyield PROTO C :VARARG
luaD_growstack PROTO C :VARARG
luaD_hook PROTO C :VARARG
luaD_inctop PROTO C :VARARG
luaD_pcall PROTO C :VARARG
luaD_poscall PROTO C :VARARG
luaD_precall PROTO C :VARARG
luaD_protectedparser PROTO C :VARARG
luaD_rawrunprotected PROTO C :VARARG
luaD_reallocstack PROTO C :VARARG
luaD_shrinkstack PROTO C :VARARG
luaD_throw PROTO C :VARARG
luaE_extendCI PROTO C :VARARG
luaE_freeCI PROTO C :VARARG
luaE_freethread PROTO C :VARARG
luaE_setdebt PROTO C :VARARG
luaE_shrinkCI PROTO C :VARARG
luaF_close PROTO C :VARARG
luaF_findupval PROTO C :VARARG
luaF_freeproto PROTO C :VARARG
luaF_getlocalname PROTO C :VARARG
luaF_initupvals PROTO C :VARARG
luaF_newCclosure PROTO C :VARARG
luaF_newLclosure PROTO C :VARARG
luaF_newproto PROTO C :VARARG
luaG_addinfo PROTO C :VARARG
luaG_concaterror PROTO C :VARARG
luaG_errormsg PROTO C :VARARG
luaG_opinterror PROTO C :VARARG
luaG_ordererror PROTO C :VARARG
luaG_runerror PROTO C :VARARG
luaG_tointerror PROTO C :VARARG
luaG_traceexec PROTO C :VARARG
luaG_typeerror PROTO C :VARARG
luaH_free PROTO C :VARARG
luaH_get PROTO C :VARARG
luaH_getint PROTO C :VARARG
luaH_getn PROTO C :VARARG
luaH_getshortstr PROTO C :VARARG
luaH_getstr PROTO C :VARARG
luaH_new PROTO C :VARARG
luaH_newkey PROTO C :VARARG
luaH_next PROTO C :VARARG
luaH_resize PROTO C :VARARG
luaH_resizearray PROTO C :VARARG
luaH_set PROTO C :VARARG
luaH_setint PROTO C :VARARG
luaK_checkstack PROTO C :VARARG
luaK_codeABC PROTO C :VARARG
luaK_codeABx PROTO C :VARARG
luaK_codek PROTO C :VARARG
luaK_concat PROTO C :VARARG
luaK_dischargevars PROTO C :VARARG
luaK_exp2RK PROTO C :VARARG
luaK_exp2anyreg PROTO C :VARARG
luaK_exp2anyregup PROTO C :VARARG
luaK_exp2nextreg PROTO C :VARARG
luaK_exp2val PROTO C :VARARG
luaK_fixline PROTO C :VARARG
luaK_getlabel PROTO C :VARARG
luaK_goiffalse PROTO C :VARARG
luaK_goiftrue PROTO C :VARARG
luaK_indexed PROTO C :VARARG
luaK_infix PROTO C :VARARG
luaK_intK PROTO C :VARARG
luaK_jump PROTO C :VARARG
luaK_nil PROTO C :VARARG
luaK_patchclose PROTO C :VARARG
luaK_patchlist PROTO C :VARARG
luaK_patchtohere PROTO C :VARARG
luaK_posfix PROTO C :VARARG
luaK_prefix PROTO C :VARARG
luaK_reserveregs PROTO C :VARARG
luaK_ret PROTO C :VARARG
luaK_self PROTO C :VARARG
luaK_setlist PROTO C :VARARG
luaK_setoneret PROTO C :VARARG
luaK_setreturns PROTO C :VARARG
luaK_storevar PROTO C :VARARG
luaK_stringK PROTO C :VARARG
luaL_addlstring PROTO C :VARARG
luaL_addstring PROTO C :VARARG
luaL_addvalue PROTO C :VARARG
luaL_argerror PROTO C :VARARG
luaL_buffinit PROTO C :VARARG
luaL_buffinitsize PROTO C :VARARG
luaL_callmeta PROTO C :VARARG
luaL_checkany PROTO C :VARARG
luaL_checkinteger PROTO C :VARARG
luaL_checklstring PROTO C :VARARG
luaL_checknumber PROTO C :VARARG
luaL_checkoption PROTO C :VARARG
luaL_checkstack PROTO C :VARARG
luaL_checktype PROTO C :VARARG
luaL_checkudata PROTO C :VARARG
luaL_checkversion_ PROTO C :VARARG
luaL_error PROTO C :VARARG
luaL_execresult PROTO C :VARARG
luaL_fileresult PROTO C :VARARG
luaL_getmetafield PROTO C :VARARG
luaL_getsubtable PROTO C :VARARG
luaL_gsub PROTO C :VARARG
luaL_len PROTO C :VARARG
luaL_loadbufferx PROTO C :VARARG
luaL_loadfilex PROTO C :VARARG
luaL_loadstring PROTO C :VARARG
luaL_newmetatable PROTO C :VARARG
luaL_newstate PROTO C ; void
luaL_openlibs PROTO C :DWORD ; luastate
luaL_optinteger PROTO C :VARARG
luaL_optlstring PROTO C :VARARG
luaL_optnumber PROTO C :VARARG
luaL_prepbuffsize PROTO C :VARARG
luaL_pushresult PROTO C :VARARG
luaL_pushresultsize PROTO C :VARARG
luaL_ref PROTO C :VARARG
luaL_requiref PROTO C :VARARG
luaL_setfuncs PROTO C :VARARG
luaL_setmetatable PROTO C :VARARG
luaL_testudata PROTO C :VARARG
luaL_tolstring PROTO C :VARARG
luaL_traceback PROTO C :VARARG
luaL_unref PROTO C :VARARG
luaL_where PROTO C :VARARG
luaM_growaux_ PROTO C :VARARG
luaM_realloc_ PROTO C :VARARG
luaM_toobig PROTO C :VARARG
luaO_arith PROTO C :VARARG
luaO_ceillog2 PROTO C :VARARG
luaO_chunkid PROTO C :VARARG
luaO_fb2int PROTO C :VARARG
luaO_hexavalue PROTO C :VARARG
luaO_int2fb PROTO C :VARARG
luaO_nilobject_ PROTO C :VARARG
luaO_pushfstring PROTO C :VARARG
luaO_pushvfstring PROTO C :VARARG
luaO_str2num PROTO C :VARARG
luaO_tostring PROTO C :VARARG
luaO_utf8esc PROTO C :VARARG
luaP_opmodes PROTO C :VARARG
luaP_opnames PROTO C :VARARG
luaS_clearcache PROTO C :VARARG
luaS_createlngstrobj PROTO C :VARARG
luaS_eqlngstr PROTO C :VARARG
luaS_hash PROTO C :VARARG
luaS_hashlongstr PROTO C :VARARG
luaS_init PROTO C :VARARG
luaS_new PROTO C :VARARG
luaS_newlstr PROTO C :VARARG
luaS_newudata PROTO C :VARARG
luaS_remove PROTO C :VARARG
luaS_resize PROTO C :VARARG
luaT_callTM PROTO C :VARARG
luaT_callbinTM PROTO C :VARARG
luaT_callorderTM PROTO C :VARARG
luaT_gettm PROTO C :VARARG
luaT_gettmbyobj PROTO C :VARARG
luaT_init PROTO C :VARARG
luaT_objtypename PROTO C :VARARG
luaT_trybinTM PROTO C :VARARG
luaT_typenames_ PROTO C :VARARG
luaU_dump PROTO C :VARARG
luaU_undump PROTO C :VARARG
luaV_concat PROTO C :VARARG
luaV_div PROTO C :VARARG
luaV_equalobj PROTO C :VARARG
luaV_execute PROTO C :VARARG
luaV_finishOp PROTO C :VARARG
luaV_finishget PROTO C :VARARG
luaV_finishset PROTO C :VARARG
luaV_lessequal PROTO C :VARARG
luaV_lessthan PROTO C :VARARG
luaV_mod PROTO C :VARARG
luaV_objlen PROTO C :VARARG
luaV_settable PROTO C :VARARG ;(lua_State *L, const TValue *t, TValue *key, StkId val)
luaV_shiftl PROTO C :VARARG
luaV_tointeger PROTO C :VARARG
luaV_tonumber_ PROTO C :VARARG
luaX_init PROTO C :VARARG
luaX_lookahead PROTO C :VARARG
luaX_newstring PROTO C :VARARG
luaX_next PROTO C :VARARG
luaX_setinput PROTO C :VARARG
luaX_syntaxerror PROTO C :VARARG
luaX_token2str PROTO C :VARARG
luaY_parser PROTO C :VARARG
luaZ_fill PROTO C :VARARG
luaZ_init PROTO C :VARARG
luaZ_read PROTO C :VARARG
lua_absindex PROTO C :VARARG
lua_arith PROTO C :VARARG
lua_atpanic PROTO C :VARARG
lua_callk PROTO C :VARARG
lua_checkstack PROTO C :VARARG
lua_close PROTO C :VARARG
lua_compare PROTO C :VARARG
lua_concat PROTO C :VARARG
lua_copy PROTO C :VARARG
lua_createtable PROTO C :VARARG
lua_dump PROTO C :VARARG
lua_error PROTO C :VARARG
lua_gc PROTO C :VARARG
lua_getallocf PROTO C :VARARG
lua_getfield PROTO C :VARARG
lua_getglobal PROTO C :VARARG
lua_gethook PROTO C :VARARG
lua_gethookcount PROTO C :VARARG
lua_gethookmask PROTO C :VARARG
lua_geti PROTO C :VARARG
lua_getinfo PROTO C :VARARG
lua_getlocal PROTO C :VARARG
lua_getmetatable PROTO C :VARARG
lua_getstack PROTO C :VARARG
lua_gettable PROTO C :VARARG
lua_gettop PROTO C :VARARG
lua_getupvalue PROTO C :VARARG
lua_getuservalue PROTO C :VARARG
lua_ident PROTO C :VARARG
lua_iscfunction PROTO C :VARARG
lua_isinteger PROTO C :VARARG
lua_isnumber PROTO C :VARARG
lua_isstring PROTO C :VARARG
lua_isuserdata PROTO C :VARARG
lua_isyieldable PROTO C :VARARG
lua_len PROTO C :VARARG
lua_load PROTO C :VARARG
lua_newstate PROTO C :VARARG
lua_newthread PROTO C :VARARG
lua_newuserdata PROTO C :VARARG
lua_next PROTO C :VARARG
lua_pcallk PROTO C :VARARG
lua_pushboolean PROTO C :VARARG
lua_pushcclosure PROTO C ptr_lua_State:DWORD, lua_CFunction:DWORD, n:DWORD
lua_pushfstring PROTO C :VARARG
lua_pushinteger PROTO C :VARARG
lua_pushlightuserdata PROTO C :VARARG
lua_pushlstring PROTO C :VARARG
lua_pushnil PROTO C :VARARG
lua_pushnumber PROTO C :VARARG
lua_pushstring PROTO C :VARARG
lua_pushthread PROTO C :VARARG
lua_pushvalue PROTO C :VARARG
lua_pushvfstring PROTO C :VARARG
lua_rawequal PROTO C :VARARG
lua_rawget PROTO C :VARARG
lua_rawgeti PROTO C :VARARG
lua_rawgetp PROTO C :VARARG
lua_rawlen PROTO C :VARARG
lua_rawset PROTO C :VARARG
lua_rawseti PROTO C :VARARG
lua_rawsetp PROTO C :VARARG
lua_resume PROTO C :VARARG
lua_rotate PROTO C :VARARG
lua_setallocf PROTO C :VARARG
lua_setfield PROTO C :VARARG
lua_setglobal PROTO C ptr_lua_State:DWORD, ptr_name:DWORD
lua_sethook PROTO C :VARARG
lua_seti PROTO C :VARARG
lua_setlocal PROTO C :VARARG
lua_setmetatable PROTO C :VARARG
lua_settable PROTO C :VARARG
lua_settop PROTO C :VARARG
lua_setupvalue PROTO C :VARARG
lua_setuservalue PROTO C :VARARG
lua_status PROTO C :VARARG
lua_stringtonumber PROTO C :VARARG
lua_toboolean PROTO C :VARARG
lua_tocfunction PROTO C :VARARG
lua_tointegerx PROTO C :VARARG
lua_tolstring PROTO C :VARARG
lua_tonumberx PROTO C :VARARG
lua_topointer PROTO C :VARARG
lua_tothread PROTO C :VARARG
lua_touserdata PROTO C :VARARG
lua_type PROTO C :VARARG
lua_typename PROTO C :VARARG
lua_upvalueid PROTO C :VARARG
lua_upvaluejoin PROTO C :VARARG
lua_version PROTO C :DWORD ; luastate
lua_xmove PROTO C :VARARG
lua_yieldk PROTO C :VARARG
luai_ctype_ PROTO C :VARARG
luaopen_base PROTO C :VARARG
luaopen_bit32 PROTO C :VARARG
luaopen_coroutine PROTO C :VARARG
luaopen_debug PROTO C :VARARG
luaopen_io PROTO C :VARARG
luaopen_math PROTO C :VARARG
luaopen_os PROTO C :VARARG
luaopen_package PROTO C :VARARG
luaopen_string PROTO C :VARARG
luaopen_table PROTO C :VARARG
luaopen_utf8 PROTO C :VARARG
_ftol2_sse PROTO C :VARARG


; Structures
;struct lua_Debug {
;  int event;
;  const char *name;	/* (n) */
;  const char *namewhat;	/* (n) 'global', 'local', 'field', 'method' */
;  const char *what;	/* (S) 'Lua', 'C', 'main', 'tail' */
;  const char *source;	/* (S) */
;  int currentline;	/* (l) */
;  int linedefined;	/* (S) */
;  int lastlinedefined;	/* (S) */
;  unsigned char nups;	/* (u) number of upvalues */
;  unsigned char nparams;/* (u) number of parameters */
;  char isvararg;        /* (u) */
;  char istailcall;	/* (t) */
;  char short_src[LUA_IDSIZE]; /* (S) */
;  /* private part */
;  struct CallInfo *i_ci;  /* active function */
;};
;
;typedef struct luaL_Reg {
;  const char *name;
;  lua_CFunction func;
;} luaL_Reg;
;
;typedef struct luaL_Buffer {
;  char *b;  /* buffer address */
;  size_t size;  /* buffer size */
;  size_t n;  /* number of characters in buffer */
;  lua_State *L;
;  char initb[LUAL_BUFFERSIZE];  /* initial buffer */
;} luaL_Buffer;



.CONST
LUA_VERSION_MAJOR	    EQU "5"
LUA_VERSION_MINOR	    EQU "3"
LUA_VERSION_NUM		    EQU 503
LUA_VERSION_RELEASE	    EQU "4"

;LUA_VERSION


LUAI_BITSINT	        EQU 32
; predefined options for LUA_INT_TYPE
LUA_INT_INT		        EQU 1
LUA_INT_LONG		    EQU 2
LUA_INT_LONGLONG	    EQU 3

; predefined options for LUA_FLOAT_TYPE
LUA_FLOAT_FLOAT		    EQU 1
LUA_FLOAT_DOUBLE	    EQU 2
LUA_FLOAT_LONGDOUBLE	EQU 3

; 32-bit integers and 'float'
LUA_INT_TYPE	        EQU LUA_INT_INT
LUA_FLOAT_TYPE	        EQU LUA_FLOAT_FLOAT
LUA_NUMBER	            TYPEDEF QWORD ; float
LUA_INTEGER		        TYPEDEF DWORD ; int
LUAI_MAXSTACK		    EQU 15000
LUA_IDSIZE	            EQU 60
LUAL_BUFFERSIZE         EQU 2048

LUA_NOREF               EQU -2
LUA_REFNIL              EQU -1

; thread status */
LUA_OK		            EQU 0
LUA_YIELD	            EQU 1
LUA_ERRRUN	            EQU 2
LUA_ERRSYNTAX	        EQU 3
LUA_ERRMEM	            EQU 4
LUA_ERRGCMM	            EQU 5
LUA_ERRERR	            EQU 6

; basic types
LUA_TNONE		        EQU -1
LUA_TNIL		        EQU 0
LUA_TBOOLEAN		    EQU 1
LUA_TLIGHTUSERDATA	    EQU 2
LUA_TNUMBER		        EQU 3
LUA_TSTRING		        EQU 4
LUA_TTABLE		        EQU 5
LUA_TFUNCTION		    EQU 6
LUA_TUSERDATA		    EQU 7
LUA_TTHREAD		        EQU 8
LUA_NUMTAGS		        EQU 9



; minimum Lua stack available to a C function */
LUA_MINSTACK	        EQU 20


; predefined values in the registry */
LUA_RIDX_MAINTHREAD	    EQU 1
LUA_RIDX_GLOBALS	    EQU 2
LUA_RIDX_LAST		    EQU LUA_RIDX_GLOBALS

; Comparison and arithmetic functions
LUA_OPADD	            EQU 0 ; ORDER TM, ORDER OP
LUA_OPSUB	            EQU 1
LUA_OPMUL	            EQU 2
LUA_OPMOD	            EQU 3
LUA_OPPOW	            EQU 4
LUA_OPDIV	            EQU 5
LUA_OPIDIV	            EQU 6
LUA_OPBAND	            EQU 7
LUA_OPBOR	            EQU 8
LUA_OPBXOR	            EQU 9
LUA_OPSHL	            EQU 10
LUA_OPSHR	            EQU 11
LUA_OPUNM	            EQU 12
LUA_OPBNOT	            EQU 13

LUA_OPEQ	            EQU 0
LUA_OPLT	            EQU 1
LUA_OPLE	            EQU 2

LUA_GCSTOP		        EQU 0
LUA_GCRESTART		    EQU 1
LUA_GCCOLLECT		    EQU 2
LUA_GCCOUNT		        EQU 3
LUA_GCCOUNTB		    EQU 4
LUA_GCSTEP		        EQU 5
LUA_GCSETPAUSE		    EQU 6
LUA_GCSETSTEPMUL	    EQU 7
LUA_GCISRUNNING		    EQU 9

; Event codes
LUA_HOOKCALL	        EQU 0
LUA_HOOKRET	            EQU 1
LUA_HOOKLINE	        EQU 2
LUA_HOOKCOUNT	        EQU 3
LUA_HOOKTAILCALL        EQU 4


; Event masks
LUA_MASKCALL	        EQU (1 SHL LUA_HOOKCALL)
LUA_MASKRET	            EQU (1 SHL LUA_HOOKRET)
LUA_MASKLINE	        EQU (1 SHL LUA_HOOKLINE)
LUA_MASKCOUNT	        EQU (1 SHL LUA_HOOKCOUNT)


;typedef LUA_NUMBER lua_Number;
;typedef LUA_INTEGER lua_Integer;
;typedef LUA_UNSIGNED lua_Unsigned;
;typedef LUA_KCONTEXT lua_KContext;


;; state manipulation
;LUA_API lua_State *(lua_newstate) (lua_Alloc f, void *ud);
;LUA_API void       (lua_close) (lua_State *L);
;LUA_API lua_State *(lua_newthread) (lua_State *L);
;LUA_API lua_CFunction (lua_atpanic) (lua_State *L, lua_CFunction panicf);
;LUA_API const lua_Number *(lua_version) (lua_State *L);
;
;; basic stack manipulation
;LUA_API int   (lua_absindex) (lua_State *L, int idx);
;LUA_API int   (lua_gettop) (lua_State *L);
;LUA_API void  (lua_settop) (lua_State *L, int idx);
;LUA_API void  (lua_pushvalue) (lua_State *L, int idx);
;LUA_API void  (lua_rotate) (lua_State *L, int idx, int n);
;LUA_API void  (lua_copy) (lua_State *L, int fromidx, int toidx);
;LUA_API int   (lua_checkstack) (lua_State *L, int n);
;LUA_API void  (lua_xmove) (lua_State *from, lua_State *to, int n);
;
;; access functions (stack -> C)
;LUA_API int             (lua_isnumber) (lua_State *L, int idx);
;LUA_API int             (lua_isstring) (lua_State *L, int idx);
;LUA_API int             (lua_iscfunction) (lua_State *L, int idx);
;LUA_API int             (lua_isinteger) (lua_State *L, int idx);
;LUA_API int             (lua_isuserdata) (lua_State *L, int idx);
;LUA_API int             (lua_type) (lua_State *L, int idx);
;LUA_API const char     *(lua_typename) (lua_State *L, int tp);
;LUA_API lua_Number      (lua_tonumberx) (lua_State *L, int idx, int *isnum);
;LUA_API lua_Integer     (lua_tointegerx) (lua_State *L, int idx, int *isnum);
;LUA_API int             (lua_toboolean) (lua_State *L, int idx);
;LUA_API const char     *(lua_tolstring) (lua_State *L, int idx, size_t *len);
;LUA_API size_t          (lua_rawlen) (lua_State *L, int idx);
;LUA_API lua_CFunction   (lua_tocfunction) (lua_State *L, int idx);
;LUA_API void	       *(lua_touserdata) (lua_State *L, int idx);
;LUA_API lua_State      *(lua_tothread) (lua_State *L, int idx);
;LUA_API const void     *(lua_topointer) (lua_State *L, int idx);
;LUA_API void  (lua_arith) (lua_State *L, int op);
;LUA_API int   (lua_rawequal) (lua_State *L, int idx1, int idx2);
;LUA_API int   (lua_compare) (lua_State *L, int idx1, int idx2, int op);
;
;; push functions (C -> stack)
;LUA_API void        (lua_pushnil) (lua_State *L);
;LUA_API void        (lua_pushnumber) (lua_State *L, lua_Number n);
;LUA_API void        (lua_pushinteger) (lua_State *L, lua_Integer n);
;LUA_API const char *(lua_pushlstring) (lua_State *L, const char *s, size_t len);
;LUA_API const char *(lua_pushstring) (lua_State *L, const char *s);
;LUA_API const char *(lua_pushvfstring) (lua_State *L, const char *fmt, va_list argp);
;LUA_API const char *(lua_pushfstring) (lua_State *L, const char *fmt, ...);
;LUA_API void  (lua_pushcclosure) (lua_State *L, lua_CFunction fn, int n);
;LUA_API void  (lua_pushboolean) (lua_State *L, int b);
;LUA_API void  (lua_pushlightuserdata) (lua_State *L, void *p);
;LUA_API int   (lua_pushthread) (lua_State *L);
;
;; get functions (Lua -> stack)
;LUA_API int (lua_getglobal) (lua_State *L, const char *name);
;LUA_API int (lua_gettable) (lua_State *L, int idx);
;LUA_API int (lua_getfield) (lua_State *L, int idx, const char *k);
;LUA_API int (lua_geti) (lua_State *L, int idx, lua_Integer n);
;LUA_API int (lua_rawget) (lua_State *L, int idx);
;LUA_API int (lua_rawgeti) (lua_State *L, int idx, lua_Integer n);
;LUA_API int (lua_rawgetp) (lua_State *L, int idx, const void *p);
;LUA_API void  (lua_createtable) (lua_State *L, int narr, int nrec);
;LUA_API void *(lua_newuserdata) (lua_State *L, size_t sz);
;LUA_API int   (lua_getmetatable) (lua_State *L, int objindex);
;LUA_API int  (lua_getuservalue) (lua_State *L, int idx);
;
;; set functions (stack -> Lua)
;LUA_API void  (lua_setglobal) (lua_State *L, const char *name);
;LUA_API void  (lua_settable) (lua_State *L, int idx);
;LUA_API void  (lua_setfield) (lua_State *L, int idx, const char *k);
;LUA_API void  (lua_seti) (lua_State *L, int idx, lua_Integer n);
;LUA_API void  (lua_rawset) (lua_State *L, int idx);
;LUA_API void  (lua_rawseti) (lua_State *L, int idx, lua_Integer n);
;LUA_API void  (lua_rawsetp) (lua_State *L, int idx, const void *p);
;LUA_API int   (lua_setmetatable) (lua_State *L, int objindex);
;LUA_API void  (lua_setuservalue) (lua_State *L, int idx);
;
;; 'load' and 'call' functions (load and run Lua code)
;LUA_API void  (lua_callk) (lua_State *L, int nargs, int nresults, lua_KContext ctx, lua_KFunction k);
;LUA_API int   (lua_pcallk) (lua_State *L, int nargs, int nresults, int errfunc, lua_KContext ctx, lua_KFunction k);
;LUA_API int   (lua_load) (lua_State *L, lua_Reader reader, void *dt, const char *chunkname, const char *mode);
;LUA_API int (lua_dump) (lua_State *L, lua_Writer writer, void *data, int strip);
;
;; coroutine functions
;LUA_API int  (lua_yieldk)     (lua_State *L, int nresults, lua_KContext ctx, lua_KFunction k);
;LUA_API int  (lua_resume)     (lua_State *L, lua_State *from, int narg);
;LUA_API int  (lua_status)     (lua_State *L);
;LUA_API int (lua_isyieldable) (lua_State *L);
;LUA_API int (lua_gc) (lua_State *L, int what, int data);
;
;; miscellaneous functions
;LUA_API int   (lua_error) (lua_State *L);
;LUA_API int   (lua_next) (lua_State *L, int idx);
;LUA_API void  (lua_concat) (lua_State *L, int n);
;LUA_API void  (lua_len)    (lua_State *L, int idx);
;LUA_API size_t   (lua_stringtonumber) (lua_State *L, const char *s);
;LUA_API lua_Alloc (lua_getallocf) (lua_State *L, void **ud);
;LUA_API void      (lua_setallocf) (lua_State *L, lua_Alloc f, void *ud);
;LUA_API int (lua_getstack) (lua_State *L, int level, lua_Debug *ar);
;LUA_API int (lua_getinfo) (lua_State *L, const char *what, lua_Debug *ar);
;LUA_API const char *(lua_getlocal) (lua_State *L, const lua_Debug *ar, int n);
;LUA_API const char *(lua_setlocal) (lua_State *L, const lua_Debug *ar, int n);
;LUA_API const char *(lua_getupvalue) (lua_State *L, int funcindex, int n);
;LUA_API const char *(lua_setupvalue) (lua_State *L, int funcindex, int n);
;LUA_API void *(lua_upvalueid) (lua_State *L, int fidx, int n);
;LUA_API void  (lua_upvaluejoin) (lua_State *L, int fidx1, int n1, int fidx2, int n2);
;LUA_API void (lua_sethook) (lua_State *L, lua_Hook func, int mask, int count);
;LUA_API lua_Hook (lua_gethook) (lua_State *L);
;LUA_API int (lua_gethookmask) (lua_State *L);
;LUA_API int (lua_gethookcount) (lua_State *L);
;
;LUAMOD_API int (luaopen_base) (lua_State *L);
;LUAMOD_API int (luaopen_coroutine) (lua_State *L);
;LUAMOD_API int (luaopen_table) (lua_State *L);
;LUAMOD_API int (luaopen_io) (lua_State *L);
;LUAMOD_API int (luaopen_os) (lua_State *L);
;LUAMOD_API int (luaopen_string) (lua_State *L);
;LUAMOD_API int (luaopen_utf8) (lua_State *L);
;LUAMOD_API int (luaopen_bit32) (lua_State *L);
;LUAMOD_API int (luaopen_math) (lua_State *L);
;LUAMOD_API int (luaopen_debug) (lua_State *L);
;LUAMOD_API int (luaopen_package) (lua_State *L);
;
;LUALIB_API void (luaL_openlibs) (lua_State *L);
;LUALIB_API int (luaL_getmetafield) (lua_State *L, int obj, const char *e);
;LUALIB_API int (luaL_callmeta) (lua_State *L, int obj, const char *e);
;LUALIB_API const char *(luaL_tolstring) (lua_State *L, int idx, size_t *len);
;LUALIB_API int (luaL_argerror) (lua_State *L, int arg, const char *extramsg);
;LUALIB_API const char *(luaL_checklstring) (lua_State *L, int arg, size_t *l);
;LUALIB_API const char *(luaL_optlstring) (lua_State *L, int arg, const char *def, size_t *l);
;LUALIB_API lua_Number (luaL_checknumber) (lua_State *L, int arg);
;LUALIB_API lua_Number (luaL_optnumber) (lua_State *L, int arg, lua_Number def);
;LUALIB_API lua_Integer (luaL_checkinteger) (lua_State *L, int arg);
;LUALIB_API lua_Integer (luaL_optinteger) (lua_State *L, int arg, lua_Integer def);
;LUALIB_API void (luaL_checkstack) (lua_State *L, int sz, const char *msg);
;LUALIB_API void (luaL_checktype) (lua_State *L, int arg, int t);
;LUALIB_API void (luaL_checkany) (lua_State *L, int arg);
;LUALIB_API int   (luaL_newmetatable) (lua_State *L, const char *tname);
;LUALIB_API void  (luaL_setmetatable) (lua_State *L, const char *tname);
;LUALIB_API void *(luaL_testudata) (lua_State *L, int ud, const char *tname);
;LUALIB_API void *(luaL_checkudata) (lua_State *L, int ud, const char *tname);
;LUALIB_API void (luaL_where) (lua_State *L, int lvl);
;LUALIB_API int (luaL_error) (lua_State *L, const char *fmt, ...);
;LUALIB_API int (luaL_checkoption) (lua_State *L, int arg, const char *def, const char *const lst[]);
;LUALIB_API int (luaL_fileresult) (lua_State *L, int stat, const char *fname);
;LUALIB_API int (luaL_execresult) (lua_State *L, int stat);
;LUALIB_API int (luaL_ref) (lua_State *L, int t);
;LUALIB_API void (luaL_unref) (lua_State *L, int t, int ref);
;LUALIB_API int (luaL_loadfilex) (lua_State *L, const char *filename, const char *mode);
;LUALIB_API int (luaL_loadbufferx) (lua_State *L, const char *buff, size_t sz, const char *name, const char *mode);
;LUALIB_API int (luaL_loadstring) (lua_State *L, const char *s);
;LUALIB_API lua_State *(luaL_newstate) (void);
;LUALIB_API lua_Integer (luaL_len) (lua_State *L, int idx);
;LUALIB_API const char *(luaL_gsub) (lua_State *L, const char *s, const char *p, const char *r);
;LUALIB_API void (luaL_setfuncs) (lua_State *L, const luaL_Reg *l, int nup);
;LUALIB_API int (luaL_getsubtable) (lua_State *L, int idx, const char *fname);
;LUALIB_API void (luaL_traceback) (lua_State *L, lua_State *L1, const char *msg, int level);
;LUALIB_API void (luaL_requiref) (lua_State *L, const char *modname, lua_CFunction openf, int glb);
;LUALIB_API void (luaL_buffinit) (lua_State *L, luaL_Buffer *B);
;LUALIB_API char *(luaL_prepbuffsize) (luaL_Buffer *B, size_t sz);
;LUALIB_API void (luaL_addlstring) (luaL_Buffer *B, const char *s, size_t l);
;LUALIB_API void (luaL_addstring) (luaL_Buffer *B, const char *s);
;LUALIB_API void (luaL_addvalue) (luaL_Buffer *B);
;LUALIB_API void (luaL_pushresult) (luaL_Buffer *B);
;LUALIB_API void (luaL_pushresultsize) (luaL_Buffer *B, size_t sz);
;LUALIB_API char *(luaL_buffinitsize) (lua_State *L, luaL_Buffer *B, size_t sz);





