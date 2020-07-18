#include <stdio.h>
#include <stdlib.h>
#include "MaxPriorityQueue.h"

int Parent(int i)
{
    return (i / 2);
}

int Left(int i)
{
    return (i * i);
} 

int Right(int i)
{
    return (i * i + 1);
}

void MaxHeapify(int array[], int i, int size)
{
    int l = Left(i);
    int r = Right(i);
    int largest;
    int temp;
    if(l <= size && array[l] > array[i])
    {
        largest = l;
    }
    else
        largest = i;
    if(r <= size && array[r] > array[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        MaxHeapify(array, largest, size);
    }
}

int MaxNum(int array[])
{
    return array[0];
}

int ExtractMax(int array[], int size)
{
    int max;
    if(size < 1)
    {
        exit(-1);
    }
    max = array[0];
    array[0] = array[size];
    size--;
    MaxHeapify(array, 0, size);
    return max;
}

void IncreaseKey(int array[], int i, int key)
{
    int temp;
    if(key < array[i])
    {
        exit(-1);
    }
    array[i] = key;
    while(i > 0 && array[Parent(i)] < array[i])
    {
        temp = array[i];
        array[i] = array[Parent(i)];
        array[Parent(i)] = temp;
        i = Parent(i);
    }
}

void Insert(int array[], int x, int size)
{
    size++;
    array[size] = INT_MIN; 
    IncreaseKey(array, size, x);
}
