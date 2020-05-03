#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

void UpAdJust(int array[], int length)
{
    int childIndex = length - 1;
    int parentIndex = (childIndex - 1) / 2;

    int temp = array[childIndex];
    while(childIndex > 0 && temp < array[parentIndex])
    {
        array[childIndex] = array[parentIndex];
        childIndex = parentIndex;
        parentIndex = (parentIndex - 1) / 2;
    }
    array[childIndex] = temp;
}

void DownAdJust(int array[], int parentIndex, int length)
{
    int temp = array[parentIndex];
    int childIndex = 2 * parentIndex + 1;

    while(childIndex < length)
    {
        if(childIndex + 1 < length && array[childIndex + 1] < array[childIndex])
        {
            childIndex++;
        }

        if(temp <= array[childIndex])
        {
            break;
        }

        array[parentIndex] = array[childIndex];
        parentIndex = childIndex;
        childIndex = 2 * childIndex + 1;
    }
    array[parentIndex] = temp;
}

void BuildHeap(int array[], int length)
{
    for(int i = (length - 2) / 2; i >= 0; i--)
    {
        DownAdJust(array, i, length);
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