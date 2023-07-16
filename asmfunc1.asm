;Jihro Abendano S11
section .text
default rel
bits 64
global sdot_non

sdot_non:
   push     rbp
   mov      rbp, rsp
   sub      rsp, 8       

   mov      r12, rdx
   mov      r13, r8
   xor      r15, r15

   cmp      rcx, 0
   jle      Exit        

   Loop:
      mov      rax, qword [r12]
      imul     rax, qword [r13]
      add      r15, rax

      add      r12, 8
      add      r13, 8

      sub      rcx, 1
      jnz      Loop       

   Exit:
      mov      rax, r15
      mov      rsp, rbp   
      pop      rbp
      ret