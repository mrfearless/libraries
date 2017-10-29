.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

EXTERNDEF ListViewGetColumnCount :PROTO :DWORD

.code

;**************************************************************************	
; 
;
;LVCF_IMAGE                      equ 0010h
;
;LVCFMT_LEFT                     equ 0000h
;LVCFMT_RIGHT                    equ 0001h
;LVCFMT_CENTER                   equ 0002h
;LVCFMT_JUSTIFYMASK              equ 0003h
;LVCFMT_IMAGE                    equ 0800h
;LVCFMT_BITMAP_ON_RIGHT          equ 1000h
;LVCFMT_COL_HAS_IMAGES           equ 8000h
;LVCFMT_FIXED_WIDTH              equ 00100h
;LVCFMT_NO_DPI_SCALE             equ 40000h
;LVCFMT_FIXED_RATIO              equ 80000h
;LVCFMT_LINE_BREAK               equ 100000h
;LVCFMT_FILL                     equ 200000h
;LVCFMT_WRAP                     equ 400000h
;LVCFMT_NO_TITLE                 equ 800000h
;LVCFMT_TILE_PLACEMENTMASK       equ LVCFMT_LINE_BREAK or LVCFMT_FILL
;LVCFMT_SPLITBUTTON              equ 1000000h

;**************************************************************************	
ListViewInsertColumn PROC PUBLIC hListview:DWORD, dwFormat:DWORD, dwWidth:DWORD, lpszColumnText:DWORD 
    LOCAL LVC:LV_COLUMN
    LOCAL iCol:DWORD
    
    Invoke ListViewGetColumnCount, hListview
    mov iCol, eax
	mov LVC.imask, LVCF_FMT or LVCF_TEXT or LVCF_WIDTH  ;or LVCFMT_COL_HAS_IMAGES
	mov eax, dwFormat
    mov LVC.fmt, eax ; defaults to LVCFMT_LEFT
    mov eax, lpszColumnText	
	mov LVC.pszText, eax
	mov eax, dwWidth
	mov LVC.lx, eax
	Invoke SendMessage, hListview, LVM_INSERTCOLUMN, iCol, Addr LVC
	ret  
ListViewInsertColumn ENDP

ListViewInsertColumnImage PROC PUBLIC hListview:DWORD, dwFormat:DWORD, dwWidth:DWORD, lpszColumnText:DWORD, nImageListIndex:DWORD
    LOCAL LVC:LV_COLUMN
    LOCAL iCol:DWORD
    
    Invoke ListViewGetColumnCount, hListview
    mov iCol, eax
	mov LVC.imask, LVCF_FMT or LVCF_TEXT or LVCF_WIDTH or LVCF_IMAGE
	mov eax, dwFormat
    mov LVC.fmt, eax ; defaults to LVCFMT_LEFT
    mov eax, lpszColumnText	
	mov LVC.pszText, eax
	mov eax, dwWidth
	mov LVC.lx, eax
	mov eax, nImageListIndex
	mov LVC.iImage, eax
	Invoke SendMessage, hListview, LVM_INSERTCOLUMN, iCol, Addr LVC
	ret  
ListViewInsertColumnImage ENDP


;Additional fmt member bits - arrow up, arrow down
;For any newbie using winapi, who is looking for a way to display arrow up and arrow down sort indicators:
;
;It should be noted in this article, that since Windows XP (_WIN32_WINNT >= 0x0501), 
;fmt member of LVCOLUMN can also be combined with HDF_SORTUP (0x0400) and HDF_SORTDOWN (0x0200) values. 
;These two bits, combined with any other, accomplish the above. Does not work with column 0, as mentioned in the article, 
;but does not require setting up some troublesome image lists just to display an arrow. 
;I just found out about this by accident, where i forgot to initialize this member for all columns and they all got arrows on them, 
;resulting from accidental binary 1100 1100 1100 1100 fmt value.
;
;
;Now, to manipulate these sort indicators, we can respond to LVN_COLUMNCLICK in WM_NOTIFY and check for existence of HDF_SORTUP in a column that was clicked, 
;like so (index is the column that was clicked and i hope you know what hListView is):
;
;LVCOLUMN lvc;
;
;lvc.mask=LVCF_FMT;
;
;HWND hListView=((LPNMLISTVIEW)lParam)->hdr.hwndFrom;
;
;int index=((LPNMLISTVIEW)lParam)->iSubItem;
;
;SendMessage(hListView,LVM_GETCOLUMN,(WPARAM)index, (LPARAM)&lvc);
;
;if(HDF_SORTUP & lvc.fmt) {
;
;   //set the opposite arrow
;
;   lvc.fmt=lvc.fmt & (~HDF_SORTUP) | HDF_SORTDOWN; //turns off sort-up, turns on sort-down
;
;   SendMessage(hListView, LVM_SETCOLUMN, (WPARAM) index, (LPARAM) &lvc);
;
;   //use any sorting you would use, e.g. the LVM_SORTITEMS message
;
;}else if(HDF_SORTDOWN & lvc.fmt){
;
;   //the opposite
;
;   lvc.fmt=lvc.fmt & (~HDF_SORTDOWN) | HDF_SORTUP;
;
;   SendMessage(hListView, LVM_SETCOLUMN, (WPARAM) index, (LPARAM) &lvc);
;
;}else{
;
;   // this is the case our clicked column wasn't the one being sorted up until now
;
;   // so first  we need to iterate through all columns and send LVM_SETCOLUMN to them with fmt set to NOT include these HDFs
;
;   HWND colHeader=(HWND)SendMessage(hListView,LVM_GETHEADER,NULL,NULL);
;
;   int Cols=SendMessage(colHeader,HDM_GETITEMCOUNT,NULL,NULL);
;
;   for(int q=0; q<Cols; q++){
;
;       //Get current fmt
;
;       SendMessage(hListView,LVM_GETCOLUMN,(WPARAM) q, (LPARAM) &lvc);
;
;       //remove both sort-up and sort-down
;
;       lvc.fmt=lvc.fmt & (~HDF_SORTUP) & (~HDF_SORTDOWN);
;
;       SendMessage(hListView,LVM_SETCOLUMN,(WPARAM) q, (LPARAM) &lvc);
;
;   }
;
;   //read current fmt from clicked column
;
;   SendMessage(hListView,LVM_GETCOLUMN,(WPARAM) index, (LPARAM) &lvc);
;
;   // then set whichever arrow you feel like and send LVM_SETCOLUMN to this particular column
;
;   lvc.fmt=lvc.fmt | HDF_SORTUP;
;
;   SendMessage(hListView, LVM_SETCOLUMN, (WPARAM) index, (LPARAM) &lvc);
;
;}



end	
	