/*
Ryan Alfa
ASU ID 1221954331
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "heap.h"
using namespace std; 


int main(int argc, char **argv){
    
    FILE *fp;
    HEAP *minHeap; 
    //int position; 
    double key;
    int returnV;
    char Word[100];
    //int capacity;
    //ELEMENT *pELEMENT;
    

    if (argc < 4){
        fprintf(stderr, "Usage: %s <ifile> <ofile>\n", argv[0]);
        exit(0);
    }

    int flag = atoi(argv[3]);

     if (flag > 4 || flag < 0){
        fprintf(stderr, "Error: Flag must be {0,1,2,3}\n");
        exit(0);
    }

    fp = NULL;

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
            printf("Instruction: Stop\n");
            return 0;
        }


        if (strcmp(Word, "Read")==0){ 
            


            FILE* inputFile = fopen(argv[1], "r");
            if (!inputFile) {
                printf("cannot open input file");
                return 1;
            }

            printf("Instruction: Read\n");
            

            // Check if the heap is NULL
            if (minHeap == nullptr) {
                fprintf(stderr,"Error: heap is NUll\n");
                fclose(inputFile); // Close the input file
                continue;
            }

            // Read n from the file
            int n;
            if (fscanf(inputFile, "%d", &n) != 1) {
                printf("invalid input file format");
                fclose(inputFile); // Close the input file
                continue;
            }

            // Check if heap->capacity is smaller than n
            if (minHeap->capacity < n) {
                fprintf(stderr,"heap capacity is smaller than n");
                fclose(inputFile); // Close the input file
                continue;
            }

            // Read keys and insert elements into the heap
            for (int j = 0; j < n; j++) {
                double fileKey;
                if (fscanf(inputFile, "%lf", &fileKey) != 1) {
                    printf("invalid key in input file");
                    fclose(inputFile); // Close the input file
                    continue;
                }
                ELEMENT* element = new ELEMENT;
                element->key = fileKey;
                int pos = minHeap->size;
                minHeap->H[pos] = element;
                minHeap->size++;

                // not sure about this ask professor.
            }


             if (isMinHeap(minHeap)){
                    fclose(inputFile);
                    continue;
                }else {
                    if (flag == 1 || flag == 3){
                        printf("Input array is NOT a MinHeap\nCall BuildHeap\n");
                        minHeap = BuildHeap(minHeap);
                        printf("Number of Heapify calls triggered by BuildHeap: <count>");
                }
                }
            // Close the input file
            fclose(inputFile);
            continue;
        }


        if (strcmp(Word, "Print")==0){
            PrintHeap(minHeap);
            continue;
        }


        if (strcmp(Word, "Write")==0){
            

            printf("Instruction: Write\n");
             // Check if the heap is NULL
            if (minHeap == nullptr) {
                fprintf(stderr,"Error: heap is NULL\n");
                continue;
            }

            // Open the output file for writing
            const char* outputFile = argv[2];
            FILE* file = fopen(outputFile, "w");
            if (!file) {
                printf("cannot open output file");
                continue;
            }

            // Write heap information to the file
            fprintf(file, "%d\n", minHeap->size);
            for (int i = 0; i < minHeap->size; i++) {
                fprintf(file,"%.6lf\n", minHeap->H[i]->key); // Adjust format as needed
            }

            // Close the output file
            fclose(file);



            continue;
        }


        if (strcmp(Word, "Init")==0){
            minHeap = Init(key);
            continue;
        }


        if (strcmp(Word, "Insert")==0){
            Insert(minHeap,key,flag);       
            continue;
        }


        if (strcmp(Word, "ExtractMin")==0){ 
            printf("Instruction: ExtractMin\n");
            minHeap = ExtractMin(minHeap,flag);   
            continue;
        }


        if (strcmp(Word, "DecreaseKey")==0){
            printf("Instruction: DecreaseKey ");
            int Position =0;
            double newKey =0;

            // Parse the position and newKey values from input
            if (scanf("%d %lf", &Position, &newKey) != 2) {
                 fprintf(stderr, "Error: Invalid DecreaseKey instruction\n");
                 continue;
            }
            Position = Position - 1;
            // Call the DecreaseKey function
            minHeap = DecreaseKey(minHeap, Position, newKey, flag);
            Position = Position + 1;
            printf("%d %.6lf\n",Position, newKey);
            continue;
        }


    }



}