#include "common.h"
#include "algorithms/pattern-matching/brute-force/brute-force.h"
#include "algorithms/pattern-matching/shift-and/shift-and.h"

int main(int argc, char **argv)
{ printf(" Tamanho do texto: ");
  scanf("%ld%*[^\n]", &n);
  getchar();
  printf(" Tamanho do padrao: ");
  scanf("%ld%*[^\n]", &m);
  getchar();
  printf(" Texto: ");
  for (i = 1; i <= n; i++) 
    { T[i-1] = getchar();
      if (T[i-1] == '\n')
      T[i-1] = ' ';
    }
  scanf("%*[^\n]");
  getchar();
  printf(" Padrao: ");
  for (i = 1; i <= m; i++) 
    { P[i-1] = getchar();
      if (P[i-1] == '\n')
      P[i-1] = ' ';
    }
  scanf("%*[^\n]");
  getchar();
  printf(" Forca bruta: ");
  BruteForce(T, &n, P, &m);
  scanf("%*[^\n]");
  getchar();
  printf(" Shift-And-Exato: ");
  ShiftAnd(T, &n, P, &m);
  scanf("%*[^\n]");
  return 0;
}