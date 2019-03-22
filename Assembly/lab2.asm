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

; the program code will be part of a segment called code
segment code use32 class=code
start:
;...

; 256*1
mov AX,256
mov BX,1
mul BX

;(a-b-b-c)+(a-c-c-d) all bytes


mov AH, 20
mov AL, 1
sub AH, AL
mov AL, 1
sub AH, AL
mov AL, 10
sub AH, AL
mov BH, 20
mov AL, 10
sub BH, AL
sub BH, AL
mov AL, -6
sub BH, AL
add AH, BH

;(a-c)+(b-d)  words


mov AX, 4
mov BX, 3
mov CX, 2
mov DX, 1
sub AX, CX
sub BX, DX
add AX, BX

; [(a+b)*3-c*2]+d  a,b,c are db and d is dw

mov AH, 4
mov AL, 2
add AL,AH
mov AH, 2
mul AH
mov BX,AX
mov AL, 5
mov AH, 4
mul AH
sub BX,AX
mov AX,1
add BX,AX

; [(a+b)*2]/(a+d)  a,b,d are db
 
 mov AH,1
 mov AL,5
 add AL,AH
 mov AH,5
 mul AH
 mov BH,1
 mov BL,17
 add BH,BL
 div BH

 ; call exit(0) ), 0 represents status code: SUCCESS
    push dword 0 ; saves on stack the parameter of the function exit
    call [exit] ; function exit is called in order to end the execution of the program
