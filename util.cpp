#include <stdio.h>
#include <string.h>
#include "util.h"

int nextInstruction(char *Word, double *Key)
{
    int  returnV;

    fscanf(stdin, "%s", Word);

    if (strcmp(Word, "Stop")==0)   return 1;
    if (strcmp(Word, "Read")==0)   return 1;
    if (strcmp(Word, "Print")==0)  return 1;
    if (strcmp(Word, "Write")==0)  return 1;

    if (strcmp(Word, "Init")==0)    return 1;
    if (strcmp(Word, "Insert")==0)    return 1;

    if (strcmp(Word, "ExtractMin")==0)    return 1;
    if (strcmp(Word, "DecreaseKey")==0)    return 1;

    if (strcmp(Word, "Unknown")==0)    return 1;

    return 0;
}