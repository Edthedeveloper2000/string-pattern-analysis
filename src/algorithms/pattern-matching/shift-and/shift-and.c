#include "shift-and.h"
#include <time.h>
#include <stdio.h>

void ShiftAnd(Text text, Pattern pattern) { 
    clock_t start, end;
    double cpu_time_used;


    start = clock();

    long Masc[MaxChar];
    long i;
    long R = 0;

    for (i = 0; i < MaxChar; i++)
        Masc[i] = 0;

    for (i = 1; i <= patternSize; i++) {
        Masc[pattern[i-1] + 127] |= 1 << (patternSize - i);
    }

    for (i = 0; i < textSize; i++) { 
        R = ((((unsigned long)R) >> 1) | (1 << (patternSize - 1))) & Masc[text[i] + 127];
        
        // if ((R & 1) != 0)
        //     printf(" Casamento na posicao %3ld\n", i - patternSize + 2);
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao shift-and: %f segundos\n", cpu_time_used);
}
