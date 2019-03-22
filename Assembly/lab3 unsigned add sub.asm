bits 32 ;assembling for the 32 bits architecture
global start

; we ask the assembler to give global visibility to the symbol called start 
;(the start label will be the entry point in the program) 
extern exit ; we inform the assembler that the exit symbol is foreign; it exists even if we won't be defining it
import exit msvcrt.dll  ; we specify the external library that defines the symbol
        ; msvcrt.dll contains exit, printf and all the other important C-runtime functions

; our variables are declared here (the segment is called data) 
segment data use32 class=data
; ... 

a db 6
b dw 3
c dd 2
d dq 9


; the program code will be part of a segment called code
segment code use32 class=code
start:
; ... 

; Lab 3 unsigned addition and subs

;  ((a + b) + (a + c) + (b + c)) - d
; I compute a+a+b+b+c+c-d
;       where a - byte, b - word, c - double word, d - qword


mov AL,[a]
mov AH,[a]
add AL,AH
CBW
mov BX,[b]
add AX,BX
mov BX,[b]
add AX,BX
CWD
mov BX,word[c]
mov CX,word[c+2]
add AX,BX
add DX,CX
mov BX,word[c]
mov CX,word[c+2]
add AX,BX
add DX,CX
CDQ
mov EDX,0
sub EAX,dword[d]
sub EDX,dword[d+4]






    ; call exit(0) ), 0 represents status code: SUCCESS
    push dword 0 ; saves on stack the parameter of the function exit
    call [exit] ; function exit is called in order to end the execution of the program