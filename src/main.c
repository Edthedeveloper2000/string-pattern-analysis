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
    mainMenu();
    return 0;
}
