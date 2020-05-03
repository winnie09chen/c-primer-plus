#ifndef HEAP_H_
#define HEAP_H_

void UpAdJust(int array[], int length);

void DowdAdJust(int array[], int parentIndex, int length);

void BuildHeap(int array[], int length);

void PrintHeap(int array[], int length, int space, int location);

#endif
