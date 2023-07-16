section .text
global sdot_simd

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

    movd    edx, xmm0           
    add     eax, edx

    pop     rbp
    ret
