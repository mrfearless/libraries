StatusBarInit               PROTO :DWORD                ; Initialize the statusbar, set parts and set initial text etc
StatusBarSize			    PROTO :DWORD, :DWORD        ; Resize statusbar
StatusBarSetPanelText       PROTO :DWORD, :DWORD        ; Set text in a statusbar panel

.DATA
szStatusText                DB 512 dup (0)


.CODE


;-------------------------------------------------------------------------------------
; StatusBarInit - Initialize the StatusBar Control
;-------------------------------------------------------------------------------------
StatusBarInit PROC hWin:DWORD
	LOCAL sbParts[3]:DWORD

	invoke CreateStatusWindow, WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN  or WS_CLIPSIBLINGS or SBS_SIZEGRIP, NULL, hWin, IDC_SB
	mov hSB, eax

	mov [sbParts +  0], 135		; Panel 1 Size
	mov [sbParts +  4], 180		; Panel 2 Size
	mov [sbParts +  8], -1		; Panel 3 Size 

	Invoke SendMessage, hSB, SB_SETPARTS, 3, ADDR sbParts ; Set amount of parts
    
	Invoke  StatusBarSetPanelText, 0, CTEXT(" Search for text") 
	Invoke  StatusBarSetPanelText, 1, CTEXT(" Info: ") 	
	Invoke  StatusBarSetPanelText, 2, CTEXT(" ")
    ret
StatusBarInit ENDP


;-------------------------------------------------------------------------------------
; Resets StatusBar to bottom of main dialog - Call from WM_SIZE event
;-------------------------------------------------------------------------------------
StatusBarSize PROC hWin:DWORD, lParam:DWORD
	Invoke MoveWindow, hSB, 0, 0, 0, 0, TRUE	
	ret
StatusBarSize ENDP


;-------------------------------------------------------------------------------------
; Set StatusBar Panel Text
;-------------------------------------------------------------------------------------
StatusBarSetPanelText PROC nPanel:DWORD, lpszPanelText:DWORD
    xor eax, eax
    mov eax, nPanel
    Invoke SendMessage, hSB, SB_SETTEXT, eax, lpszPanelText
    ret
StatusBarSetPanelText ENDP


















