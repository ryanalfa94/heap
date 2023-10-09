#include <stdio.h>
#include <string.h>
#include "util.h"

int nextInstruction(char *Word, double *Key)
{
    int  returnV;
    int position; 

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
    else if (strcmp(Word, "DecreaseKey")==0)    {


        /*
        decreasKey gives u a position and a new key. we scan both of em
        pass em through and check if both are numbers if so return 1 otherwise return 0. 
        */
        position = fscanf(stdin, "%d", position);
        returnV = fscanf(stdin, "%lf", Key);

         if (position == 1 && returnV == 1){
            return 1;
        }else{
            return 0;
        }

    }
    else {

        printf(" not a correct instruction !!!!!!!");
    }

   

    return 0;
}