;=========================================================================================
;
; LICENSE
;
; VirtualStack Library x86 v1.0.0.0
;
; Copyright (c) 2017 by KSR aka fearless
;
; All Rights Reserved
;
; http://www.LetTheLight.in
;
;
; This software is provided 'as-is', without any express or implied warranty. In no
; event will the author be held liable for any damages arising from the use of this
; software.
;
; Permission is granted to anyone to use this software for any non-commercial program.
; If you use the library in an application, an acknowledgement in the application or
; documentation is appreciated but not required. 
;
; You are allowed to make modifications to the source code, but you must leave the
; original copyright notices intact and not misrepresent the origin of the software.
; It is not allowed to claim you wrote the original software. Modified files must have
; a clear notice that the files are modified, and not in the original state. This includes
; the name of the person(s) who modified the code. 
;
; If you want to distribute or redistribute any portion of this package, you will need
; to include the full package in it's original state, including this license and all
; the copyrights. 
;
; While distributing this package (in it's original state) is allowed, it is not allowed
; to charge anything for this. You may not sell or include the package in any commercial
; package without having permission of the author. Neither is it allowed to redistribute
; any of the package's components with commercial applications.
;
;=========================================================================================

;-----------------------------------------------------------------------------------------
; VirtualStack Prototypes
;-----------------------------------------------------------------------------------------
VirtualStackCreate          PROTO :DWORD            ; dwStackSize. Returns in eax hVirtualStack or NULL if error
VirtualStackDelete          PROTO :DWORD            ; hVirtualStack. Returns in eax TRUE or FALSE
VirtualStackPush            PROTO :DWORD, :DWORD    ; hVirtualStack, dwPushValue. Returns in eax TRUE or FALSE
VirtualStackPop             PROTO :DWORD, :DWORD    ; hVirtualStack, lpdwPopValue. Returns in eax TRUE or FALSE or -1 for empty stack
VirtualStackPeek            PROTO :DWORD, :DWORD    ; hVirtualStack, lpdwPeekValue. Returns in eax TRUE or FALSE or -1 for empty stack
VirtualStackCount           PROTO :DWORD            ; hVirtualStack. Returns in eax number of items on stack
VirtualStackSize            PROTO :DWORD            ; hVirtualStack. Returns in eax max size of stack
VirtualStackZero            PROTO :DWORD            ; hVirtualStack. Returns in eax TRUE or FALSE


.CONST
;-----------------------------------------------------------------------------------------
; VirtualStack Constants
;-----------------------------------------------------------------------------------------

; Virtual Stack Sizes:
VIRTUALSTACK_SIZE_SMALL     EQU 16d
VIRTUALSTACK_SIZE_MEDIUM    EQU 256d
VIRTUALSTACK_SIZE_LARGE     EQU 1024d

; Virtual Stack Error Return Values
VIRTUALSTACK_STACKFULL      EQU -2  ; Stack pointer is already at max size. No more items can be 'pushed' to this stack
VIRTUALSTACK_STACKEMPTY     EQU -1  ; Stack pointer is already at 0. No more items can be 'popped' from this stack
VIRTUALSTACK_FAILURE        EQU 0   ; Stack operation error
VIRTUALSTACK_SUCCESS        EQU 1   ; Stack operation success









