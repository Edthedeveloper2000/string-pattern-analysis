#include "common.h"
#include "algorithms/pattern-matching/brute-force/brute-force.h"
#include "algorithms/pattern-matching/shift-and/shift-and.h"

void readText(Text T, long size, const char *message) {
    printf("%s", message);
    for (long i = 0; i < size; i++) {
        T[i] = getchar();
        if (T[i] == '\n') {
            T[i] = ' ';
        }
    }
    scanf("%*[^\n]");
    getchar();
}

void readPattern(Pattern P, long size, const char *message) {
    printf("%s", message);
    for ( long i = 0; i < size; i++) {
        P[i] = getchar();
        if (P[i] == '\n') {
            P[i] = ' ';
        }
    }
    scanf("%*[^\n]");
    getchar();
}

int main(int argc, char **argv) {
    Text T;
    Pattern P;
    long n, m;

    // Ler tamanho do texto
    printf("Tamanho do texto: ");
    scanf("%ld%*[^\n]", &n);
    getchar();

    // Ler tamanho do padrão
    printf("Tamanho do padrão: ");
    scanf("%ld%*[^\n]", &m);
    getchar();

    // Ler o texto
    readText(T, n, "Texto: ");

    // Ler o padrão
    readPattern(P, m, "Padrão: ");

    // Executar os algoritmos 
    printf("\nResultados:\n");

    printf("Força bruta: ");
    BruteForce(T, &n, P, &m);

    printf("Shift-And-Exato: ");
    ShiftAnd(T, &n, P, &m);

    return 0;
}