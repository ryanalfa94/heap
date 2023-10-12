/*
Ryan Alfa
ASU ID 1221954331
*/

#include <stdio.h>
#include <string.h>
#include "util.h"

int nextInstruction(char *Word, double *Key)
{
    int  returnV;
   

    fscanf(stdin, "%s", Word);

    if (strcmp(Word, "Stop")==0)   return 1;
    else if (strcmp(Word, "Read")==0)   return 1;
    else if (strcmp(Word, "Print")==0)  return 1;
    else if (strcmp(Word, "Write")==0)  return 1;


    else if (strcmp(Word, "Init")==0){    
        // after we checked it was an init, we scan the number after init aka the size 
        returnV = fscanf(stdin, "%lf", Key); 
        /*
        If fscanf successfully reads a value and assigns it to Key, 
        it returns 1, indicating that one value was successfully read.
        If fscanf fails to read a value (e.g., due to incorrect input or the end of the input stream), 
        it returns a value other than 1.
        */
         if (returnV == 1){
            return 1;
        }else{
            return 0;
        }
    }

    else if (strcmp(Word, "Insert")==0){
        
         // after we checked it was an insert, we scan the number we inserting.
        returnV = fscanf(stdin, "%lf", Key); 
        /*
        If fscanf successfully reads a value and assigns it to Key, 
        it returns 1, indicating that one value was successfully read.
        If fscanf fails to read a value (e.g., due to incorrect input or the end of the input stream), 
        it returns a value other than 1.
        */
         if (returnV == 1){
            return 1;
        }else{
            return 0;
        }
    }

    else if (strcmp(Word, "ExtractMin")==0)    return 1;
    else if (strcmp(Word, "DecreaseKey")==0)    return 1;
    
    else {
    }

   

    return 0;
}