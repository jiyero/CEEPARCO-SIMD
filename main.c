//Jihro Abendano S11
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern  long long int sdot_non( int n,  long long int* A,  long long int* B);
//extern  long long int sdot_simd( long long int n,  long long int* A,  long long int* B);
    
unsigned long long int dotProductC(int n, long long int* A, long long int* B) {
    long long int  sdot = 0;
    for (int i = 0; i < n; i++) {
        sdot += A[i] * B[i];
    }
    return sdot;
}
int main() {
     long long int  n = 1 << 20; // Vector size

    // Allocate memory 
     long long int* A = (long long int*)malloc(n * sizeof(long long int));
     long long int* B = (long long int*)malloc(n * sizeof(long long int));

    // Initialize Vectors with integer 3
    for (int i = 0; i < n; i++) {
        A[i] = 3;
        B[i] = 3;
    }

    //C Kernel and timer
    for (int i = 0; i < 30; i++) {
        clock_t start = clock();
        long long int  sdot = dotProductC(n, A, B);
        clock_t end = clock();
        double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Run %d\n", i+1);
        printf("C Kernel Result: %lld\n", sdot);
        printf("C Kernel Execution Time: %f seconds\n\n", cpu_time_used);
    }


    //Non SIMD Kernel and timer
    clock_t start2 = clock();
    long long int sdotasm = sdot_non(n, A, B);
    clock_t end2 = clock();
    double nonsimd_time_used = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
    printf("x86 Kernel Result: %lld\n", sdotasm);
    printf("x86 Kernel Execution Time: %f seconds\n\n", nonsimd_time_used);

 

    // Free allocated memory
    free(A);
    free(B);

    return 0;
}