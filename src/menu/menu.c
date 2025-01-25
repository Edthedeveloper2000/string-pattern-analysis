#include "menu.h"

void mainMenu() {
    printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|\n");
    printf("|              "BLUE"MENU"RESET"             |\n");
    printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|\n");
    printf("|   1 - Carregar arquivo        |\n");
    printf("|   2 - Sair                    |\n");
    printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|\n");
    printf("| >>> ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            menuClear();
            fileReaderMenu(text, pattern);
            break;
        case 2:
            exit(0);  
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            mainMenu();  
            break;
    }
}

void fileReaderMenu(Text text, Pattern pattern) {
    char path[100];
    printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|\n");
    printf("|            "BLUE"LEITURA DO ARQUIVO"RESET"           |\n");
    printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|\n");
    printf("| Digite o caminho do arquivo de texto:   |\n");
    printf("| >>> ");
    scanf("%s", path);
    readFile(path, text);
    textSize = strlen((char *) text);
    menuClear();
    choiceMenu();
}

void choiceMenu() {
    do {
        printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|\n");
        printf("|       "GREEN"OPÇÕES APÓS CARREGAR ARQUIVO"RESET"      |\n");
        printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|\n");
        printf("|   1 - Encontrar padrão de texto         |\n");
        printf("|   2 - Criptografar texto                |\n");
        printf("|   3 - Descriptografar texto             |\n");
        printf("|   4 - Chave aleatória                   |\n");
        printf("|   5 - Voltar ao menu principal          |\n");
        printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|\n");
        printf("| >>> ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("| Digite o padrão a ser encontrado:\n");
                printf("| >>> ");
                scanf("%s", pattern);
                patternSize = strlen((char *) pattern);
                findPattern(text, pattern);
                break;
            case 2:
                encryptText(text);
                break;
            case 3:
                decryptText(text);
                break;
            case 4:
                encryptGuessKey(text);
                break;
            case 5:
                menuClear();
                mainMenu(); 
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
        system("pause");
        menuClear();
    } while (choice != 5); 
}

void findPattern(Text text, Pattern pattern) {
   printf("\n| Tempo de execução:\n");

    printf("| Força bruta: ");
    BruteForce(text, pattern);

    printf("| Shift-And: ");
    ShiftAnd(text, pattern);
}

void encryptText(Text text) {
    int key;
    char out_file[100];
    Text cpy_text;
    strcpy((char *) cpy_text, (char *) text);
    printf("Digite a chave para criptografar: ");
    scanf("%d", &key);
    printf("Digite o caminho do arquivo de saida: ");
    scanf("%s", out_file);
    encrypt_decrypt_text(cpy_text, key, ENCRYPT, out_file);
    printf("\n");
    printf("Texto criptografado com sucesso!\n");
}

void decryptText(Text text) {
    int key;
    char out_file[100];
    Text cpy_text;
    strcpy((char *) cpy_text, (char *) text);
    printf("Digite a chave para descriptografar: ");
    scanf("%d", &key);
    printf("Digite o caminho do arquivo de saida: ");
    scanf("%s", out_file);
    encrypt_decrypt_text(cpy_text, key, DECRYPT, out_file);
    printf("\n");
    printf("Texto descriptografado com sucesso!\n");
}

void encryptGuessKey(Text text){
    int key = 1 + rand() % 50;
    char out_file[100];
    Text cpy_text;
    strcpy((char *) cpy_text, (char *) text);
    float frequencies[26];
    printf("Digite o caminho do arquivo de saida: ");
    scanf("%s", out_file);
    printf("\n");
    encrypt_decrypt_text(cpy_text, key, ENCRYPT, out_file);
    calculate_frequencies(cpy_text, frequencies);
    printf("\n");
    printf("Tabela de frequências:\n ");
    for(int i = 0; i < 26; i++){
        char letter = 'a' + i; 
        printf("%c: %.2f%%\n", letter, frequencies[i]);
    }
    printf("Chave advinhada: %d\n", guess_key(frequencies));
}


void menuClear() {
    #ifdef OS_Windows
        system("cls");
    #else
        system("clear");
    #endif 
}