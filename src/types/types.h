#include "../common.h"
#ifndef TYPES
#define TYPES

#define MaxTamText     1000000
#define MaxTamPattern    10
#define MaxChar         256
#define MaxError         10

typedef unsigned char Text[MaxTamText];
typedef unsigned char Pattern[MaxTamPattern];

extern Text text;
extern Pattern pattern;
extern long patternSize;
extern long textSize;


#endif