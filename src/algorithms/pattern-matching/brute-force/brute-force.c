#include "brute-force.h"

void BruteForce(Text T, long *n, Pattern P, long *m) { 
    long i, j, k;
    for (i = 1; i <= (*n - *m + 1); i++) { 
        k = i;
        j = 1;
        while (T[k-1] == P[j-1] && j <= *m) { 
            j++; 
            k++;
        }
        if (j > *m)
            printf(" Casamento na posicao%3ld\n", i);
    }
}