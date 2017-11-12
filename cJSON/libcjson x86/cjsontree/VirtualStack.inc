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
VirtualStackCreate          PROTO :DWORD, :DWORD    ; dwStackSize, dwStackOptions. Returns in eax hVirtualStack or NULL if error
VirtualStackDelete          PROTO :DWORD, :DWORD    ; hVirtualStack, lpdwVirtualDeleteCallbackProc. Returns in eax TRUE or FALSE
VirtualStackPush            PROTO :DWORD, :DWORD    ; hVirtualStack, dwPushValue. Returns in eax TRUE or FALSE
VirtualStackPop             PROTO :DWORD, :DWORD    ; hVirtualStack, lpdwPopValue. Returns in eax TRUE or FALSE or -1 for empty stack
VirtualStackPeek            PROTO :DWORD, :DWORD    ; hVirtualStack, lpdwPeekValue. Returns in eax TRUE or FALSE or -1 for empty stack
VirtualStackPeer            PROTO :DWORD, :DWORD    ; hVirtualStack, lpdwPeerValue. Returns in eax TRUE or FALSE or -1 for empty stack
VirtualStackZero            PROTO :DWORD            ; hVirtualStack. Returns in eax TRUE or FALSE

VirtualStackCount           PROTO :DWORD            ; hVirtualStack. Returns in eax number of items on stack
VirtualStackSize            PROTO :DWORD            ; hVirtualStack. Returns in eax max size of stack
VirtualStackDepth           PROTO :DWORD            ; hVirtualStack. Returns in eax max number of items ever on stack
VirtualStackData            PROTO :DWORD            ; hVirtualStack. Returns in eax pointer to stack data table
VirtualStackUniqueCount     PROTO :DWORD            ; hVirtualStack. Returns in eax unique number of items on stack

;VirtualDeleteCallbackProc  PROTO :DWORD, :DWORD    ; optional Callback. hVirtualStack, ptrStackItem


.CONST
;-----------------------------------------------------------------------------------------
; VirtualStack Constants
;-----------------------------------------------------------------------------------------

; Virtual Stack Sizes (dwStackSize):
VIRTUALSTACK_SIZE_TINY      EQU 16d
VIRTUALSTACK_SIZE_SMALL     EQU 32d
VIRTUALSTACK_SIZE_MEDIUM    EQU 256d
VIRTUALSTACK_SIZE_LARGE     EQU 1024d

; Virtual Stack Options (dwStackOptions):
VIRTUALSTACK_OPTION_DEFAULT EQU 0   ; Normal
VIRTUALSTACK_OPTION_UNIQUE  EQU 1   ; Creates a list of unique stack items for use with VirtualDeleteCallbackProc in VirtualStackDelete

; Virtual Stack Error Return Values
VIRTUALSTACK_UNIQUEFULL     EQU -3  ; Unique list is already at max size. No more items can be added to this unique list
VIRTUALSTACK_STACKFULL      EQU -2  ; Stack pointer is already at max size. No more items can be 'pushed' to this stack
VIRTUALSTACK_STACKEMPTY     EQU -1  ; Stack pointer is already at 0. No more items can be 'popped' from this stack
VIRTUALSTACK_FAILURE        EQU 0   ; Stack operation error
VIRTUALSTACK_SUCCESS        EQU 1   ; Stack operation success









