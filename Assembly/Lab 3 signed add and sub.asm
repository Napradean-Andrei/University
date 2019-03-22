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

a db 7
b dw 9
c dd 4
d dq 1


; the program code will be part of a segment called code
segment code use32 class=code
start:
; ... 

; Lab 3 signed addition and subs

;  (a + b + c) - d + (b - c)
;       where a - byte, b - word, c - double word, d - qword


mov AL,[a]
CBW
mov BX,[b]
adc AX,BX
CWD
push DX
push AX
pop EAX
mov EBX,[c]
adc EAX,EBX
CDQ
mov EBX,dword[d]
mov ECX,dword[d+4]
sbb EAX,EBX
sbb EDX,ECX
mov EBX,EAX
mov ECX,EDX ; ECX:EBX = a + b + c - d
mov AX,[b]
CWD
push DX
push AX
pop EAX
mov EBX,[c]
sbb EAX,EBX
CDQ
adc EBX,EAX
adc ECX,EDX 
;ECX:EBX = a + b + c - d + (b-c)





    ; call exit(0) ), 0 represents status code: SUCCESS
    push dword 0 ; saves on stack the parameter of the function exit
    call [exit] ; function exit is called in order to end the execution of the program