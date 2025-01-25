#include "shift-and.h"

void ShiftAnd(Text T, long *n, Pattern P, long *m) { 
    long Masc[MaxChar];
    long i;
    long R = 0;
    for (i = 0; i < MaxChar; i++)
        Masc[i] = 0;
    for (i = 1; i <= *m; i++) {
        Masc[P[i-1] + 127] |= 1 << (*m - i);
    }
    for (i = 0; i < *n; i++) { 
        R = ((((unsigned long)R) >> 1) | 
        (1 << (*m - 1))) & Masc[T[i] + 127];
        if ((R & 1) != 0)
            printf(" Casamento na posicao %3ld\n", i - *m + 2);
    }
}