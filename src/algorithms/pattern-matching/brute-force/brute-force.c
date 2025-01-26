#include "brute-force.h"

void BruteForce(Text T, Pattern P) {

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    long i, j, k;
    for (i = 1; i <= (textSize - patternSize + 1); i++) { 
        k = i;
        j = 1;
        while (T[k-1] == P[j-1] && j <= patternSize) { 
            j++; 
            k++;
        }
        // if (j > patternSize)
        //     printf(" Casamento na posicao%3ld\n", i);
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao brute-force: %.10lf segundos\n", cpu_time_used);
}