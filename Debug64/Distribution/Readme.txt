 =========================================================================================
 
  Debug64 Library x64 
 
  2015 fearless
 
  Original code from Donkey's vKim like tools - adapted for JWasm64 
 
  Original Thread: www.masmforum.com/board/index.php?topic=16317.msg135041#msg135041
 
  Download: www.masmforum.com/board/index.php?action=dlattach;topic=16317.0;id=10334
 
 =========================================================================================


 ----------------------------------------------------------------------------------------
 OVERVIEW
 ----------------------------------------------------------------------------------------
 Debug macros and functions for 64bit JWasm


 ----------------------------------------------------------------------------------------
 HISTORY
 ----------------------------------------------------------------------------------------
 
 v1.0.0.0 
 --------
 Release    - First release - bit buggy, very few functions/macros working


 ----------------------------------------------------------------------------------------
 HOW TO USE
 ----------------------------------------------------------------------------------------
 - Copy DbgWin.exe to JWasm\bin (or other location as suits your setup)
 - Copy Debug64.inc to your JWasm\include folder (or wherever your includes are located)
 - Copy Debug64.lib to your JWasm\Lib\x64 folder (or wherever your 64bit libraries are located)
 - Copy Libs\*.lib to JWasm\Lib\x64 (or wherever your 64bit libraries are located)
 - Include in your project, somewhere at the start:

     DEBUG64 EQU 1

     IFDEF DEBUG64
         PRESERVEXMMREGS equ 1
         includelib \JWasm\lib\x64\Debug64.lib
         DBG64LIB equ 1
         DEBUGEXE textequ <'\Jwasm\bin\DbgWin.exe'>
         include \JWasm\include\debug64.inc
         .DATA
         RDBG_DbgWin DB DEBUGEXE,0
         .CODE
     ENDIF

 - Adjust the path settings in the above code block to suit your own dev environment
 - Use the debug macros in your code

 ----------------------------------------------------------------------------------------
 NOTES
 ---------------------------------------------------------------------------------------- 

 Changed the DEBUGEXE define to an external definition that is set outside of the debug64
 library in the users project instead.
 
 Currently I have only tested these macros: PrintText, PrintString, PrintDec, PrintQWORD
 
 Couldn't get PrintStringByAddr to work properly. DbgDump & DumpMem don't seem to work 
 either. Probably an error in my conversion and/or macros are incorrect for these 
 functions. Haven't looked at any other functions, the prototypes for all others that I 
 haven't looked at the ones that are commented out in Debug64.inc
 
 Some 64bit libs are included, just in case someone doesn't have them for some reason -
 ntdll.lib specifically, which I had to go looking for.
 
 Original source is included in a separate folder, or can be downloaded from the masm 
 forum board, links at the start of this readme.txt
 
 Included a DbgTest radasm project to show example of use for currently tested macros.
 
 =========================================================================================
