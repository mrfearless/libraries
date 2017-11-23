.686
.MMX
.XMM
.x64

option casemap : none
option win64 : 11
option frame : auto
option stackbase : rsp

_WIN64 EQU 1
WINVER equ 0501h

include windows.inc
include commctrl.inc
;include user32.inc
includelib user32.lib

include TreeView.inc

;.data
;TVIS            TV_INSERTSTRUCT <>

.code
;======================================================================
; Insert Root or Child Node into Treeview
; if hNodeParent == NULL we are inserting a Root node so nNodePosition
; can be NULL (it will be ignored)
; If hNodeParent is not NULL we are inserting a Child node.
; Returns handle to the newly created node root or child in rax
;======================================================================
TreeViewItemInsert PROC FRAME hTreeview:QWORD, hNodeParent:QWORD, lpszNodeText:QWORD, nNodeIndex:QWORD, NodePosition:QWORD, nImage:QWORD, nImageSelected:QWORD, dqParam:QWORD
	LOCAL TVIS:TV_INSERTSTRUCT
	;LOCAL hNode:QWORD

	.IF hNodeParent != NULL 											; A child node is specified, set specifics for child node insert
	
	    .IF nImage != -1
	        mov TVIS.item.mask_, TVIF_TEXT or TVIF_PARAM or TVIF_IMAGE or TVIF_SELECTEDIMAGE
	    .ELSE
	        mov TVIS.item.mask_, TVIF_TEXT or TVIF_PARAM
	    .ENDIF
		mov	rax, hNodeParent
    	mov TVIS.hParent, rax
	    mov	rax, NodePosition											; Set position for child node (TVI_FIRST, TVI_LAST, TVI_SORT)
    	mov TVIS.hInsertAfter, rax
    .ELSE
        .IF nImage != -1												; A root node is specified, set specifics for root node insert
            mov TVIS.item.mask_, TVIF_TEXT or TVIF_PARAM or TVIF_IMAGE or TVIF_SELECTEDIMAGE or TVIF_CHILDREN
        .ELSE
            mov TVIS.item.mask_, TVIF_TEXT or TVIF_PARAM or TVIF_CHILDREN
        .ENDIF
    	mov TVIS.hParent, NULL 										
    	mov TVIS.hInsertAfter, TVI_ROOT
    	mov TVIS.item.cChildren, 1
    .ENDIF		

	mov	rax, lpszNodeText											    ; Specify text for node (root/child)
    mov TVIS.item.pszText, rax
    
    .IF dqParam == NULL
        mov rax, nNodeIndex
    .ELSE
        mov rax, dqParam
    .ENDIF
    mov TVIS.item.lParam, rax
    
    .IF nImage != -1
        mov rax, nImage
        mov TVIS.item.iImage, eax                                       ; Image for node if linked to an imagelist
    .ELSE
        mov TVIS.item.iImage, -2
    .ENDIF
    .IF nImageSelected != -1
        mov rax, nImageSelected
        mov TVIS.item.iSelectedImage, eax 								; Image for node if linked to an imagelist
    .ELSE
        mov TVIS.item.iSelectedImage, -2
    .ENDIF
    ;push nNodeIndex														; Set index value of node item (root or child) as lParam
    ;pop TVIS.item.lParam
    
 	Invoke SendMessage, hTreeview, TVM_INSERTITEM, 0, addr TVIS		    ; Insert item (root/child)
 	;mov hNode, rax	
 	;mov rax, hNode  		
	
	ret

TreeViewItemInsert endp


end