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

a db 2
b db 3
c db 4
d db 1
x dq 2

; the program code will be part of a segment called code
segment code use32 class=code
start:
; ... 

; Lab 3 unsigned multiplications and divisions

;  a-(7+x)/(b*b-c/d+2); a-doubleword; b,c,d-byte; x-qword


mov EAX,0
mov EBX,0

mov AL,[b]
mul byte [b]
mov BL,AL

mov AL,[c]
mov CL,[d]
add CL,2
mov EDX,0
div CL
sub BL,AL;(b*b-c/d+2)

mov EAX,[x]
mov EDX,[x+4]
add AL,7;(7+x)
div BL
mov EBX,[a]
sub























    ; call exit(0) ), 0 represents status code: SUCCESS
    push dword 0 ; saves on stack the parameter of the function exit
    call [exit] ; function exit is called in order to end the execution of the program