.686
.MMX
.XMM
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include kernel32.inc
includelib kernel32.lib

include Console.inc


.CODE

;FOREGROUND_BLUE                      equ 1h
;FOREGROUND_GREEN                     equ 2h
;FOREGROUND_RED                       equ 4h
;FOREGROUND_INTENSITY                 equ 8h
;BACKGROUND_BLUE                      equ 10h
;BACKGROUND_GREEN                     equ 20h
;BACKGROUND_RED                       equ 40h
;BACKGROUND_INTENSITY                 equ 80h
;https://docs.microsoft.com/en-us/windows/console/using-the-high-level-input-and-output-functions

;//Define extra colours
;#define FOREGROUND_WHITE		(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN)
;#define FOREGROUND_YELLOW       	(FOREGROUND_RED | FOREGROUND_GREEN)
;#define FOREGROUND_CYAN		        (FOREGROUND_BLUE | FOREGROUND_GREEN)
;#define FOREGROUND_MAGENTA	        (FOREGROUND_RED | FOREGROUND_BLUE)
;#define FOREGROUND_BLACK		0
;
;#define FOREGROUND_INTENSE_RED		(FOREGROUND_RED | FOREGROUND_INTENSITY)
;#define FOREGROUND_INTENSE_GREEN	(FOREGROUND_GREEN | FOREGROUND_INTENSITY)
;#define FOREGROUND_INTENSE_BLUE		(FOREGROUND_BLUE | FOREGROUND_INTENSITY)
;#define FOREGROUND_INTENSE_WHITE	(FOREGROUND_WHITE | FOREGROUND_INTENSITY)
;#define FOREGROUND_INTENSE_YELLOW	(FOREGROUND_YELLOW | FOREGROUND_INTENSITY)
;#define FOREGROUND_INTENSE_CYAN		(FOREGROUND_CYAN | FOREGROUND_INTENSITY)
;#define FOREGROUND_INTENSE_MAGENTA	(FOREGROUND_MAGENTA | FOREGROUND_INTENSITY)
;
;#define BACKGROUND_WHITE		(BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN)
;#define BACKGROUND_YELLOW	        (BACKGROUND_RED | BACKGROUND_GREEN)
;#define BACKGROUND_CYAN		        (BACKGROUND_BLUE | BACKGROUND_GREEN)
;#define BACKGROUND_MAGENTA	        (BACKGROUND_RED | BACKGROUND_BLUE)
;#define BACKGROUND_BLACK		0
;
;#define BACKGROUND_INTENSE_RED		(BACKGROUND_RED | BACKGROUND_INTENSITY)
;#define BACKGROUND_INTENSE_GREEN	(BACKGROUND_GREEN | BACKGROUND_INTENSITY)
;#define BACKGROUND_INTENSE_BLUE		(BACKGROUND_BLUE | BACKGROUND_INTENSITY)
;#define BACKGROUND_INTENSE_WHITE	(BACKGROUND_WHITE | BACKGROUND_INTENSITY)
;#define BACKGROUND_INTENSE_YELLOW	(BACKGROUND_YELLOW | BACKGROUND_INTENSITY)
;#define BACKGROUND_INTENSE_CYAN		(BACKGROUND_CYAN | BACKGROUND_INTENSITY)
;#define BACKGROUND_INTENSE_MAGENTA	(BACKGROUND_MAGENTA | BACKGROUND_INTENSITY)


;**************************************************************************
; ConsoleTextColor - alias for ConsoleStdOutColor
;**************************************************************************
ConsoleTextColor PROC lpszConText:DWORD, Color:DWORD
    Invoke ConsoleStdOutColor, lpszConText, Color
ConsoleTextColor ENDP


;**************************************************************************
; ConsoleStdOutColor
;**************************************************************************
ConsoleStdOutColor PROC lpszConText:DWORD, Color:DWORD
    LOCAL hConOutput:DWORD
    LOCAL dwBytesWritten:DWORD
    LOCAL dwLenConText:DWORD
    LOCAL wOldColorAttrs:WORD
    LOCAL sbi:CONSOLE_SCREEN_BUFFER_INFO
    

    Invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConOutput, eax
    
    Invoke GetConsoleScreenBufferInfo, hConOutput, Addr sbi
    movzx eax, word ptr sbi.wAttributes
    mov wOldColorAttrs, ax
    
    ;Invoke FlushConsoleInputBuffer, hConOutput
    Invoke SetConsoleTextAttribute, hConOutput, word ptr Color
    
    Invoke lstrlen, lpszConText
    mov dwLenConText, eax

    Invoke WriteFile, hConOutput, lpszConText, dwLenConText, Addr dwBytesWritten, NULL
    
    ;Invoke FlushConsoleInputBuffer, hConOutput
    Invoke SetConsoleTextAttribute, hConOutput, wOldColorAttrs; // back to default color
    
    mov eax, dwBytesWritten
    ret
ConsoleStdOutColor ENDP


END

;void print_in_color(int color, std::string text)
;{
;	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
;	FlushConsoleInputBuffer(hConsole);
;	SetConsoleTextAttribute(hConsole, color); // back to default color
;	std::cout << text;
;	FlushConsoleInputBuffer(hConsole);
;	SetConsoleTextAttribute(hConsole, 7); // back to default color
;}