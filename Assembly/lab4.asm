
;Given the doubleword M, compute the doubleword MNew as follows:
;the bits 0-3 a of MNew are the same as the bits 5-8 a of M.
;the bits 4-7 a of MNew have the value 1
;the bits 27-31 a of MNew have the value 0
;the bits 8-26 of MNew are the same as the bits 8-26 a of M.

bits 32 ;assembling for the 32 bits architecture
; the start label will be the entry point in the program
global  start 

extern  exit ; we inform the assembler that the exit symbol is foreign, i.e. it exists even if we won't be defining it
import  exit msvcrt.dll; exit is a function that ends the process, it is defined in msvcrt.dll
        ; msvcrt.dll contains exit, printf and all the other important C-runtime functions
segment  data use32 class=data ; the data segment where the variables are declared 
     M dw 10111000101010110111011101010111b
     MNew dw 0
segment  code use32 class=code ; code segment
start: 

     mov  bx, 0 ; we compute the result in bx

     mov  ax, [M] ; we isolate bits 5-8 of M
     and  ax, 00000000000000000000000111100000b
     mov  cl, 5
     ror  ax, cl ; we rotate 5 positions to the right
     or   bx, ax ; we put the bits into the result

     or   bx, 00000000000000000000000011110000b ; we force the value of bits 4-7 of the result to the value 1

     and  bx, 00000011111111111111111111111111b ; facem biti 27-31 din rezultat sa aiba valoarea 0
     
     mov  ax, [M]; we isolate bits 8-26 of M
     and  ax, 00000111111111111111111100000000b
     or   bx,ax; punem bitii in rezultat
     mov [MNew],bx;we move the result form the register to the result variable

     push dword 0 ;saves on stack the parameter of the function exit
     call [exit] ;function exit is called in order to end the execution of
the program	
