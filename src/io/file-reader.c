#include "file-reader.h"

void readFile(const char* filename, Text text){
    FILE* file = fopen(filename, "r");
    if(!file){
        printf("Erro ao abrir arquivo\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long lenght = ftell(file);
    fseek(file, 0, SEEK_SET);

    if(lenght == 0){
        fclose(file);
        printf("O arquivo fornecido esta vazio\n");
        return;
    }
    fread(text, 1, lenght, file);
    text[lenght]= '\0';

    fclose(file);
}

