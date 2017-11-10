;=========================================================================================
;
; LICENSE
;
; VirtualStack Library x64 v1.0.0.0
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
VirtualStackCreate          PROTO :QWORD, :QWORD    ; qwStackSize, qwStackOptions. Returns in rax hVirtualStack or NULL if error
VirtualStackDelete          PROTO :QWORD, :QWORD    ; hVirtualStack. lpqwVirtualDeleteCallbackProc. Returns in rax TRUE or FALSE
VirtualStackPush            PROTO :QWORD, :QWORD    ; hVirtualStack, qwPushValue. Returns in rax TRUE or FALSE
VirtualStackPop             PROTO :QWORD, :QWORD    ; hVirtualStack, lpqwPopValue. Returns in rax TRUE or FALSE or -1 for empty stack
VirtualStackPeek            PROTO :QWORD, :QWORD    ; hVirtualStack, lpqwPeekValue. Returns in rax TRUE or FALSE or -1 for empty stack
VirtualStackPeer            PROTO :QWORD, :QWORD    ; hVirtualStack, lpqwPeerValue. Returns in rax TRUE or FALSE or -1 for empty stack
VirtualStackZero            PROTO :QWORD            ; hVirtualStack. Returns in rax TRUE or FALSE

VirtualStackCount           PROTO :QWORD            ; hVirtualStack. Returns in rax number of items on stack
VirtualStackSize            PROTO :QWORD            ; hVirtualStack. Returns in rax max size of stack
VirtualStackDepth           PROTO :QWORD            ; hVirtualStack. Returns in rax max number of items ever on stack
VirtualStackData            PROTO :QWORD            ; hVirtualStack. Returns in rax pointer to stack data table
VirtualStackUniqueCount     PROTO :QWORD            ; hVirtualStack. Returns in rax unique number of items on stack

;VirtualDeleteCallbackProc  PROTO :QWORD, :QWORD    ; optional Callback. hVirtualStack, ptrStackItem

.CONST
;-----------------------------------------------------------------------------------------
; VirtualStack Constants
;-----------------------------------------------------------------------------------------

; Virtual Stack Sizes:
VIRTUALSTACK_SIZE_TINY      EQU 16d
VIRTUALSTACK_SIZE_SMALL     EQU 32d
VIRTUALSTACK_SIZE_MEDIUM    EQU 256d
VIRTUALSTACK_SIZE_LARGE     EQU 1024d

; Virtual Stack Options (qwStackOptions):
VIRTUALSTACK_OPTION_DEFAULT EQU 0   ; Normal
VIRTUALSTACK_OPTION_UNIQUE  EQU 1   ; Creates a list of unique stack items for use with VirtualDeleteCallbackProc in VirtualStackDelete

; Virtual Stack Error Return Values
VIRTUALSTACK_UNIQUEFULL     EQU -3  ; Unique list is already at max size. No more items can be added to this unique list
VIRTUALSTACK_STACKFULL      EQU -2  ; Stack pointer is already at max size. No more items can be 'pushed' to this stack
VIRTUALSTACK_STACKEMPTY     EQU -1  ; Stack pointer is already at 0. No more items can be 'popped' from this stack
VIRTUALSTACK_FAILURE        EQU 0   ; Stack operation error
VIRTUALSTACK_SUCCESS        EQU 1   ; Stack operation success









