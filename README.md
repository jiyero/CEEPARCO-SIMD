# CEEPARCO-SIMD

![SIMD SC](https://github.com/jiyero/CEEPARCO-SIMD/assets/90267825/4df7c3bd-2ff2-4af9-bee9-c682bf745bbd)

# Dot product implementation with vectors initialized with the integer 3. Kernels are ran 30 times and average time is taken. Could not implement x86-64 with YMM Register.
###
Main.c         ->   C implementation
asmfunc1.asm   ->   x86-64 implementation
asmfunc2.asm   ->   SIMD YMM Register (Attempted)


## C Kernel

### 2^20 Vector Size
![image](https://github.com/jiyero/CEEPARCO-SIMD/assets/90267825/c04984c1-de66-414a-8872-e48b83b9dd69)


### 2^24 Vector Size 
![image](https://github.com/jiyero/CEEPARCO-SIMD/assets/90267825/1b870396-0d3f-4f80-b364-f16a3f43aee6)



### 2^29 Vector Size 
![image](https://github.com/jiyero/CEEPARCO-SIMD/assets/90267825/3f57cd0e-ec93-4aed-a7d8-1095b1dd5059)



## Non-SIMD x86-64 Kernel

### 2^20 Vector Size
![image](https://github.com/jiyero/CEEPARCO-SIMD/assets/90267825/0f4c849e-50af-4015-9661-be48682c55b4)


### 2^24 Vector Size
![image](https://github.com/jiyero/CEEPARCO-SIMD/assets/90267825/f1c75039-be3e-4fa3-9275-5f00d979e9a6)



### 2^29 Vector Size
![image](https://github.com/jiyero/CEEPARCO-SIMD/assets/90267825/a76483d4-2b15-4241-a267-84ccbf4b429a)

### Analysis

The x86-64 is able to achieve faster execution time compared to the C implementation. In x86-64, it uses registers, which is faster compared to cache memory due to its smaller size and its proximity to the CPU. High-level languages tend to take up a significant amount of memory when compiling compared to assembly language. This can significantly affect execution time since additional processes will be needed for the implementation thus increasing the execution time. Additionally, x86-64 directly requires manual input from the programmer who will also handle specific processor capabilities and instructions. 
