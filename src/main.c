#include "common.h"
#include "algorithms/pattern-matching/brute-force/brute-force.h"
#include "algorithms/pattern-matching/shift-and/shift-and.h"
#include "io/file-reader.h"
#include "menu/menu.h"

void readPattern(Pattern P, long size, const char *message) {
    printf("%s", message);
    for (long i = 0; i < size; i++) {
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
    char filename[256];  // Caminho do arquivo
    // Solicitar o caminho do arquivo
    printf("Digite o caminho do arquivo de texto: ");
    scanf("%s", filename);
    // Ler conteúdo do arquivo
    readFile(filename, T);

    n = strlen((char *) T);

    // Ler tamanho do padrão
    printf("Tamanho do padrão: ");
    scanf("%ld%*[^\n]", &m);
    getchar();

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
