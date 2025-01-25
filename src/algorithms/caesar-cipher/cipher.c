#include "cipher.h"

Frequency freq_table[] = {
    {'a', 14.63}, {'b', 1.04}, {'c', 3.88}, {'d', 4.99},
    {'e', 12.57}, {'f', 1.02}, {'g', 1.30}, {'h', 1.28},
    {'i', 6.18},  {'j', 0.40}, {'k', 0.02}, {'l', 2.78},
    {'m', 4.74},  {'n', 5.05}, {'o', 10.73}, {'p', 2.52},
    {'q', 1.20},  {'r', 6.53}, {'s', 7.81}, {'t', 4.34},
    {'u', 4.63},  {'v', 1.67}, {'w', 0.01}, {'x', 0.21},
    {'y', 0.01},  {'z', 0.47}
};

void encrypt_decrypt_text(char *text, int key, int encrypt) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = base + (encrypt ? (text[i] - base + key) : (text[i] - base - key + ALPHABET_SIZE)) % ALPHABET_SIZE;
        }
    }
}

void calculate_frequencies(const char *text, float frequencies[]) {
    memset(frequencies, 0, ALPHABET_SIZE * sizeof(float));
    int total = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            frequencies[tolower(text[i]) - ASCII_OFFSET]++;
            total++;
        }
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        frequencies[i] = (frequencies[i] / total) * 100;
    }
}

int guess_key(const float frequencies[]) {
    int best_key = 0;
    float best_score = -1;

    for (int key = 0; key < ALPHABET_SIZE; key++) {
        float score = 0;

        for (int i = 0; i < ALPHABET_SIZE; i++) {
            int shifted_index = (i + key) % ALPHABET_SIZE;
            score += frequencies[shifted_index] * freq_table[i].frequency;
        }

        if (score > best_score) {
            best_score = score;
            best_key = key;
        }
    }

    return best_key;
}
