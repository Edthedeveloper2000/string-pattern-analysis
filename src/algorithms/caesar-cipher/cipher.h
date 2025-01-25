#include "../../common.h"
#ifndef CIFRA_H
#define CIFRA_H

#define ALPHABET_SIZE 26
#define ASCII_OFFSET 'a'

typedef struct {
    char letter;
    float frequency;
} Frequency;

extern Frequency freq_table[];

void encrypt_decrypt_text(char *text, int key, int encrypt);
void calculate_frequencies(const char *text, float frequencies[]);
int guess_key(const float frequencies[]);

#endif 