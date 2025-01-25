#ifndef COMMON_H
#define COMMON_H

//Incluindo Bibliotecas padrão:
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Definições de cores ANSI
#define RED "\x1b[31m"       // Vermelho
#define WHITE "\x1b[37m"     // Branco
#define YELLOW "\x1B[33m"    // Amarelo
#define BLUE "\x1B[34m"      // Azul
#define GREEN "\e[0;32m"     // Verde
#define RESET "\033[0m"      // Resetar cor

// O ifdef abaixo verifica o sistema operacional, para 
// incluir a biblioteca corretamente
#ifdef __unix__         
    #include <unistd.h>

#elif defined(_WIN32) || defined(WIN32) 

   #define OS_Windows

   #include <windows.h>

#endif
#endif