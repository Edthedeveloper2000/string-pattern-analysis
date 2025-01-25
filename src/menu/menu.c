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
            exit(0);  // Encerra o programa
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            mainMenu();  // Chama novamente o menu principal
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
        printf("|       "BLUE"OPÇÕES APÓS CARREGAR ARQUIVO"RESET"         |\n");
        printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|\n");
        printf("|   1 - Encontrar padrão de texto         |\n");
        printf("|   2 - Criptografar texto                |\n");
        printf("|   3 - Descriptografar texto             |\n");
        printf("|   4 - Voltar ao menu principal          |\n");
        printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|\n");
        printf("| >>> ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("| Digite o padrão a ser encontrado:     |\n");
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
                menuClear();
                mainMenu();  // Volta ao menu principal
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
        system("pause");
        menuClear();
    } while (choice != 4); 
}

void findPattern(Text text, Pattern pattern) {
   printf("\nResultados:\n");

    printf("Força bruta: ");
    BruteForce(text, pattern);

    printf("Shift-And-Exato: ");
    ShiftAnd(text, pattern);
}

void encryptText(Text text) {
    // Função para criptografar o texto
    printf("Texto criptografado com sucesso!\n");
    // Implementar a lógica de criptografia
}

void decryptText(Text text) {
    // Função para descriptografar o texto
    printf("Texto descriptografado com sucesso!\n");
    // Implementar a lógica de descriptografia
}


void menuClear() {
    #ifdef OS_Windows
        system("cls");
    #else
        system("clear");
    #endif 
}