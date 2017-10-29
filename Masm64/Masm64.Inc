;=========================================================================================
;
; Masm64 Library x64 v1.0.0.0 
; 
; 64bit Port of Steve Hutchesson's Masm32 library from www.masm32.com
;
; 2015 by fearless
;
; http://www.LetTheLight.in
;
;
; This software is provided 'as-is', without any express or implied warranty. In no
; event will the author be held liable for any damages arising from the use of this
; software.
;
;=========================================================================================

;-----------------------------------------------------------------------------------------
; LTLI Masm64 Prototypes
;-----------------------------------------------------------------------------------------

; ----------------------------
; numeric and text conversions
; ----------------------------
qw2hex      PROTO :QWORD,:QWORD
dw2hex      PROTO :DWORD,:QWORD
dwtoa       PROTO :DWORD,:QWORD   ; value - buffer

a2qw        PROTO :QWORD
atoqw       PROTO :QWORD
ltoa        PROTO :DWORD,:QWORD


htodw       PROTO :QWORD
htoqw       PROTO :QWORD

; --------------------------------------
; zero terminated string procedures have
; been renamed for consistency. Equates
; to the old names are below.
; --------------------------------------
InString    PROTO :QWORD,:QWORD,:QWORD                    ; StartPos-lpszString-lpszSubStr
szappend    PROTO :QWORD,:QWORD,:QWORD
szCatStr    PROTO :QWORD,:QWORD
szCmp       PROTO :QWORD,:QWORD
szCmpi      PROTO :QWORD,:QWORD,:QWORD
Cmpi        PROTO :QWORD,:QWORD
szCopy      PROTO :QWORD,:QWORD
szLeft      PROTO :QWORD,:QWORD,:QWORD
szLen       PROTO :QWORD
szLower     PROTO :QWORD
szLtrim     PROTO :QWORD,:QWORD
szMid       PROTO :QWORD,:QWORD,:QWORD,:QWORD
;szMultiCat  PROTO C :QWORD,:QWORD,:VARARG
szMonoSpace PROTO :QWORD
szRemove    PROTO :QWORD,:QWORD,:QWORD
szRep       PROTO :QWORD,:QWORD,:QWORD,:QWORD
szRev       PROTO :QWORD,:QWORD
szRight     PROTO :QWORD,:QWORD,:QWORD
szRtrim     PROTO :QWORD,:QWORD
szTrim      PROTO :QWORD
szUpper     PROTO :QWORD


StrLen  equ <szLen>
lnstr   equ <szLen>
cmpstr  equ <szCmp>
cmpsi   equ <szCmpi>
revstr  equ <szRev>
lcase   equ <szLower>
ucase   equ <szUpper>
ltrim   equ <szLtrim>
rtrim   equ <szRtrim>
trim    equ <szTrim>
lstr    equ <szLeft>
rstr    equ <szRight>
midstr  equ <szMid>



; ----------------------
; path, folder functions
; ----------------------
exist       PROTO :QWORD
GetPathOnly PROTO :QWORD,:QWORD


ArgByNumber PROTO :QWORD,:QWORD,:QWORD,:QWORD



nrandom     PROTO :QWORD
nseed       PROTO :QWORD



