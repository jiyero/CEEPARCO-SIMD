section .text
global sdot_simd

; sdot_simd function
; Inputs:
;   int n           - Vector size
;   long long int* A - Pointer to the first vector
;   long long int* B - Pointer to the second vector
; Outputs:
;   long long int   - Dot product result

sdot_simd:
    push    rbp
    mov     rbp, rsp
    mov     rdi, rdi            
    shr     rdi, 4              
    vpxor   ymm0, ymm0, ymm0    

dot_loop:

    vmovaps ymm1, [rsi]
    vmovaps ymm2, [rdx]


    vpmulld ymm1, ymm1, ymm2
    vpaddd  ymm0, ymm0, ymm1

    add     rsi, 64             
    add     rdx, 64             

    dec     rdi                 
    jnz     dot_loop            


    vextracti128 xmm1, ymm0, 0x1
    vpaddd  xmm0, xmm0, xmm1
    phaddd  xmm0, xmm0
    phaddd  xmm0, xmm0

    ; Add the 32-bit sum to the accumulator (eax)
    movd    edx, xmm0           ; Move the result into edx (lower 32 bits)
    add     eax, edx

    pop     rbp
    ret
