#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"


int main(int argc, char **argv){
    FILE *fp;
 
    double key;
    int returnV;
    char Word[100];

    if (argc < 3){
        fprintf(stderr, "Usage: %s <ifile> <ofile>\n", argv[0]);
        exit(0);
    }

    fp    = NULL;

    fp = fopen(argv[1], "r");
    if (!fp){
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(0);
    }
    // File opened for reading...
// Work on the logic inside each if statement. 
  while (1){
        returnV = nextInstruction(Word, &key);

        if (returnV == 0){
            fprintf(stderr, "Warning: Invalid instruction: %s\n", Word);
            continue;
        }


        if (strcmp(Word, "Stop")==0){
            return 0;
        }


        if (strcmp(Word, "Read")==0){          
            continue;
        }


        if (strcmp(Word, "Print")==0){
            continue;
        }


        if (strcmp(Word, "Write")==0){
            // look at stacklist implementation of write. they are somewhat similar 
            continue;
        }


        if (strcmp(Word, "Init")==0){
            continue;
        }


        if (strcmp(Word, "Insert")==0){         
            continue;
        }


        if (strcmp(Word, "ExtractMin")==0){   
            continue;
        }


        if (strcmp(Word, "DecreaseKey")==0){
            continue;
        }


    }



}