#include <stdio.h>
#include <stdlib.h>
#include "MaxHeap.h"

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

void BuildMaxHeap(int array[], int size)
{
    int heapsize = size;
    for(int i = (size - 1) / 2; i >= 0; i--)
    {
        MaxHeapify(array, i, heapsize);
    }
}


void HeapSort(int array[], int size)
{
    BuildMaxHeap(array, size);
    int temp;
    for(int i = (size - 1); i >= 1; i--)
    {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        size--;
        MaxHeapify(array, 0, size);
    }
}

void PrintHeap(int array[], int length, int space, int location)
{
    if(location >= length)
    {
        return;
    }
    for(int i = 0; i < space; i++)
    {
        printf(" ");
    }
    printf("%d", array[location]);
    printf("\n");

    PrintHeap(array, length, space + 4, location * 2 + 1);
    PrintHeap(array, length, space + 4, location * 2 + 2);
}