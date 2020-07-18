#ifndef MAX_HEAP_H_
#define MAX_HEAP_H_

int Parent(int i);

int Left(int i);

int Right(int i);

void MaxHeapify(int array[], int i, int size);

void BuildMaxHeap(int array[], int size);

void HeapSort(int array[], int size);

void PrintHeap(int array[], int length, int space, int location);

#endif
