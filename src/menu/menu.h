#include "../common.h"
#include "../algorithms/pattern-matching/brute-force/brute-force.h"
#include "../algorithms/pattern-matching/shift-and/shift-and.h"
#include "../io/file-reader.h"
#include "../types/types.h"
#ifndef MENU
#define MENU

void mainMenu();

void fileReaderMenu();

void findPattern(Text text, Pattern pattern);
void encryptText(Text text);
void decryptText(Text text);
void menuClear();

void menuClear();
#endif

