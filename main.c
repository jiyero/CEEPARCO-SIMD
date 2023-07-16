//Jihro Abendano S11
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern  long long int sdot_non( int n,  long long int* A,  long long int* B);
extern  long long int sdot_simd( int n,  long long int* A,  long long int* B);
    
unsigned long long int dotProductC(int n, long long int* A, long long int* B) {
    long long int  sdot = 0;
    for (int i = 0; i < n; i++) {
        sdot += A[i] * B[i];
    }
    return sdot;
}
int main() {
     long long int  n = 1 << 20; // Vector size
     double avg;

    // Allocate memory 
     long long int* A = (long long int*)malloc(n * sizeof(long long int));
     long long int* B = (long long int*)malloc(n * sizeof(long long int));

    // Initialize Vectors with integer 3
    for (int i = 0; i < n; i++) {
        A[i] = 3;
        B[i] = 3;
    }
    double c_time_used;
    double nonsimd_time_used;
    double simd_time_used;
    double sumTime = 0;
/*
    //C Kernel and timer
    for (int i = 0; i < 30; i++) {
        clock_t start = clock();    
        long long int  sdot = dotProductC(n, A, B);
        clock_t end = clock();
        c_time_used = ((double)(end - start))*1e3/ CLOCKS_PER_SEC;
        sumTime = c_time_used + sumTime;
        printf("Run %d\n", i+1);
        printf("C Kernel Result: %lld\n", sdot);
        printf("C Kernel Execution Time: %f milliseconds\n\n", c_time_used);
    }
    avg = sumTime / 30;
    printf("Average time for C in milliseconds: %lf\n\n", avg);
    
    sumTime = 0;
    //Non SIMD Kernel and timer
    for (int i = 0; i < 30; i++) {
    clock_t start2 = clock();
    long long int sdotasm = sdot_non(n, A, B);
    clock_t end2 = clock();
    nonsimd_time_used = ((double)(end2 - start2))*1e3 / CLOCKS_PER_SEC;
    sumTime = nonsimd_time_used + sumTime;
    printf("Run %d\n", i + 1);
    printf("x86 Kernel Result: %lld\n", sdotasm);
    printf("x86 Kernel Execution Time: %f milliseconds\n\n", nonsimd_time_used);
    }

    avg = sumTime / 30;
    printf("Average time for Non-SIMD Kernel in milliseconds: %lf\n\n", avg);
*/
    sumTime = 0;
    
    //SIMD Kernel and Timer
    for (int i = 0; i < 30; i++) {
        clock_t start3 = clock();
        long long int sdotsim = sdot_simd(n, A, B);
        clock_t end3 = clock();
        simd_time_used = ((double)(end3 - start3)) * 1e3 / CLOCKS_PER_SEC;
        sumTime = simd_time_used + sumTime;
        printf("Run %d\n", i + 1);
        printf("SIMD Kernel Result: %lld\n", sdotsim);
        printf("SIMD Kernel Execution Time: %f milliseconds\n\n", simd_time_used);
    }


    avg = sumTime / 30;
    printf("Average time for Non-SIMD Kernel in milliseconds: %lf\n\n", avg);
    
    // Free allocated memory
    free(A);
    free(B);

    return 0;
}