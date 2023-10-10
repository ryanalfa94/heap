/*
Ryan Alfa
ASU ID 1221954331
*/

#include  "data_structures.h"
#include "heap.h"
#include "stdio.h"
#include "stdlib.h"
#include <cmath>
#include <iostream>

// helpful functions. 

int heapifyCount =0; 
bool IsHeapFull(HEAP* heap) {
    return heap->size >= heap->capacity;
}

void DecreaseKeyHeapify(HEAP* heap, int position) {
    int parent = (position - 1) / 2;

    while (position > 0 && heap->H[position]->key < heap->H[parent]->key) {
        // Swap the element with its parent
        ELEMENT* temp = heap->H[position];
        heap->H[position] = heap->H[parent];
        heap->H[parent] = temp;

        // Move up to the parent position
        position = parent;
        parent = (position - 1) / 2;
    }
}


bool isMinHeap(HEAP* heap) {
    // Check if the heap pointer is NULL
    if (heap == nullptr) {
        return false;
    }

    int n = heap->size;

    // Start from the first non-leaf node and check each parent-child relationship
    for (int i = 0; i < n / 2; i++) {
        double parent = heap->H[i]->key;
        double leftChild = heap->H[2*i] ->key; 
        double rightChild = heap->H[(2*i)+1] ->key; 

        // Check if the parent is greater than its children
        if (parent > leftChild || parent > rightChild) {
            return false;
        }
    }

    return true; // If all parent-child relationships are satisfied, it's a Min-Heap
}



// end of helpful functions. 



void Heapify(HEAP* heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Find the smallest among the current node, left child, and right child   
    if (left < heap->size && heap->H[left]->key < heap->H[smallest]->key) {
        smallest = left;
    }

    if (right < heap->size && heap->H[right]->key < heap->H[smallest]->key) {
        smallest = right;
    }

    if (smallest != i) {
        //swaping the elements
        ELEMENT* temp = heap->H[i];
        heap->H[i] = heap->H[smallest];
        heap->H[smallest] = temp;

        // Recursively call Heapify on the affected subtree
        Heapify(heap, smallest);

        // Increment the count for each Heapify call
        heapifyCount++;
        
    }
}

HEAP* BuildHeap(HEAP* heap) {
    for (int i = (heap->size - 1) / 2; i >= 0; i--) {
        Heapify(heap, i);
    }
    return heap;
}





HEAP* Init(int Capacity) {
    // Print the instruction to stdout
    printf("Instruction: Init %d\n",Capacity);   

    // Allocate memory for the HEAP object
    HEAP* heap = new HEAP;
    if (heap == nullptr) {
        printf("Memory allocation for HEAP object failed.\n");
        return nullptr;
    }

    // Allocate memory for the pointer to pointer (heap array) of ELEMENT objects
    heap->H = new ELEMENT*[Capacity];
    if (heap->H == nullptr) {
        printf("Memory allocation for heap array failed.\n");
        delete heap; // Free the previously allocated HEAP object
        return nullptr;
    }

    // Initialize the size and capacity of the HEAP object
    heap->size = 0;
    heap->capacity = Capacity;

    return heap;
}



HEAP* Insert(HEAP* heap, double key, int flag) {
    // Check if the heap is NULL
    if (heap == nullptr) {
        fprintf(stderr,"Error: heap is NUll\n");
        return nullptr;
    }

    // Check if the heap is full
    if (IsHeapFull(heap)) {
        fprintf(stderr,"Error: heap is full\n");
        return heap;
    }

    // Dynamically allocate memory for an ELEMENT object
    ELEMENT* element = new ELEMENT;
    if (element == nullptr) {
        printf("memory allocation for ELEMENT object failed\n");
        return heap;
    }

    // Set the key field of the ELEMENT object
    element->key = key;

    // Insert the element into the min heap
    int pos = heap->size;
    heap->H[pos] = element;
    heap->size++;

    // CALLING BUILD HEAP TO MAKE THE NEW ARRAY A MINHEAP.
    heap = BuildHeap(heap);
        int position = -1;
        for (int i = 0; i < heap->size; i++) {
        if (heap->H[i]->key == key) {
            position = i; // Element found, update the position
            break; // Exit the loop since we found the element
        }
    }

      // Print the appropriate message based on the flag
            if (flag == 2 || flag == 3){
                printf("Element with key %.6lf inserted at location %d of the heap array\n",key,position);
            }else{
                printf("Instruction: Insert %.6lf\n",key);
            } 
    return heap;
}


void PrintHeap(HEAP* heap) {
    if (heap == nullptr) {
        fprintf(stderr,"Error: heap is NUll\n");
        return;
    }

    // Print the instruction to stdout
    printf("Instruction: Print\n");

    // Print the size of the heap (number of elements)
    printf("%d\n",heap->size);

    // Print the key values of the elements
    for (int i = 0; i < heap->size; i++) {
        printf("%.6lf\n", heap->H[i]->key);
    }

}



// Function to extract the minimum element from the heap
HEAP* ExtractMin(HEAP* heap, int flag) {
    // Check if the heap is NULL
    if (heap == NULL) {
        fprintf(stderr, "Error: heap is NULL\n");
        return heap;
    }

    // Check if the heap is empty
    if (heap->size == 0) {
        fprintf(stderr, "Error: heap is empty\n");
        return heap;
    }

    // Save the minimum key
    double minKey = heap->H[0]->key;

    // Replace the minimum element with the last element
    heap->H[0] = heap->H[heap->size - 1];
    heap->size--;

    // Perform Heapify to restore the min-heap property
    Heapify(heap, 0);
    heapifyCount++; // Increment the count after each Heapify operation

    // Reset the heapifyCount before each ExtractMin operation

    if (flag == 1 || flag == 3) {
        // Print additional information for flag 1 or 3
        printf("Element with key %.6lf extracted from the heap\n", minKey);
        // Print the number of Heapify calls
        printf("Number of Heapify calls triggered by ExtractMin: %d\n", heapifyCount);
    } else {
        // Print basic information for flag 0 or 2
        printf("Element with key %.6lf extracted from the heap\n", minKey);
    }

    heapifyCount = 0;

    return heap;
}



HEAP* DecreaseKey(HEAP* heap, int position, double newKey, int flag) {
    // Check if the heap is NULL
    if (heap == nullptr) {
        fprintf(stderr, "Error: heap is NULL\n");
        return heap;
    }

    // Check if the heap is empty
    if (heap->size == 0) {
        fprintf(stderr, "Error: heap is empty\n");
        return heap;
    }

    // Check if <Position> is out of range
    if (position < 0 || position >= heap->size || newKey >= heap->H[position]->key) {
        fprintf(stderr, "Error: invalid call to DecreaseKey\n");
        return heap;
    }

    // Update the key field of the corresponding object
    
    heap->H[position]->key = newKey;

    // Perform DecreaseKey-specific heap maintenance
    DecreaseKeyHeapify(heap, position);

  

    return heap;
}