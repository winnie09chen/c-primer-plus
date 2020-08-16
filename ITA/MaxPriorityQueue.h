#ifndef MAX_PRIORITY_QUEUE_H__
#define MAX_PRIORITY_QUEUE_H__

void Insert(int array[], int x, int size);

int MaxNum(int array[]);

int ExtractMax(int array[], int size);

void IncreaseKey(int array[], int i, int key);

int Parent(int i);

int Left(int i);

int Right(int i);

void MaxHeapify(int array[], int i, int size);

#endif
