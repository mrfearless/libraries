  ; ------------------------------------------
  ; prototypes for EXPORT msvcrt functions
  ; ------------------------------------------

    c_msvcrt typedef PROTO C :VARARG

    externdef _imp__$I10_OUTPUT:PTR c_msvcrt
    crt_$I10_OUTPUT equ <_imp__$I10_OUTPUT>

    externdef _imp___CIacos:PTR c_msvcrt
    crt__CIacos equ <_imp___CIacos>

    externdef _imp___CIasin:PTR c_msvcrt
    crt__CIasin equ <_imp___CIasin>

    externdef _imp___CIatan:PTR c_msvcrt
    crt__CIatan equ <_imp___CIatan>

    externdef _imp___CIatan2:PTR c_msvcrt
    crt__CIatan2 equ <_imp___CIatan2>

    externdef _imp___CIcos:PTR c_msvcrt
    crt__CIcos equ <_imp___CIcos>

    externdef _imp___CIcosh:PTR c_msvcrt
    crt__CIcosh equ <_imp___CIcosh>

    externdef _imp___CIexp:PTR c_msvcrt
    crt__CIexp equ <_imp___CIexp>

    externdef _imp___CIfmod:PTR c_msvcrt
    crt__CIfmod equ <_imp___CIfmod>

    externdef _imp___CIlog:PTR c_msvcrt
    crt__CIlog equ <_imp___CIlog>

    externdef _imp___CIlog10:PTR c_msvcrt
    crt__CIlog10 equ <_imp___CIlog10>

    externdef _imp___CIpow:PTR c_msvcrt
    crt__CIpow equ <_imp___CIpow>

    externdef _imp___CIsin:PTR c_msvcrt
    crt__CIsin equ <_imp___CIsin>

    externdef _imp___CIsinh:PTR c_msvcrt
    crt__CIsinh equ <_imp___CIsinh>

    externdef _imp___CIsqrt:PTR c_msvcrt
    crt__CIsqrt equ <_imp___CIsqrt>

    externdef _imp___CItan:PTR c_msvcrt
    crt__CItan equ <_imp___CItan>

    externdef _imp___CItanh:PTR c_msvcrt
    crt__CItanh equ <_imp___CItanh>

    externdef _imp___CxxThrowException:PTR c_msvcrt
    crt__CxxThrowException equ <_imp___CxxThrowException>

    externdef _imp___EH_prolog:PTR c_msvcrt
    crt__EH_prolog equ <_imp___EH_prolog>

    externdef _imp___Getdays:PTR c_msvcrt
    crt__Getdays equ <_imp___Getdays>

    externdef _imp___Getmonths:PTR c_msvcrt
    crt__Getmonths equ <_imp___Getmonths>

    externdef _imp___Gettnames:PTR c_msvcrt
    crt__Gettnames equ <_imp___Gettnames>

    externdef _imp___HUGE:PTR c_msvcrt
    crt__HUGE equ <_imp___HUGE>

    externdef _imp___Strftime:PTR c_msvcrt
    crt__Strftime equ <_imp___Strftime>

    externdef _imp___XcptFilter:PTR c_msvcrt
    crt__XcptFilter equ <_imp___XcptFilter>

    externdef _imp____CxxFrameHandler:PTR c_msvcrt
    crt___CxxFrameHandler equ <_imp____CxxFrameHandler>

    externdef _imp____CxxLongjmpUnwind:PTR c_msvcrt
    crt___CxxLongjmpUnwind equ <_imp____CxxLongjmpUnwind>

    externdef _imp____RTCastToVoid:PTR c_msvcrt
    crt___RTCastToVoid equ <_imp____RTCastToVoid>

    externdef _imp____RTDynamicCast:PTR c_msvcrt
    crt___RTDynamicCast equ <_imp____RTDynamicCast>

    externdef _imp____RTtypeid:PTR c_msvcrt
    crt___RTtypeid equ <_imp____RTtypeid>

    externdef _imp____STRINGTOLD:PTR c_msvcrt
    crt___STRINGTOLD equ <_imp____STRINGTOLD>

    externdef _imp____argc:PTR c_msvcrt
    crt___argc equ <_imp____argc>

    externdef _imp____argv:PTR c_msvcrt
    crt___argv equ <_imp____argv>

    externdef _imp____badioinfo:PTR c_msvcrt
    crt___badioinfo equ <_imp____badioinfo>

    externdef _imp____crtCompareStringA:PTR c_msvcrt
    crt___crtCompareStringA equ <_imp____crtCompareStringA>

    externdef _imp____crtGetLocaleInfoW:PTR c_msvcrt
    crt___crtGetLocaleInfoW equ <_imp____crtGetLocaleInfoW>

    externdef _imp____crtLCMapStringA:PTR c_msvcrt
    crt___crtLCMapStringA equ <_imp____crtLCMapStringA>

    externdef _imp____dllonexit:PTR c_msvcrt
    crt___dllonexit equ <_imp____dllonexit>

    externdef _imp____doserrno:PTR c_msvcrt
    crt___doserrno equ <_imp____doserrno>

    externdef _imp____fpecode:PTR c_msvcrt
    crt___fpecode equ <_imp____fpecode>

    externdef _imp____getmainargs:PTR c_msvcrt
    crt___getmainargs equ <_imp____getmainargs>

    externdef _imp____initenv:PTR c_msvcrt
    crt___initenv equ <_imp____initenv>

    externdef _imp____isascii:PTR c_msvcrt
    crt___isascii equ <_imp____isascii>

    externdef _imp____iscsym:PTR c_msvcrt
    crt___iscsym equ <_imp____iscsym>

    externdef _imp____iscsymf:PTR c_msvcrt
    crt___iscsymf equ <_imp____iscsymf>

    externdef _imp____lc_codepage:PTR c_msvcrt
    crt___lc_codepage equ <_imp____lc_codepage>

    externdef _imp____lc_collate_cp:PTR c_msvcrt
    crt___lc_collate_cp equ <_imp____lc_collate_cp>

    externdef _imp____lc_handle:PTR c_msvcrt
    crt___lc_handle equ <_imp____lc_handle>

    externdef _imp____lconv_init:PTR c_msvcrt
    crt___lconv_init equ <_imp____lconv_init>

    externdef _imp____mb_cur_max:PTR c_msvcrt
    crt___mb_cur_max equ <_imp____mb_cur_max>

    externdef _imp____p___argc:PTR c_msvcrt
    crt___p___argc equ <_imp____p___argc>

    externdef _imp____p___argv:PTR c_msvcrt
    crt___p___argv equ <_imp____p___argv>

    externdef _imp____p___initenv:PTR c_msvcrt
    crt___p___initenv equ <_imp____p___initenv>

    externdef _imp____p___mb_cur_max:PTR c_msvcrt
    crt___p___mb_cur_max equ <_imp____p___mb_cur_max>

    externdef _imp____p___wargv:PTR c_msvcrt
    crt___p___wargv equ <_imp____p___wargv>

    externdef _imp____p___winitenv:PTR c_msvcrt
    crt___p___winitenv equ <_imp____p___winitenv>

    externdef _imp____p__acmdln:PTR c_msvcrt
    crt___p__acmdln equ <_imp____p__acmdln>

    externdef _imp____p__amblksiz:PTR c_msvcrt
    crt___p__amblksiz equ <_imp____p__amblksiz>

    externdef _imp____p__commode:PTR c_msvcrt
    crt___p__commode equ <_imp____p__commode>

    externdef _imp____p__daylight:PTR c_msvcrt
    crt___p__daylight equ <_imp____p__daylight>

    externdef _imp____p__dstbias:PTR c_msvcrt
    crt___p__dstbias equ <_imp____p__dstbias>

    externdef _imp____p__environ:PTR c_msvcrt
    crt___p__environ equ <_imp____p__environ>

    externdef _imp____p__fileinfo:PTR c_msvcrt
    crt___p__fileinfo equ <_imp____p__fileinfo>

    externdef _imp____p__fmode:PTR c_msvcrt
    crt___p__fmode equ <_imp____p__fmode>

    externdef _imp____p__iob:PTR c_msvcrt
    crt___p__iob equ <_imp____p__iob>

    externdef _imp____p__mbcasemap:PTR c_msvcrt
    crt___p__mbcasemap equ <_imp____p__mbcasemap>

    externdef _imp____p__mbctype:PTR c_msvcrt
    crt___p__mbctype equ <_imp____p__mbctype>

    externdef _imp____p__osver:PTR c_msvcrt
    crt___p__osver equ <_imp____p__osver>

    externdef _imp____p__pctype:PTR c_msvcrt
    crt___p__pctype equ <_imp____p__pctype>

    externdef _imp____p__pgmptr:PTR c_msvcrt
    crt___p__pgmptr equ <_imp____p__pgmptr>

    externdef _imp____p__pwctype:PTR c_msvcrt
    crt___p__pwctype equ <_imp____p__pwctype>

    externdef _imp____p__timezone:PTR c_msvcrt
    crt___p__timezone equ <_imp____p__timezone>

    externdef _imp____p__tzname:PTR c_msvcrt
    crt___p__tzname equ <_imp____p__tzname>

    externdef _imp____p__wcmdln:PTR c_msvcrt
    crt___p__wcmdln equ <_imp____p__wcmdln>

    externdef _imp____p__wenviron:PTR c_msvcrt
    crt___p__wenviron equ <_imp____p__wenviron>

    externdef _imp____p__winmajor:PTR c_msvcrt
    crt___p__winmajor equ <_imp____p__winmajor>

    externdef _imp____p__winminor:PTR c_msvcrt
    crt___p__winminor equ <_imp____p__winminor>

    externdef _imp____p__winver:PTR c_msvcrt
    crt___p__winver equ <_imp____p__winver>

    externdef _imp____p__wpgmptr:PTR c_msvcrt
    crt___p__wpgmptr equ <_imp____p__wpgmptr>

    externdef _imp____pioinfo:PTR c_msvcrt
    crt___pioinfo equ <_imp____pioinfo>

    externdef _imp____pxcptinfoptrs:PTR c_msvcrt
    crt___pxcptinfoptrs equ <_imp____pxcptinfoptrs>

    externdef _imp____set_app_type:PTR c_msvcrt
    crt___set_app_type equ <_imp____set_app_type>

    externdef _imp____setlc_active:PTR c_msvcrt
    crt___setlc_active equ <_imp____setlc_active>

    externdef _imp____setusermatherr:PTR c_msvcrt
    crt___setusermatherr equ <_imp____setusermatherr>

    externdef _imp____threadhandle:PTR c_msvcrt
    crt___threadhandle equ <_imp____threadhandle>

    externdef _imp____threadid:PTR c_msvcrt
    crt___threadid equ <_imp____threadid>

    externdef _imp____toascii:PTR c_msvcrt
    crt___toascii equ <_imp____toascii>

    externdef _imp____unDName:PTR c_msvcrt
    crt___unDName equ <_imp____unDName>

    externdef _imp____unDNameEx:PTR c_msvcrt
    crt___unDNameEx equ <_imp____unDNameEx>

    externdef _imp____unguarded_readlc_active:PTR c_msvcrt
    crt___unguarded_readlc_active equ <_imp____unguarded_readlc_active>

    externdef _imp____wargv:PTR c_msvcrt
    crt___wargv equ <_imp____wargv>

    externdef _imp____wgetmainargs:PTR c_msvcrt
    crt___wgetmainargs equ <_imp____wgetmainargs>

    externdef _imp____winitenv:PTR c_msvcrt
    crt___winitenv equ <_imp____winitenv>

    externdef _imp___abnormal_termination:PTR c_msvcrt
    crt__abnormal_termination equ <_imp___abnormal_termination>

    externdef _imp___access:PTR c_msvcrt
    crt__access equ <_imp___access>

    externdef _imp___acmdln:PTR c_msvcrt
    crt__acmdln equ <_imp___acmdln>

    externdef _imp___adj_fdiv_m16i:PTR c_msvcrt
    crt__adj_fdiv_m16i equ <_imp___adj_fdiv_m16i>

    externdef _imp___adj_fdiv_m32:PTR c_msvcrt
    crt__adj_fdiv_m32 equ <_imp___adj_fdiv_m32>

    externdef _imp___adj_fdiv_m32i:PTR c_msvcrt
    crt__adj_fdiv_m32i equ <_imp___adj_fdiv_m32i>

    externdef _imp___adj_fdiv_m64:PTR c_msvcrt
    crt__adj_fdiv_m64 equ <_imp___adj_fdiv_m64>

    externdef _imp___adj_fdiv_r:PTR c_msvcrt
    crt__adj_fdiv_r equ <_imp___adj_fdiv_r>

    externdef _imp___adj_fdivr_m16i:PTR c_msvcrt
    crt__adj_fdivr_m16i equ <_imp___adj_fdivr_m16i>

    externdef _imp___adj_fdivr_m32:PTR c_msvcrt
    crt__adj_fdivr_m32 equ <_imp___adj_fdivr_m32>

    externdef _imp___adj_fdivr_m32i:PTR c_msvcrt
    crt__adj_fdivr_m32i equ <_imp___adj_fdivr_m32i>

    externdef _imp___adj_fdivr_m64:PTR c_msvcrt
    crt__adj_fdivr_m64 equ <_imp___adj_fdivr_m64>

    externdef _imp___adj_fpatan:PTR c_msvcrt
    crt__adj_fpatan equ <_imp___adj_fpatan>

    externdef _imp___adj_fprem:PTR c_msvcrt
    crt__adj_fprem equ <_imp___adj_fprem>

    externdef _imp___adj_fprem1:PTR c_msvcrt
    crt__adj_fprem1 equ <_imp___adj_fprem1>

    externdef _imp___adj_fptan:PTR c_msvcrt
    crt__adj_fptan equ <_imp___adj_fptan>

    externdef _imp___adjust_fdiv:PTR c_msvcrt
    crt__adjust_fdiv equ <_imp___adjust_fdiv>

    externdef _imp___aexit_rtn:PTR c_msvcrt
    crt__aexit_rtn equ <_imp___aexit_rtn>

    externdef _imp___amsg_exit:PTR c_msvcrt
    crt__amsg_exit equ <_imp___amsg_exit>

    externdef _imp___assert:PTR c_msvcrt
    crt__assert equ <_imp___assert>

    externdef _imp___atodbl:PTR c_msvcrt
    crt__atodbl equ <_imp___atodbl>

    externdef _imp___atoi64:PTR c_msvcrt
    crt__atoi64 equ <_imp___atoi64>

    externdef _imp___atoldbl:PTR c_msvcrt
    crt__atoldbl equ <_imp___atoldbl>

    externdef _imp___beep:PTR c_msvcrt
    crt__beep equ <_imp___beep>

    externdef _imp___beginthread:PTR c_msvcrt
    crt__beginthread equ <_imp___beginthread>

    externdef _imp___beginthreadex:PTR c_msvcrt
    crt__beginthreadex equ <_imp___beginthreadex>

    externdef _imp___c_exit:PTR c_msvcrt
    crt__c_exit equ <_imp___c_exit>

    externdef _imp___cabs:PTR c_msvcrt
    crt__cabs equ <_imp___cabs>

    externdef _imp___callnewh:PTR c_msvcrt
    crt__callnewh equ <_imp___callnewh>

    externdef _imp___cexit:PTR c_msvcrt
    crt__cexit equ <_imp___cexit>

    externdef _imp___cgets:PTR c_msvcrt
    crt__cgets equ <_imp___cgets>

    externdef _imp___chdir:PTR c_msvcrt
    crt__chdir equ <_imp___chdir>

    externdef _imp___chdrive:PTR c_msvcrt
    crt__chdrive equ <_imp___chdrive>

    externdef _imp___chgsign:PTR c_msvcrt
    crt__chgsign equ <_imp___chgsign>

    externdef _imp___chkesp:PTR c_msvcrt
    crt__chkesp equ <_imp___chkesp>

    externdef _imp___chmod:PTR c_msvcrt
    crt__chmod equ <_imp___chmod>

    externdef _imp___chsize:PTR c_msvcrt
    crt__chsize equ <_imp___chsize>

    externdef _imp___clearfp:PTR c_msvcrt
    crt__clearfp equ <_imp___clearfp>

    externdef _imp___close:PTR c_msvcrt
    crt__close equ <_imp___close>

    externdef _imp___commit:PTR c_msvcrt
    crt__commit equ <_imp___commit>

    externdef _imp___commode:PTR c_msvcrt
    crt__commode equ <_imp___commode>

    externdef _imp___control87:PTR c_msvcrt
    crt__control87 equ <_imp___control87>

    externdef _imp___controlfp:PTR c_msvcrt
    crt__controlfp equ <_imp___controlfp>

    externdef _imp___copysign:PTR c_msvcrt
    crt__copysign equ <_imp___copysign>

    externdef _imp___cprintf:PTR c_msvcrt
    crt__cprintf equ <_imp___cprintf>

    externdef _imp___cputs:PTR c_msvcrt
    crt__cputs equ <_imp___cputs>

    externdef _imp___creat:PTR c_msvcrt
    crt__creat equ <_imp___creat>

    externdef _imp___cscanf:PTR c_msvcrt
    crt__cscanf equ <_imp___cscanf>

    externdef _imp___ctime64:PTR c_msvcrt
    crt__ctime64 equ <_imp___ctime64>

    externdef _imp___ctype:PTR c_msvcrt
    crt__ctype equ <_imp___ctype>

    externdef _imp___cwait:PTR c_msvcrt
    crt__cwait equ <_imp___cwait>

    externdef _imp___daylight:PTR c_msvcrt
    crt__daylight equ <_imp___daylight>

    externdef _imp___dstbias:PTR c_msvcrt
    crt__dstbias equ <_imp___dstbias>

    externdef _imp___dup:PTR c_msvcrt
    crt__dup equ <_imp___dup>

    externdef _imp___dup2:PTR c_msvcrt
    crt__dup2 equ <_imp___dup2>

    externdef _imp___ecvt:PTR c_msvcrt
    crt__ecvt equ <_imp___ecvt>

    externdef _imp___endthread:PTR c_msvcrt
    crt__endthread equ <_imp___endthread>

    externdef _imp___endthreadex:PTR c_msvcrt
    crt__endthreadex equ <_imp___endthreadex>

    externdef _imp___environ:PTR c_msvcrt
    crt__environ equ <_imp___environ>

    externdef _imp___eof:PTR c_msvcrt
    crt__eof equ <_imp___eof>

    externdef _imp___errno:PTR c_msvcrt
    crt__errno equ <_imp___errno>

    externdef _imp___except_handler2:PTR c_msvcrt
    crt__except_handler2 equ <_imp___except_handler2>

    externdef _imp___except_handler3:PTR c_msvcrt
    crt__except_handler3 equ <_imp___except_handler3>

    externdef _imp___execl:PTR c_msvcrt
    crt__execl equ <_imp___execl>

    externdef _imp___execle:PTR c_msvcrt
    crt__execle equ <_imp___execle>

    externdef _imp___execlp:PTR c_msvcrt
    crt__execlp equ <_imp___execlp>

    externdef _imp___execlpe:PTR c_msvcrt
    crt__execlpe equ <_imp___execlpe>

    externdef _imp___execv:PTR c_msvcrt
    crt__execv equ <_imp___execv>

    externdef _imp___execve:PTR c_msvcrt
    crt__execve equ <_imp___execve>

    externdef _imp___execvp:PTR c_msvcrt
    crt__execvp equ <_imp___execvp>

    externdef _imp___execvpe:PTR c_msvcrt
    crt__execvpe equ <_imp___execvpe>

    externdef _imp___exit:PTR c_msvcrt
    crt__exit equ <_imp___exit>

    externdef _imp___expand:PTR c_msvcrt
    crt__expand equ <_imp___expand>

    externdef _imp___fcloseall:PTR c_msvcrt
    crt__fcloseall equ <_imp___fcloseall>

    externdef _imp___fcvt:PTR c_msvcrt
    crt__fcvt equ <_imp___fcvt>

    externdef _imp___fdopen:PTR c_msvcrt
    crt__fdopen equ <_imp___fdopen>

    externdef _imp___fgetchar:PTR c_msvcrt
    crt__fgetchar equ <_imp___fgetchar>

    externdef _imp___fgetwchar:PTR c_msvcrt
    crt__fgetwchar equ <_imp___fgetwchar>

    externdef _imp___filbuf:PTR c_msvcrt
    crt__filbuf equ <_imp___filbuf>

    externdef _imp___fileinfo:PTR c_msvcrt
    crt__fileinfo equ <_imp___fileinfo>

    externdef _imp___filelength:PTR c_msvcrt
    crt__filelength equ <_imp___filelength>

    externdef _imp___filelengthi64:PTR c_msvcrt
    crt__filelengthi64 equ <_imp___filelengthi64>

    externdef _imp___fileno:PTR c_msvcrt
    crt__fileno equ <_imp___fileno>

    externdef _imp___findclose:PTR c_msvcrt
    crt__findclose equ <_imp___findclose>

    externdef _imp___findfirst:PTR c_msvcrt
    crt__findfirst equ <_imp___findfirst>

    externdef _imp___findfirst64:PTR c_msvcrt
    crt__findfirst64 equ <_imp___findfirst64>

    externdef _imp___findfirsti64:PTR c_msvcrt
    crt__findfirsti64 equ <_imp___findfirsti64>

    externdef _imp___findnext:PTR c_msvcrt
    crt__findnext equ <_imp___findnext>

    externdef _imp___findnext64:PTR c_msvcrt
    crt__findnext64 equ <_imp___findnext64>

    externdef _imp___findnexti64:PTR c_msvcrt
    crt__findnexti64 equ <_imp___findnexti64>

    externdef _imp___finite:PTR c_msvcrt
    crt__finite equ <_imp___finite>

    externdef _imp___flsbuf:PTR c_msvcrt
    crt__flsbuf equ <_imp___flsbuf>

    externdef _imp___flushall:PTR c_msvcrt
    crt__flushall equ <_imp___flushall>

    externdef _imp___fmode:PTR c_msvcrt
    crt__fmode equ <_imp___fmode>

    externdef _imp___fpclass:PTR c_msvcrt
    crt__fpclass equ <_imp___fpclass>

    externdef _imp___fpieee_flt:PTR c_msvcrt
    crt__fpieee_flt equ <_imp___fpieee_flt>

    externdef _imp___fpreset:PTR c_msvcrt
    crt__fpreset equ <_imp___fpreset>

    externdef _imp___fputchar:PTR c_msvcrt
    crt__fputchar equ <_imp___fputchar>

    externdef _imp___fputwchar:PTR c_msvcrt
    crt__fputwchar equ <_imp___fputwchar>

    externdef _imp___fsopen:PTR c_msvcrt
    crt__fsopen equ <_imp___fsopen>

    externdef _imp___fstat:PTR c_msvcrt
    crt__fstat equ <_imp___fstat>

    externdef _imp___fstat64:PTR c_msvcrt
    crt__fstat64 equ <_imp___fstat64>

    externdef _imp___fstati64:PTR c_msvcrt
    crt__fstati64 equ <_imp___fstati64>

    externdef _imp___ftime:PTR c_msvcrt
    crt__ftime equ <_imp___ftime>

    externdef _imp___ftime64:PTR c_msvcrt
    crt__ftime64 equ <_imp___ftime64>

    externdef _imp___ftol:PTR c_msvcrt
    crt__ftol equ <_imp___ftol>

    externdef _imp___fullpath:PTR c_msvcrt
    crt__fullpath equ <_imp___fullpath>

    externdef _imp___futime:PTR c_msvcrt
    crt__futime equ <_imp___futime>

    externdef _imp___futime64:PTR c_msvcrt
    crt__futime64 equ <_imp___futime64>

    externdef _imp___gcvt:PTR c_msvcrt
    crt__gcvt equ <_imp___gcvt>

    externdef _imp___get_heap_handle:PTR c_msvcrt
    crt__get_heap_handle equ <_imp___get_heap_handle>

    externdef _imp___get_osfhandle:PTR c_msvcrt
    crt__get_osfhandle equ <_imp___get_osfhandle>

    externdef _imp___get_sbh_threshold:PTR c_msvcrt
    crt__get_sbh_threshold equ <_imp___get_sbh_threshold>

    externdef _imp___getch:PTR c_msvcrt
    crt__getch equ <_imp___getch>

    externdef _imp___getche:PTR c_msvcrt
    crt__getche equ <_imp___getche>

    externdef _imp___getcwd:PTR c_msvcrt
    crt__getcwd equ <_imp___getcwd>

    externdef _imp___getdcwd:PTR c_msvcrt
    crt__getdcwd equ <_imp___getdcwd>

    externdef _imp___getdiskfree:PTR c_msvcrt
    crt__getdiskfree equ <_imp___getdiskfree>

    externdef _imp___getdllprocaddr:PTR c_msvcrt
    crt__getdllprocaddr equ <_imp___getdllprocaddr>

    externdef _imp___getdrive:PTR c_msvcrt
    crt__getdrive equ <_imp___getdrive>

    externdef _imp___getdrives:PTR c_msvcrt
    crt__getdrives equ <_imp___getdrives>

    externdef _imp___getmaxstdio:PTR c_msvcrt
    crt__getmaxstdio equ <_imp___getmaxstdio>

    externdef _imp___getmbcp:PTR c_msvcrt
    crt__getmbcp equ <_imp___getmbcp>

    externdef _imp___getpid:PTR c_msvcrt
    crt__getpid equ <_imp___getpid>

    externdef _imp___getsystime:PTR c_msvcrt
    crt__getsystime equ <_imp___getsystime>

    externdef _imp___getw:PTR c_msvcrt
    crt__getw equ <_imp___getw>

    externdef _imp___getws:PTR c_msvcrt
    crt__getws equ <_imp___getws>

    externdef _imp___global_unwind2:PTR c_msvcrt
    crt__global_unwind2 equ <_imp___global_unwind2>

    externdef _imp___gmtime64:PTR c_msvcrt
    crt__gmtime64 equ <_imp___gmtime64>

    externdef _imp___heapadd:PTR c_msvcrt
    crt__heapadd equ <_imp___heapadd>

    externdef _imp___heapchk:PTR c_msvcrt
    crt__heapchk equ <_imp___heapchk>

    externdef _imp___heapmin:PTR c_msvcrt
    crt__heapmin equ <_imp___heapmin>

    externdef _imp___heapset:PTR c_msvcrt
    crt__heapset equ <_imp___heapset>

    externdef _imp___heapused:PTR c_msvcrt
    crt__heapused equ <_imp___heapused>

    externdef _imp___heapwalk:PTR c_msvcrt
    crt__heapwalk equ <_imp___heapwalk>

    externdef _imp___hypot:PTR c_msvcrt
    crt__hypot equ <_imp___hypot>

    externdef _imp___i64toa:PTR c_msvcrt
    crt__i64toa equ <_imp___i64toa>

    externdef _imp___i64tow:PTR c_msvcrt
    crt__i64tow equ <_imp___i64tow>

    externdef _imp___initterm:PTR c_msvcrt
    crt__initterm equ <_imp___initterm>

    externdef _imp___inp:PTR c_msvcrt
    crt__inp equ <_imp___inp>

    externdef _imp___inpd:PTR c_msvcrt
    crt__inpd equ <_imp___inpd>

    externdef _imp___inpw:PTR c_msvcrt
    crt__inpw equ <_imp___inpw>

    externdef _imp___iob:PTR c_msvcrt
    crt__iob equ <_imp___iob>

    externdef _imp___isatty:PTR c_msvcrt
    crt__isatty equ <_imp___isatty>

    externdef _imp___isctype:PTR c_msvcrt
    crt__isctype equ <_imp___isctype>

    externdef _imp___ismbbalnum:PTR c_msvcrt
    crt__ismbbalnum equ <_imp___ismbbalnum>

    externdef _imp___ismbbalpha:PTR c_msvcrt
    crt__ismbbalpha equ <_imp___ismbbalpha>

    externdef _imp___ismbbgraph:PTR c_msvcrt
    crt__ismbbgraph equ <_imp___ismbbgraph>

    externdef _imp___ismbbkalnum:PTR c_msvcrt
    crt__ismbbkalnum equ <_imp___ismbbkalnum>

    externdef _imp___ismbbkana:PTR c_msvcrt
    crt__ismbbkana equ <_imp___ismbbkana>

    externdef _imp___ismbbkprint:PTR c_msvcrt
    crt__ismbbkprint equ <_imp___ismbbkprint>

    externdef _imp___ismbbkpunct:PTR c_msvcrt
    crt__ismbbkpunct equ <_imp___ismbbkpunct>

    externdef _imp___ismbblead:PTR c_msvcrt
    crt__ismbblead equ <_imp___ismbblead>

    externdef _imp___ismbbprint:PTR c_msvcrt
    crt__ismbbprint equ <_imp___ismbbprint>

    externdef _imp___ismbbpunct:PTR c_msvcrt
    crt__ismbbpunct equ <_imp___ismbbpunct>

    externdef _imp___ismbbtrail:PTR c_msvcrt
    crt__ismbbtrail equ <_imp___ismbbtrail>

    externdef _imp___ismbcalnum:PTR c_msvcrt
    crt__ismbcalnum equ <_imp___ismbcalnum>

    externdef _imp___ismbcalpha:PTR c_msvcrt
    crt__ismbcalpha equ <_imp___ismbcalpha>

    externdef _imp___ismbcdigit:PTR c_msvcrt
    crt__ismbcdigit equ <_imp___ismbcdigit>

    externdef _imp___ismbcgraph:PTR c_msvcrt
    crt__ismbcgraph equ <_imp___ismbcgraph>

    externdef _imp___ismbchira:PTR c_msvcrt
    crt__ismbchira equ <_imp___ismbchira>

    externdef _imp___ismbckata:PTR c_msvcrt
    crt__ismbckata equ <_imp___ismbckata>

    externdef _imp___ismbcl0:PTR c_msvcrt
    crt__ismbcl0 equ <_imp___ismbcl0>

    externdef _imp___ismbcl1:PTR c_msvcrt
    crt__ismbcl1 equ <_imp___ismbcl1>

    externdef _imp___ismbcl2:PTR c_msvcrt
    crt__ismbcl2 equ <_imp___ismbcl2>

    externdef _imp___ismbclegal:PTR c_msvcrt
    crt__ismbclegal equ <_imp___ismbclegal>

    externdef _imp___ismbclower:PTR c_msvcrt
    crt__ismbclower equ <_imp___ismbclower>

    externdef _imp___ismbcprint:PTR c_msvcrt
    crt__ismbcprint equ <_imp___ismbcprint>

    externdef _imp___ismbcpunct:PTR c_msvcrt
    crt__ismbcpunct equ <_imp___ismbcpunct>

    externdef _imp___ismbcspace:PTR c_msvcrt
    crt__ismbcspace equ <_imp___ismbcspace>

    externdef _imp___ismbcsymbol:PTR c_msvcrt
    crt__ismbcsymbol equ <_imp___ismbcsymbol>

    externdef _imp___ismbcupper:PTR c_msvcrt
    crt__ismbcupper equ <_imp___ismbcupper>

    externdef _imp___ismbslead:PTR c_msvcrt
    crt__ismbslead equ <_imp___ismbslead>

    externdef _imp___ismbstrail:PTR c_msvcrt
    crt__ismbstrail equ <_imp___ismbstrail>

    externdef _imp___isnan:PTR c_msvcrt
    crt__isnan equ <_imp___isnan>

    externdef _imp___itoa:PTR c_msvcrt
    crt__itoa equ <_imp___itoa>

    externdef _imp___itow:PTR c_msvcrt
    crt__itow equ <_imp___itow>

    externdef _imp___j0:PTR c_msvcrt
    crt__j0 equ <_imp___j0>

    externdef _imp___j1:PTR c_msvcrt
    crt__j1 equ <_imp___j1>

    externdef _imp___jn:PTR c_msvcrt
    crt__jn equ <_imp___jn>

    externdef _imp___kbhit:PTR c_msvcrt
    crt__kbhit equ <_imp___kbhit>

    externdef _imp___lfind:PTR c_msvcrt
    crt__lfind equ <_imp___lfind>

    externdef _imp___loaddll:PTR c_msvcrt
    crt__loaddll equ <_imp___loaddll>

    externdef _imp___local_unwind2:PTR c_msvcrt
    crt__local_unwind2 equ <_imp___local_unwind2>

    externdef _imp___localtime64:PTR c_msvcrt
    crt__localtime64 equ <_imp___localtime64>

    externdef _imp___lock:PTR c_msvcrt
    crt__lock equ <_imp___lock>

    externdef _imp___locking:PTR c_msvcrt
    crt__locking equ <_imp___locking>

    externdef _imp___logb:PTR c_msvcrt
    crt__logb equ <_imp___logb>

    externdef _imp___longjmpex:PTR c_msvcrt
    crt__longjmpex equ <_imp___longjmpex>

    externdef _imp___lrotl:PTR c_msvcrt
    crt__lrotl equ <_imp___lrotl>

    externdef _imp___lrotr:PTR c_msvcrt
    crt__lrotr equ <_imp___lrotr>

    externdef _imp___lsearch:PTR c_msvcrt
    crt__lsearch equ <_imp___lsearch>

    externdef _imp___lseek:PTR c_msvcrt
    crt__lseek equ <_imp___lseek>

    externdef _imp___lseeki64:PTR c_msvcrt
    crt__lseeki64 equ <_imp___lseeki64>

    externdef _imp___ltoa:PTR c_msvcrt
    crt__ltoa equ <_imp___ltoa>

    externdef _imp___ltow:PTR c_msvcrt
    crt__ltow equ <_imp___ltow>

    externdef _imp___makepath:PTR c_msvcrt
    crt__makepath equ <_imp___makepath>

    externdef _imp___mbbtombc:PTR c_msvcrt
    crt__mbbtombc equ <_imp___mbbtombc>

    externdef _imp___mbbtype:PTR c_msvcrt
    crt__mbbtype equ <_imp___mbbtype>

    externdef _imp___mbcasemap:PTR c_msvcrt
    crt__mbcasemap equ <_imp___mbcasemap>

    externdef _imp___mbccpy:PTR c_msvcrt
    crt__mbccpy equ <_imp___mbccpy>

    externdef _imp___mbcjistojms:PTR c_msvcrt
    crt__mbcjistojms equ <_imp___mbcjistojms>

    externdef _imp___mbcjmstojis:PTR c_msvcrt
    crt__mbcjmstojis equ <_imp___mbcjmstojis>

    externdef _imp___mbclen:PTR c_msvcrt
    crt__mbclen equ <_imp___mbclen>

    externdef _imp___mbctohira:PTR c_msvcrt
    crt__mbctohira equ <_imp___mbctohira>

    externdef _imp___mbctokata:PTR c_msvcrt
    crt__mbctokata equ <_imp___mbctokata>

    externdef _imp___mbctolower:PTR c_msvcrt
    crt__mbctolower equ <_imp___mbctolower>

    externdef _imp___mbctombb:PTR c_msvcrt
    crt__mbctombb equ <_imp___mbctombb>

    externdef _imp___mbctoupper:PTR c_msvcrt
    crt__mbctoupper equ <_imp___mbctoupper>

    externdef _imp___mbctype:PTR c_msvcrt
    crt__mbctype equ <_imp___mbctype>

    externdef _imp___mbsbtype:PTR c_msvcrt
    crt__mbsbtype equ <_imp___mbsbtype>

    externdef _imp___mbscat:PTR c_msvcrt
    crt__mbscat equ <_imp___mbscat>

    externdef _imp___mbschr:PTR c_msvcrt
    crt__mbschr equ <_imp___mbschr>

    externdef _imp___mbscmp:PTR c_msvcrt
    crt__mbscmp equ <_imp___mbscmp>

    externdef _imp___mbscoll:PTR c_msvcrt
    crt__mbscoll equ <_imp___mbscoll>

    externdef _imp___mbscpy:PTR c_msvcrt
    crt__mbscpy equ <_imp___mbscpy>

    externdef _imp___mbscspn:PTR c_msvcrt
    crt__mbscspn equ <_imp___mbscspn>

    externdef _imp___mbsdec:PTR c_msvcrt
    crt__mbsdec equ <_imp___mbsdec>

    externdef _imp___mbsdup:PTR c_msvcrt
    crt__mbsdup equ <_imp___mbsdup>

    externdef _imp___mbsicmp:PTR c_msvcrt
    crt__mbsicmp equ <_imp___mbsicmp>

    externdef _imp___mbsicoll:PTR c_msvcrt
    crt__mbsicoll equ <_imp___mbsicoll>

    externdef _imp___mbsinc:PTR c_msvcrt
    crt__mbsinc equ <_imp___mbsinc>

    externdef _imp___mbslen:PTR c_msvcrt
    crt__mbslen equ <_imp___mbslen>

    externdef _imp___mbslwr:PTR c_msvcrt
    crt__mbslwr equ <_imp___mbslwr>

    externdef _imp___mbsnbcat:PTR c_msvcrt
    crt__mbsnbcat equ <_imp___mbsnbcat>

    externdef _imp___mbsnbcmp:PTR c_msvcrt
    crt__mbsnbcmp equ <_imp___mbsnbcmp>

    externdef _imp___mbsnbcnt:PTR c_msvcrt
    crt__mbsnbcnt equ <_imp___mbsnbcnt>

    externdef _imp___mbsnbcoll:PTR c_msvcrt
    crt__mbsnbcoll equ <_imp___mbsnbcoll>

    externdef _imp___mbsnbcpy:PTR c_msvcrt
    crt__mbsnbcpy equ <_imp___mbsnbcpy>

    externdef _imp___mbsnbicmp:PTR c_msvcrt
    crt__mbsnbicmp equ <_imp___mbsnbicmp>

    externdef _imp___mbsnbicoll:PTR c_msvcrt
    crt__mbsnbicoll equ <_imp___mbsnbicoll>

    externdef _imp___mbsnbset:PTR c_msvcrt
    crt__mbsnbset equ <_imp___mbsnbset>

    externdef _imp___mbsncat:PTR c_msvcrt
    crt__mbsncat equ <_imp___mbsncat>

    externdef _imp___mbsnccnt:PTR c_msvcrt
    crt__mbsnccnt equ <_imp___mbsnccnt>

    externdef _imp___mbsncmp:PTR c_msvcrt
    crt__mbsncmp equ <_imp___mbsncmp>

    externdef _imp___mbsncoll:PTR c_msvcrt
    crt__mbsncoll equ <_imp___mbsncoll>

    externdef _imp___mbsncpy:PTR c_msvcrt
    crt__mbsncpy equ <_imp___mbsncpy>

    externdef _imp___mbsnextc:PTR c_msvcrt
    crt__mbsnextc equ <_imp___mbsnextc>

    externdef _imp___mbsnicmp:PTR c_msvcrt
    crt__mbsnicmp equ <_imp___mbsnicmp>

    externdef _imp___mbsnicoll:PTR c_msvcrt
    crt__mbsnicoll equ <_imp___mbsnicoll>

    externdef _imp___mbsninc:PTR c_msvcrt
    crt__mbsninc equ <_imp___mbsninc>

    externdef _imp___mbsnset:PTR c_msvcrt
    crt__mbsnset equ <_imp___mbsnset>

    externdef _imp___mbspbrk:PTR c_msvcrt
    crt__mbspbrk equ <_imp___mbspbrk>

    externdef _imp___mbsrchr:PTR c_msvcrt
    crt__mbsrchr equ <_imp___mbsrchr>

    externdef _imp___mbsrev:PTR c_msvcrt
    crt__mbsrev equ <_imp___mbsrev>

    externdef _imp___mbsset:PTR c_msvcrt
    crt__mbsset equ <_imp___mbsset>

    externdef _imp___mbsspn:PTR c_msvcrt
    crt__mbsspn equ <_imp___mbsspn>

    externdef _imp___mbsspnp:PTR c_msvcrt
    crt__mbsspnp equ <_imp___mbsspnp>

    externdef _imp___mbsstr:PTR c_msvcrt
    crt__mbsstr equ <_imp___mbsstr>

    externdef _imp___mbstok:PTR c_msvcrt
    crt__mbstok equ <_imp___mbstok>

    externdef _imp___mbstrlen:PTR c_msvcrt
    crt__mbstrlen equ <_imp___mbstrlen>

    externdef _imp___mbsupr:PTR c_msvcrt
    crt__mbsupr equ <_imp___mbsupr>

    externdef _imp___memccpy:PTR c_msvcrt
    crt__memccpy equ <_imp___memccpy>

    externdef _imp___memicmp:PTR c_msvcrt
    crt__memicmp equ <_imp___memicmp>

    externdef _imp___mkdir:PTR c_msvcrt
    crt__mkdir equ <_imp___mkdir>

    externdef _imp___mktemp:PTR c_msvcrt
    crt__mktemp equ <_imp___mktemp>

    externdef _imp___mktime64:PTR c_msvcrt
    crt__mktime64 equ <_imp___mktime64>

    externdef _imp___msize:PTR c_msvcrt
    crt__msize equ <_imp___msize>

    externdef _imp___nextafter:PTR c_msvcrt
    crt__nextafter equ <_imp___nextafter>

    externdef _imp___onexit:PTR c_msvcrt
    crt__onexit equ <_imp___onexit>

    externdef _imp___open:PTR c_msvcrt
    crt__open equ <_imp___open>

    externdef _imp___open_osfhandle:PTR c_msvcrt
    crt__open_osfhandle equ <_imp___open_osfhandle>

    externdef _imp___osplatform:PTR c_msvcrt
    crt__osplatform equ <_imp___osplatform>

    externdef _imp___osver:PTR c_msvcrt
    crt__osver equ <_imp___osver>

    externdef _imp___outp:PTR c_msvcrt
    crt__outp equ <_imp___outp>

    externdef _imp___outpd:PTR c_msvcrt
    crt__outpd equ <_imp___outpd>

    externdef _imp___outpw:PTR c_msvcrt
    crt__outpw equ <_imp___outpw>

    externdef _imp___pclose:PTR c_msvcrt
    crt__pclose equ <_imp___pclose>

    externdef _imp___pctype:PTR c_msvcrt
    crt__pctype equ <_imp___pctype>

    externdef _imp___pgmptr:PTR c_msvcrt
    crt__pgmptr equ <_imp___pgmptr>

    externdef _imp___pipe:PTR c_msvcrt
    crt__pipe equ <_imp___pipe>

    externdef _imp___popen:PTR c_msvcrt
    crt__popen equ <_imp___popen>

    externdef _imp___purecall:PTR c_msvcrt
    crt__purecall equ <_imp___purecall>

    externdef _imp___putch:PTR c_msvcrt
    crt__putch equ <_imp___putch>

    externdef _imp___putenv:PTR c_msvcrt
    crt__putenv equ <_imp___putenv>

    externdef _imp___putw:PTR c_msvcrt
    crt__putw equ <_imp___putw>

    externdef _imp___putws:PTR c_msvcrt
    crt__putws equ <_imp___putws>

    externdef _imp___pwctype:PTR c_msvcrt
    crt__pwctype equ <_imp___pwctype>

    externdef _imp___read:PTR c_msvcrt
    crt__read equ <_imp___read>

    externdef _imp___rmdir:PTR c_msvcrt
    crt__rmdir equ <_imp___rmdir>

    externdef _imp___rmtmp:PTR c_msvcrt
    crt__rmtmp equ <_imp___rmtmp>

    externdef _imp___rotl:PTR c_msvcrt
    crt__rotl equ <_imp___rotl>

    externdef _imp___rotr:PTR c_msvcrt
    crt__rotr equ <_imp___rotr>

    externdef _imp___safe_fdiv:PTR c_msvcrt
    crt__safe_fdiv equ <_imp___safe_fdiv>

    externdef _imp___safe_fdivr:PTR c_msvcrt
    crt__safe_fdivr equ <_imp___safe_fdivr>

    externdef _imp___safe_fprem:PTR c_msvcrt
    crt__safe_fprem equ <_imp___safe_fprem>

    externdef _imp___safe_fprem1:PTR c_msvcrt
    crt__safe_fprem1 equ <_imp___safe_fprem1>

    externdef _imp___scalb:PTR c_msvcrt
    crt__scalb equ <_imp___scalb>

    externdef _imp___searchenv:PTR c_msvcrt
    crt__searchenv equ <_imp___searchenv>

    externdef _imp___seh_longjmp_unwind:PTR c_msvcrt
    crt__seh_longjmp_unwind equ <_imp___seh_longjmp_unwind>

    externdef _imp___set_error_mode:PTR c_msvcrt
    crt__set_error_mode equ <_imp___set_error_mode>

    externdef _imp___set_sbh_threshold:PTR c_msvcrt
    crt__set_sbh_threshold equ <_imp___set_sbh_threshold>

    externdef _imp___seterrormode:PTR c_msvcrt
    crt__seterrormode equ <_imp___seterrormode>

    externdef _imp___setjmp:PTR c_msvcrt
    crt__setjmp equ <_imp___setjmp>

    externdef _imp___setjmp3:PTR c_msvcrt
    crt__setjmp3 equ <_imp___setjmp3>

    externdef _imp___setmaxstdio:PTR c_msvcrt
    crt__setmaxstdio equ <_imp___setmaxstdio>

    externdef _imp___setmbcp:PTR c_msvcrt
    crt__setmbcp equ <_imp___setmbcp>

    externdef _imp___setmode:PTR c_msvcrt
    crt__setmode equ <_imp___setmode>

    externdef _imp___setsystime:PTR c_msvcrt
    crt__setsystime equ <_imp___setsystime>

    externdef _imp___sleep:PTR c_msvcrt
    crt__sleep equ <_imp___sleep>

    externdef _imp___snprintf:PTR c_msvcrt
    crt__snprintf equ <_imp___snprintf>

    externdef _imp___snwprintf:PTR c_msvcrt
    crt__snwprintf equ <_imp___snwprintf>

    externdef _imp___sopen:PTR c_msvcrt
    crt__sopen equ <_imp___sopen>

    externdef _imp___spawnl:PTR c_msvcrt
    crt__spawnl equ <_imp___spawnl>

    externdef _imp___spawnle:PTR c_msvcrt
    crt__spawnle equ <_imp___spawnle>

    externdef _imp___spawnlp:PTR c_msvcrt
    crt__spawnlp equ <_imp___spawnlp>

    externdef _imp___spawnlpe:PTR c_msvcrt
    crt__spawnlpe equ <_imp___spawnlpe>

    externdef _imp___spawnv:PTR c_msvcrt
    crt__spawnv equ <_imp___spawnv>

    externdef _imp___spawnve:PTR c_msvcrt
    crt__spawnve equ <_imp___spawnve>

    externdef _imp___spawnvp:PTR c_msvcrt
    crt__spawnvp equ <_imp___spawnvp>

    externdef _imp___spawnvpe:PTR c_msvcrt
    crt__spawnvpe equ <_imp___spawnvpe>

    externdef _imp___splitpath:PTR c_msvcrt
    crt__splitpath equ <_imp___splitpath>

    externdef _imp___stat:PTR c_msvcrt
    crt__stat equ <_imp___stat>

    externdef _imp___stat64:PTR c_msvcrt
    crt__stat64 equ <_imp___stat64>

    externdef _imp___stati64:PTR c_msvcrt
    crt__stati64 equ <_imp___stati64>

    externdef _imp___statusfp:PTR c_msvcrt
    crt__statusfp equ <_imp___statusfp>

    externdef _imp___strcmpi:PTR c_msvcrt
    crt__strcmpi equ <_imp___strcmpi>

    externdef _imp___strdate:PTR c_msvcrt
    crt__strdate equ <_imp___strdate>

    externdef _imp___strdup:PTR c_msvcrt
    crt__strdup equ <_imp___strdup>

    externdef _imp___strerror:PTR c_msvcrt
    crt__strerror equ <_imp___strerror>

    externdef _imp___stricmp:PTR c_msvcrt
    crt__stricmp equ <_imp___stricmp>

    externdef _imp___stricoll:PTR c_msvcrt
    crt__stricoll equ <_imp___stricoll>

    externdef _imp___strlwr:PTR c_msvcrt
    crt__strlwr equ <_imp___strlwr>

    externdef _imp___strncoll:PTR c_msvcrt
    crt__strncoll equ <_imp___strncoll>

    externdef _imp___strnicmp:PTR c_msvcrt
    crt__strnicmp equ <_imp___strnicmp>

    externdef _imp___strnicoll:PTR c_msvcrt
    crt__strnicoll equ <_imp___strnicoll>

    externdef _imp___strnset:PTR c_msvcrt
    crt__strnset equ <_imp___strnset>

    externdef _imp___strrev:PTR c_msvcrt
    crt__strrev equ <_imp___strrev>

    externdef _imp___strset:PTR c_msvcrt
    crt__strset equ <_imp___strset>

    externdef _imp___strtime:PTR c_msvcrt
    crt__strtime equ <_imp___strtime>

    externdef _imp___strupr:PTR c_msvcrt
    crt__strupr equ <_imp___strupr>

    externdef _imp___swab:PTR c_msvcrt
    crt__swab equ <_imp___swab>

    externdef _imp___sys_errlist:PTR c_msvcrt
    crt__sys_errlist equ <_imp___sys_errlist>

    externdef _imp___sys_nerr:PTR c_msvcrt
    crt__sys_nerr equ <_imp___sys_nerr>

    externdef _imp___tell:PTR c_msvcrt
    crt__tell equ <_imp___tell>

    externdef _imp___telli64:PTR c_msvcrt
    crt__telli64 equ <_imp___telli64>

    externdef _imp___tempnam:PTR c_msvcrt
    crt__tempnam equ <_imp___tempnam>

    externdef _imp___time64:PTR c_msvcrt
    crt__time64 equ <_imp___time64>

    externdef _imp___timezone:PTR c_msvcrt
    crt__timezone equ <_imp___timezone>

    externdef _imp___tolower:PTR c_msvcrt
    crt__tolower equ <_imp___tolower>

    externdef _imp___toupper:PTR c_msvcrt
    crt__toupper equ <_imp___toupper>

    externdef _imp___tzname:PTR c_msvcrt
    crt__tzname equ <_imp___tzname>

    externdef _imp___tzset:PTR c_msvcrt
    crt__tzset equ <_imp___tzset>

    externdef _imp___ui64toa:PTR c_msvcrt
    crt__ui64toa equ <_imp___ui64toa>

    externdef _imp___ui64tow:PTR c_msvcrt
    crt__ui64tow equ <_imp___ui64tow>

    externdef _imp___ultoa:PTR c_msvcrt
    crt__ultoa equ <_imp___ultoa>

    externdef _imp___ultow:PTR c_msvcrt
    crt__ultow equ <_imp___ultow>

    externdef _imp___umask:PTR c_msvcrt
    crt__umask equ <_imp___umask>

    externdef _imp___ungetch:PTR c_msvcrt
    crt__ungetch equ <_imp___ungetch>

    externdef _imp___unlink:PTR c_msvcrt
    crt__unlink equ <_imp___unlink>

    externdef _imp___unloaddll:PTR c_msvcrt
    crt__unloaddll equ <_imp___unloaddll>

    externdef _imp___unlock:PTR c_msvcrt
    crt__unlock equ <_imp___unlock>

    externdef _imp___utime:PTR c_msvcrt
    crt__utime equ <_imp___utime>

    externdef _imp___utime64:PTR c_msvcrt
    crt__utime64 equ <_imp___utime64>

    externdef _imp___vsnprintf:PTR c_msvcrt
    crt__vsnprintf equ <_imp___vsnprintf>

    externdef _imp___vsnwprintf:PTR c_msvcrt
    crt__vsnwprintf equ <_imp___vsnwprintf>

    externdef _imp___waccess:PTR c_msvcrt
    crt__waccess equ <_imp___waccess>

    externdef _imp___wasctime:PTR c_msvcrt
    crt__wasctime equ <_imp___wasctime>

    externdef _imp___wchdir:PTR c_msvcrt
    crt__wchdir equ <_imp___wchdir>

    externdef _imp___wchmod:PTR c_msvcrt
    crt__wchmod equ <_imp___wchmod>

    externdef _imp___wcmdln:PTR c_msvcrt
    crt__wcmdln equ <_imp___wcmdln>

    externdef _imp___wcreat:PTR c_msvcrt
    crt__wcreat equ <_imp___wcreat>

    externdef _imp___wcsdup:PTR c_msvcrt
    crt__wcsdup equ <_imp___wcsdup>

    externdef _imp___wcsicmp:PTR c_msvcrt
    crt__wcsicmp equ <_imp___wcsicmp>

    externdef _imp___wcsicoll:PTR c_msvcrt
    crt__wcsicoll equ <_imp___wcsicoll>

    externdef _imp___wcslwr:PTR c_msvcrt
    crt__wcslwr equ <_imp___wcslwr>

    externdef _imp___wcsncoll:PTR c_msvcrt
    crt__wcsncoll equ <_imp___wcsncoll>

    externdef _imp___wcsnicmp:PTR c_msvcrt
    crt__wcsnicmp equ <_imp___wcsnicmp>

    externdef _imp___wcsnicoll:PTR c_msvcrt
    crt__wcsnicoll equ <_imp___wcsnicoll>

    externdef _imp___wcsnset:PTR c_msvcrt
    crt__wcsnset equ <_imp___wcsnset>

    externdef _imp___wcsrev:PTR c_msvcrt
    crt__wcsrev equ <_imp___wcsrev>

    externdef _imp___wcsset:PTR c_msvcrt
    crt__wcsset equ <_imp___wcsset>

    externdef _imp___wcsupr:PTR c_msvcrt
    crt__wcsupr equ <_imp___wcsupr>

    externdef _imp___wctime:PTR c_msvcrt
    crt__wctime equ <_imp___wctime>

    externdef _imp___wctime64:PTR c_msvcrt
    crt__wctime64 equ <_imp___wctime64>

    externdef _imp___wenviron:PTR c_msvcrt
    crt__wenviron equ <_imp___wenviron>

    externdef _imp___wexecl:PTR c_msvcrt
    crt__wexecl equ <_imp___wexecl>

    externdef _imp___wexecle:PTR c_msvcrt
    crt__wexecle equ <_imp___wexecle>

    externdef _imp___wexeclp:PTR c_msvcrt
    crt__wexeclp equ <_imp___wexeclp>

    externdef _imp___wexeclpe:PTR c_msvcrt
    crt__wexeclpe equ <_imp___wexeclpe>

    externdef _imp___wexecv:PTR c_msvcrt
    crt__wexecv equ <_imp___wexecv>

    externdef _imp___wexecve:PTR c_msvcrt
    crt__wexecve equ <_imp___wexecve>

    externdef _imp___wexecvp:PTR c_msvcrt
    crt__wexecvp equ <_imp___wexecvp>

    externdef _imp___wexecvpe:PTR c_msvcrt
    crt__wexecvpe equ <_imp___wexecvpe>

    externdef _imp___wfdopen:PTR c_msvcrt
    crt__wfdopen equ <_imp___wfdopen>

    externdef _imp___wfindfirst:PTR c_msvcrt
    crt__wfindfirst equ <_imp___wfindfirst>

    externdef _imp___wfindfirst64:PTR c_msvcrt
    crt__wfindfirst64 equ <_imp___wfindfirst64>

    externdef _imp___wfindfirsti64:PTR c_msvcrt
    crt__wfindfirsti64 equ <_imp___wfindfirsti64>

    externdef _imp___wfindnext:PTR c_msvcrt
    crt__wfindnext equ <_imp___wfindnext>

    externdef _imp___wfindnext64:PTR c_msvcrt
    crt__wfindnext64 equ <_imp___wfindnext64>

    externdef _imp___wfindnexti64:PTR c_msvcrt
    crt__wfindnexti64 equ <_imp___wfindnexti64>

    externdef _imp___wfopen:PTR c_msvcrt
    crt__wfopen equ <_imp___wfopen>

    externdef _imp___wfreopen:PTR c_msvcrt
    crt__wfreopen equ <_imp___wfreopen>

    externdef _imp___wfsopen:PTR c_msvcrt
    crt__wfsopen equ <_imp___wfsopen>

    externdef _imp___wfullpath:PTR c_msvcrt
    crt__wfullpath equ <_imp___wfullpath>

    externdef _imp___wgetcwd:PTR c_msvcrt
    crt__wgetcwd equ <_imp___wgetcwd>

    externdef _imp___wgetdcwd:PTR c_msvcrt
    crt__wgetdcwd equ <_imp___wgetdcwd>

    externdef _imp___wgetenv:PTR c_msvcrt
    crt__wgetenv equ <_imp___wgetenv>

    externdef _imp___winmajor:PTR c_msvcrt
    crt__winmajor equ <_imp___winmajor>

    externdef _imp___winminor:PTR c_msvcrt
    crt__winminor equ <_imp___winminor>

    externdef _imp___winver:PTR c_msvcrt
    crt__winver equ <_imp___winver>

    externdef _imp___wmakepath:PTR c_msvcrt
    crt__wmakepath equ <_imp___wmakepath>

    externdef _imp___wmkdir:PTR c_msvcrt
    crt__wmkdir equ <_imp___wmkdir>

    externdef _imp___wmktemp:PTR c_msvcrt
    crt__wmktemp equ <_imp___wmktemp>

    externdef _imp___wopen:PTR c_msvcrt
    crt__wopen equ <_imp___wopen>

    externdef _imp___wperror:PTR c_msvcrt
    crt__wperror equ <_imp___wperror>

    externdef _imp___wpgmptr:PTR c_msvcrt
    crt__wpgmptr equ <_imp___wpgmptr>

    externdef _imp___wpopen:PTR c_msvcrt
    crt__wpopen equ <_imp___wpopen>

    externdef _imp___wputenv:PTR c_msvcrt
    crt__wputenv equ <_imp___wputenv>

    externdef _imp___wremove:PTR c_msvcrt
    crt__wremove equ <_imp___wremove>

    externdef _imp___wrename:PTR c_msvcrt
    crt__wrename equ <_imp___wrename>

    externdef _imp___write:PTR c_msvcrt
    crt__write equ <_imp___write>

    externdef _imp___wrmdir:PTR c_msvcrt
    crt__wrmdir equ <_imp___wrmdir>

    externdef _imp___wsearchenv:PTR c_msvcrt
    crt__wsearchenv equ <_imp___wsearchenv>

    externdef _imp___wsetlocale:PTR c_msvcrt
    crt__wsetlocale equ <_imp___wsetlocale>

    externdef _imp___wsopen:PTR c_msvcrt
    crt__wsopen equ <_imp___wsopen>

    externdef _imp___wspawnl:PTR c_msvcrt
    crt__wspawnl equ <_imp___wspawnl>

    externdef _imp___wspawnle:PTR c_msvcrt
    crt__wspawnle equ <_imp___wspawnle>

    externdef _imp___wspawnlp:PTR c_msvcrt
    crt__wspawnlp equ <_imp___wspawnlp>

    externdef _imp___wspawnlpe:PTR c_msvcrt
    crt__wspawnlpe equ <_imp___wspawnlpe>

    externdef _imp___wspawnv:PTR c_msvcrt
    crt__wspawnv equ <_imp___wspawnv>

    externdef _imp___wspawnve:PTR c_msvcrt
    crt__wspawnve equ <_imp___wspawnve>

    externdef _imp___wspawnvp:PTR c_msvcrt
    crt__wspawnvp equ <_imp___wspawnvp>

    externdef _imp___wspawnvpe:PTR c_msvcrt
    crt__wspawnvpe equ <_imp___wspawnvpe>

    externdef _imp___wsplitpath:PTR c_msvcrt
    crt__wsplitpath equ <_imp___wsplitpath>

    externdef _imp___wstat:PTR c_msvcrt
    crt__wstat equ <_imp___wstat>

    externdef _imp___wstat64:PTR c_msvcrt
    crt__wstat64 equ <_imp___wstat64>

    externdef _imp___wstati64:PTR c_msvcrt
    crt__wstati64 equ <_imp___wstati64>

    externdef _imp___wstrdate:PTR c_msvcrt
    crt__wstrdate equ <_imp___wstrdate>

    externdef _imp___wstrtime:PTR c_msvcrt
    crt__wstrtime equ <_imp___wstrtime>

    externdef _imp___wsystem:PTR c_msvcrt
    crt__wsystem equ <_imp___wsystem>

    externdef _imp___wtempnam:PTR c_msvcrt
    crt__wtempnam equ <_imp___wtempnam>

    externdef _imp___wtmpnam:PTR c_msvcrt
    crt__wtmpnam equ <_imp___wtmpnam>

    externdef _imp___wtoi:PTR c_msvcrt
    crt__wtoi equ <_imp___wtoi>

    externdef _imp___wtoi64:PTR c_msvcrt
    crt__wtoi64 equ <_imp___wtoi64>

    externdef _imp___wtol:PTR c_msvcrt
    crt__wtol equ <_imp___wtol>

    externdef _imp___wunlink:PTR c_msvcrt
    crt__wunlink equ <_imp___wunlink>

    externdef _imp___wutime:PTR c_msvcrt
    crt__wutime equ <_imp___wutime>

    externdef _imp___wutime64:PTR c_msvcrt
    crt__wutime64 equ <_imp___wutime64>

    externdef _imp___y0:PTR c_msvcrt
    crt__y0 equ <_imp___y0>

    externdef _imp___y1:PTR c_msvcrt
    crt__y1 equ <_imp___y1>

    externdef _imp___yn:PTR c_msvcrt
    crt__yn equ <_imp___yn>

    externdef _imp__abort:PTR c_msvcrt
    crt_abort equ <_imp__abort>

    externdef _imp__abs:PTR c_msvcrt
    crt_abs equ <_imp__abs>

    externdef _imp__acos:PTR c_msvcrt
    crt_acos equ <_imp__acos>

    externdef _imp__asctime:PTR c_msvcrt
    crt_asctime equ <_imp__asctime>

    externdef _imp__asin:PTR c_msvcrt
    crt_asin equ <_imp__asin>

    externdef _imp__atan:PTR c_msvcrt
    crt_atan equ <_imp__atan>

    externdef _imp__atan2:PTR c_msvcrt
    crt_atan2 equ <_imp__atan2>

    externdef _imp__atexit:PTR c_msvcrt
    crt_atexit equ <_imp__atexit>

    externdef _imp__atof:PTR c_msvcrt
    crt_atof equ <_imp__atof>

    externdef _imp__atoi:PTR c_msvcrt
    crt_atoi equ <_imp__atoi>

    externdef _imp__atol:PTR c_msvcrt
    crt_atol equ <_imp__atol>

    externdef _imp__bsearch:PTR c_msvcrt
    crt_bsearch equ <_imp__bsearch>

    externdef _imp__calloc:PTR c_msvcrt
    crt_calloc equ <_imp__calloc>

    externdef _imp__ceil:PTR c_msvcrt
    crt_ceil equ <_imp__ceil>

    externdef _imp__clearerr:PTR c_msvcrt
    crt_clearerr equ <_imp__clearerr>

    externdef _imp__clock:PTR c_msvcrt
    crt_clock equ <_imp__clock>

    externdef _imp__cos:PTR c_msvcrt
    crt_cos equ <_imp__cos>

    externdef _imp__cosh:PTR c_msvcrt
    crt_cosh equ <_imp__cosh>

    externdef _imp__ctime:PTR c_msvcrt
    crt_ctime equ <_imp__ctime>

    externdef _imp__difftime:PTR c_msvcrt
    crt_difftime equ <_imp__difftime>

    externdef _imp__div:PTR c_msvcrt
    crt_div equ <_imp__div>

    externdef _imp__exit:PTR c_msvcrt
    crt_exit equ <_imp__exit>

    externdef _imp__exp:PTR c_msvcrt
    crt_exp equ <_imp__exp>

    externdef _imp__fabs:PTR c_msvcrt
    crt_fabs equ <_imp__fabs>

    externdef _imp__fclose:PTR c_msvcrt
    crt_fclose equ <_imp__fclose>

    externdef _imp__feof:PTR c_msvcrt
    crt_feof equ <_imp__feof>

    externdef _imp__ferror:PTR c_msvcrt
    crt_ferror equ <_imp__ferror>

    externdef _imp__fflush:PTR c_msvcrt
    crt_fflush equ <_imp__fflush>

    externdef _imp__fgetc:PTR c_msvcrt
    crt_fgetc equ <_imp__fgetc>

    externdef _imp__fgetpos:PTR c_msvcrt
    crt_fgetpos equ <_imp__fgetpos>

    externdef _imp__fgets:PTR c_msvcrt
    crt_fgets equ <_imp__fgets>

    externdef _imp__fgetwc:PTR c_msvcrt
    crt_fgetwc equ <_imp__fgetwc>

    externdef _imp__fgetws:PTR c_msvcrt
    crt_fgetws equ <_imp__fgetws>

    externdef _imp__floor:PTR c_msvcrt
    crt_floor equ <_imp__floor>

    externdef _imp__fmod:PTR c_msvcrt
    crt_fmod equ <_imp__fmod>

    externdef _imp__fopen:PTR c_msvcrt
    crt_fopen equ <_imp__fopen>

    externdef _imp__fprintf:PTR c_msvcrt
    crt_fprintf equ <_imp__fprintf>

    externdef _imp__fputc:PTR c_msvcrt
    crt_fputc equ <_imp__fputc>

    externdef _imp__fputs:PTR c_msvcrt
    crt_fputs equ <_imp__fputs>

    externdef _imp__fputwc:PTR c_msvcrt
    crt_fputwc equ <_imp__fputwc>

    externdef _imp__fputws:PTR c_msvcrt
    crt_fputws equ <_imp__fputws>

    externdef _imp__fread:PTR c_msvcrt
    crt_fread equ <_imp__fread>

    externdef _imp__free:PTR c_msvcrt
    crt_free equ <_imp__free>

    externdef _imp__freopen:PTR c_msvcrt
    crt_freopen equ <_imp__freopen>

    externdef _imp__frexp:PTR c_msvcrt
    crt_frexp equ <_imp__frexp>

    externdef _imp__fscanf:PTR c_msvcrt
    crt_fscanf equ <_imp__fscanf>

    externdef _imp__fseek:PTR c_msvcrt
    crt_fseek equ <_imp__fseek>

    externdef _imp__fsetpos:PTR c_msvcrt
    crt_fsetpos equ <_imp__fsetpos>

    externdef _imp__ftell:PTR c_msvcrt
    crt_ftell equ <_imp__ftell>

    externdef _imp__fwprintf:PTR c_msvcrt
    crt_fwprintf equ <_imp__fwprintf>

    externdef _imp__fwrite:PTR c_msvcrt
    crt_fwrite equ <_imp__fwrite>

    externdef _imp__fwscanf:PTR c_msvcrt
    crt_fwscanf equ <_imp__fwscanf>

    externdef _imp__getc:PTR c_msvcrt
    crt_getc equ <_imp__getc>

    externdef _imp__getchar:PTR c_msvcrt
    crt_getchar equ <_imp__getchar>

    externdef _imp__getenv:PTR c_msvcrt
    crt_getenv equ <_imp__getenv>

    externdef _imp__gets:PTR c_msvcrt
    crt_gets equ <_imp__gets>

    externdef _imp__getwc:PTR c_msvcrt
    crt_getwc equ <_imp__getwc>

    externdef _imp__getwchar:PTR c_msvcrt
    crt_getwchar equ <_imp__getwchar>

    externdef _imp__gmtime:PTR c_msvcrt
    crt_gmtime equ <_imp__gmtime>

    externdef _imp__is_wctype:PTR c_msvcrt
    crt_is_wctype equ <_imp__is_wctype>

    externdef _imp__isalnum:PTR c_msvcrt
    crt_isalnum equ <_imp__isalnum>

    externdef _imp__isalpha:PTR c_msvcrt
    crt_isalpha equ <_imp__isalpha>

    externdef _imp__iscntrl:PTR c_msvcrt
    crt_iscntrl equ <_imp__iscntrl>

    externdef _imp__isdigit:PTR c_msvcrt
    crt_isdigit equ <_imp__isdigit>

    externdef _imp__isgraph:PTR c_msvcrt
    crt_isgraph equ <_imp__isgraph>

    externdef _imp__isleadbyte:PTR c_msvcrt
    crt_isleadbyte equ <_imp__isleadbyte>

    externdef _imp__islower:PTR c_msvcrt
    crt_islower equ <_imp__islower>

    externdef _imp__isprint:PTR c_msvcrt
    crt_isprint equ <_imp__isprint>

    externdef _imp__ispunct:PTR c_msvcrt
    crt_ispunct equ <_imp__ispunct>

    externdef _imp__isspace:PTR c_msvcrt
    crt_isspace equ <_imp__isspace>

    externdef _imp__isupper:PTR c_msvcrt
    crt_isupper equ <_imp__isupper>

    externdef _imp__iswalnum:PTR c_msvcrt
    crt_iswalnum equ <_imp__iswalnum>

    externdef _imp__iswalpha:PTR c_msvcrt
    crt_iswalpha equ <_imp__iswalpha>

    externdef _imp__iswascii:PTR c_msvcrt
    crt_iswascii equ <_imp__iswascii>

    externdef _imp__iswcntrl:PTR c_msvcrt
    crt_iswcntrl equ <_imp__iswcntrl>

    externdef _imp__iswctype:PTR c_msvcrt
    crt_iswctype equ <_imp__iswctype>

    externdef _imp__iswdigit:PTR c_msvcrt
    crt_iswdigit equ <_imp__iswdigit>

    externdef _imp__iswgraph:PTR c_msvcrt
    crt_iswgraph equ <_imp__iswgraph>

    externdef _imp__iswlower:PTR c_msvcrt
    crt_iswlower equ <_imp__iswlower>

    externdef _imp__iswprint:PTR c_msvcrt
    crt_iswprint equ <_imp__iswprint>

    externdef _imp__iswpunct:PTR c_msvcrt
    crt_iswpunct equ <_imp__iswpunct>

    externdef _imp__iswspace:PTR c_msvcrt
    crt_iswspace equ <_imp__iswspace>

    externdef _imp__iswupper:PTR c_msvcrt
    crt_iswupper equ <_imp__iswupper>

    externdef _imp__iswxdigit:PTR c_msvcrt
    crt_iswxdigit equ <_imp__iswxdigit>

    externdef _imp__isxdigit:PTR c_msvcrt
    crt_isxdigit equ <_imp__isxdigit>

    externdef _imp__labs:PTR c_msvcrt
    crt_labs equ <_imp__labs>

    externdef _imp__ldexp:PTR c_msvcrt
    crt_ldexp equ <_imp__ldexp>

    externdef _imp__ldiv:PTR c_msvcrt
    crt_ldiv equ <_imp__ldiv>

    externdef _imp__localeconv:PTR c_msvcrt
    crt_localeconv equ <_imp__localeconv>

    externdef _imp__localtime:PTR c_msvcrt
    crt_localtime equ <_imp__localtime>

    externdef _imp__log:PTR c_msvcrt
    crt_log equ <_imp__log>

    externdef _imp__log10:PTR c_msvcrt
    crt_log10 equ <_imp__log10>

    externdef _imp__longjmp:PTR c_msvcrt
    crt_longjmp equ <_imp__longjmp>

    externdef _imp__malloc:PTR c_msvcrt
    crt_malloc equ <_imp__malloc>

    externdef _imp__mblen:PTR c_msvcrt
    crt_mblen equ <_imp__mblen>

    externdef _imp__mbstowcs:PTR c_msvcrt
    crt_mbstowcs equ <_imp__mbstowcs>

    externdef _imp__mbtowc:PTR c_msvcrt
    crt_mbtowc equ <_imp__mbtowc>

    externdef _imp__memchr:PTR c_msvcrt
    crt_memchr equ <_imp__memchr>

    externdef _imp__memcmp:PTR c_msvcrt
    crt_memcmp equ <_imp__memcmp>

    externdef _imp__memcpy:PTR c_msvcrt
    crt_memcpy equ <_imp__memcpy>

    externdef _imp__memmove:PTR c_msvcrt
    crt_memmove equ <_imp__memmove>

    externdef _imp__memset:PTR c_msvcrt
    crt_memset equ <_imp__memset>

    externdef _imp__mktime:PTR c_msvcrt
    crt_mktime equ <_imp__mktime>

    externdef _imp__modf:PTR c_msvcrt
    crt_modf equ <_imp__modf>

    externdef _imp__perror:PTR c_msvcrt
    crt_perror equ <_imp__perror>

    externdef _imp__pow:PTR c_msvcrt
    crt_pow equ <_imp__pow>

    externdef _imp__printf:PTR c_msvcrt
    crt_printf equ <_imp__printf>

    externdef _imp__putc:PTR c_msvcrt
    crt_putc equ <_imp__putc>

    externdef _imp__putchar:PTR c_msvcrt
    crt_putchar equ <_imp__putchar>

    externdef _imp__puts:PTR c_msvcrt
    crt_puts equ <_imp__puts>

    externdef _imp__putwc:PTR c_msvcrt
    crt_putwc equ <_imp__putwc>

    externdef _imp__putwchar:PTR c_msvcrt
    crt_putwchar equ <_imp__putwchar>

    externdef _imp__qsort:PTR c_msvcrt
    crt_qsort equ <_imp__qsort>

    externdef _imp__raise:PTR c_msvcrt
    crt_raise equ <_imp__raise>

    externdef _imp__rand:PTR c_msvcrt
    crt_rand equ <_imp__rand>

    externdef _imp__realloc:PTR c_msvcrt
    crt_realloc equ <_imp__realloc>

    externdef _imp__remove:PTR c_msvcrt
    crt_remove equ <_imp__remove>

    externdef _imp__rename:PTR c_msvcrt
    crt_rename equ <_imp__rename>

    externdef _imp__rewind:PTR c_msvcrt
    crt_rewind equ <_imp__rewind>

    externdef _imp__scanf:PTR c_msvcrt
    crt_scanf equ <_imp__scanf>

    externdef _imp__setbuf:PTR c_msvcrt
    crt_setbuf equ <_imp__setbuf>

    externdef _imp__setlocale:PTR c_msvcrt
    crt_setlocale equ <_imp__setlocale>

    externdef _imp__setvbuf:PTR c_msvcrt
    crt_setvbuf equ <_imp__setvbuf>

    externdef _imp__signal:PTR c_msvcrt
    crt_signal equ <_imp__signal>

    externdef _imp__sin:PTR c_msvcrt
    crt_sin equ <_imp__sin>

    externdef _imp__sinh:PTR c_msvcrt
    crt_sinh equ <_imp__sinh>

    externdef _imp__sprintf:PTR c_msvcrt
    crt_sprintf equ <_imp__sprintf>

    externdef _imp__sqrt:PTR c_msvcrt
    crt_sqrt equ <_imp__sqrt>

    externdef _imp__srand:PTR c_msvcrt
    crt_srand equ <_imp__srand>

    externdef _imp__sscanf:PTR c_msvcrt
    crt_sscanf equ <_imp__sscanf>

    externdef _imp__strcat:PTR c_msvcrt
    crt_strcat equ <_imp__strcat>

    externdef _imp__strchr:PTR c_msvcrt
    crt_strchr equ <_imp__strchr>

    externdef _imp__strcmp:PTR c_msvcrt
    crt_strcmp equ <_imp__strcmp>

    externdef _imp__strcoll:PTR c_msvcrt
    crt_strcoll equ <_imp__strcoll>

    externdef _imp__strcpy:PTR c_msvcrt
    crt_strcpy equ <_imp__strcpy>

    externdef _imp__strcspn:PTR c_msvcrt
    crt_strcspn equ <_imp__strcspn>

    externdef _imp__strerror:PTR c_msvcrt
    crt_strerror equ <_imp__strerror>

    externdef _imp__strftime:PTR c_msvcrt
    crt_strftime equ <_imp__strftime>

    externdef _imp__strlen:PTR c_msvcrt
    crt_strlen equ <_imp__strlen>

    externdef _imp__strncat:PTR c_msvcrt
    crt_strncat equ <_imp__strncat>

    externdef _imp__strncmp:PTR c_msvcrt
    crt_strncmp equ <_imp__strncmp>

    externdef _imp__strncpy:PTR c_msvcrt
    crt_strncpy equ <_imp__strncpy>

    externdef _imp__strpbrk:PTR c_msvcrt
    crt_strpbrk equ <_imp__strpbrk>

    externdef _imp__strrchr:PTR c_msvcrt
    crt_strrchr equ <_imp__strrchr>

    externdef _imp__strspn:PTR c_msvcrt
    crt_strspn equ <_imp__strspn>

    externdef _imp__strstr:PTR c_msvcrt
    crt_strstr equ <_imp__strstr>

    externdef _imp__strtod:PTR c_msvcrt
    crt_strtod equ <_imp__strtod>

    externdef _imp__strtok:PTR c_msvcrt
    crt_strtok equ <_imp__strtok>

    externdef _imp__strtol:PTR c_msvcrt
    crt_strtol equ <_imp__strtol>

    externdef _imp__strtoul:PTR c_msvcrt
    crt_strtoul equ <_imp__strtoul>

    externdef _imp__strxfrm:PTR c_msvcrt
    crt_strxfrm equ <_imp__strxfrm>

    externdef _imp__swprintf:PTR c_msvcrt
    crt_swprintf equ <_imp__swprintf>

    externdef _imp__swscanf:PTR c_msvcrt
    crt_swscanf equ <_imp__swscanf>

    externdef _imp__system:PTR c_msvcrt
    crt_system equ <_imp__system>

    externdef _imp__tan:PTR c_msvcrt
    crt_tan equ <_imp__tan>

    externdef _imp__tanh:PTR c_msvcrt
    crt_tanh equ <_imp__tanh>

    externdef _imp__time:PTR c_msvcrt
    crt_time equ <_imp__time>

    externdef _imp__tmpfile:PTR c_msvcrt
    crt_tmpfile equ <_imp__tmpfile>

    externdef _imp__tmpnam:PTR c_msvcrt
    crt_tmpnam equ <_imp__tmpnam>

    externdef _imp__tolower:PTR c_msvcrt
    crt_tolower equ <_imp__tolower>

    externdef _imp__toupper:PTR c_msvcrt
    crt_toupper equ <_imp__toupper>

    externdef _imp__towlower:PTR c_msvcrt
    crt_towlower equ <_imp__towlower>

    externdef _imp__towupper:PTR c_msvcrt
    crt_towupper equ <_imp__towupper>

    externdef _imp__ungetc:PTR c_msvcrt
    crt_ungetc equ <_imp__ungetc>

    externdef _imp__ungetwc:PTR c_msvcrt
    crt_ungetwc equ <_imp__ungetwc>

    externdef _imp__vfprintf:PTR c_msvcrt
    crt_vfprintf equ <_imp__vfprintf>

    externdef _imp__vfwprintf:PTR c_msvcrt
    crt_vfwprintf equ <_imp__vfwprintf>

    externdef _imp__vprintf:PTR c_msvcrt
    crt_vprintf equ <_imp__vprintf>

    externdef _imp__vsprintf:PTR c_msvcrt
    crt_vsprintf equ <_imp__vsprintf>

    externdef _imp__vswprintf:PTR c_msvcrt
    crt_vswprintf equ <_imp__vswprintf>

    externdef _imp__vwprintf:PTR c_msvcrt
    crt_vwprintf equ <_imp__vwprintf>

    externdef _imp__wcscat:PTR c_msvcrt
    crt_wcscat equ <_imp__wcscat>

    externdef _imp__wcschr:PTR c_msvcrt
    crt_wcschr equ <_imp__wcschr>

    externdef _imp__wcscmp:PTR c_msvcrt
    crt_wcscmp equ <_imp__wcscmp>

    externdef _imp__wcscoll:PTR c_msvcrt
    crt_wcscoll equ <_imp__wcscoll>

    externdef _imp__wcscpy:PTR c_msvcrt
    crt_wcscpy equ <_imp__wcscpy>

    externdef _imp__wcscspn:PTR c_msvcrt
    crt_wcscspn equ <_imp__wcscspn>

    externdef _imp__wcsftime:PTR c_msvcrt
    crt_wcsftime equ <_imp__wcsftime>

    externdef _imp__wcslen:PTR c_msvcrt
    crt_wcslen equ <_imp__wcslen>

    externdef _imp__wcsncat:PTR c_msvcrt
    crt_wcsncat equ <_imp__wcsncat>

    externdef _imp__wcsncmp:PTR c_msvcrt
    crt_wcsncmp equ <_imp__wcsncmp>

    externdef _imp__wcsncpy:PTR c_msvcrt
    crt_wcsncpy equ <_imp__wcsncpy>

    externdef _imp__wcspbrk:PTR c_msvcrt
    crt_wcspbrk equ <_imp__wcspbrk>

    externdef _imp__wcsrchr:PTR c_msvcrt
    crt_wcsrchr equ <_imp__wcsrchr>

    externdef _imp__wcsspn:PTR c_msvcrt
    crt_wcsspn equ <_imp__wcsspn>

    externdef _imp__wcsstr:PTR c_msvcrt
    crt_wcsstr equ <_imp__wcsstr>

    externdef _imp__wcstod:PTR c_msvcrt
    crt_wcstod equ <_imp__wcstod>

    externdef _imp__wcstok:PTR c_msvcrt
    crt_wcstok equ <_imp__wcstok>

    externdef _imp__wcstol:PTR c_msvcrt
    crt_wcstol equ <_imp__wcstol>

    externdef _imp__wcstombs:PTR c_msvcrt
    crt_wcstombs equ <_imp__wcstombs>

    externdef _imp__wcstoul:PTR c_msvcrt
    crt_wcstoul equ <_imp__wcstoul>

    externdef _imp__wcsxfrm:PTR c_msvcrt
    crt_wcsxfrm equ <_imp__wcsxfrm>

    externdef _imp__wctomb:PTR c_msvcrt
    crt_wctomb equ <_imp__wctomb>

    externdef _imp__wprintf:PTR c_msvcrt
    crt_wprintf equ <_imp__wprintf>

    externdef _imp__wscanf:PTR c_msvcrt
    crt_wscanf equ <_imp__wscanf>

