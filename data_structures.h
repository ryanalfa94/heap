/*
Ryan Alfa
ASU ID 1221954331
*/

#ifndef _data_structs_H
#define _data_structs_H 1

typedef struct TAG_ELEMENT{
    double key;
    //int position; 
    // other fields as you see fit
}ELEMENT;
typedef struct TAG_HEAP{
    int capacity; /* capacity of the heap */
    int size; /* current size of the heap */
    ELEMENT **H; /* array of pointers to ELEMENT */
    // other fields as you see fit
}HEAP;

#endif