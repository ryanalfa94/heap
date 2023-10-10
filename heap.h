/*
Ryan Alfa
ASU ID 1221954331
*/

#ifndef _Heap_H
#define _Heap_H 1
#include "data_structures.h"

bool isMinHeap(HEAP* heap);
void PrintHeap(HEAP* heap);
void write(HEAP* heap, const char* filename);
HEAP* Init(int capacity);
HEAP* ExtractMin(HEAP* heap, int flag);
HEAP* DecreaseKey(HEAP* heap, int position, double newKey, int flag);
HEAP* Insert(HEAP* heap, double key, int flag);
void Heapify(HEAP* heap, int i);
HEAP* BuildHeap(HEAP* heap);
void printHeapifyCount();


#endif