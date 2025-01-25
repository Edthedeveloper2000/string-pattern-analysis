#include "shift-and.h"

void ShiftAnd(TipoTexto T, long *n, TipoPadrao P, long *m) { 
    long Masc[Maxchar];
    long i;
    long R = 0;
    for (i = 0; i < Maxchar; i++)
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