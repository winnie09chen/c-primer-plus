#include <stdio.h>
#include "MaxPriorityQueue.h"

void print_array(int array[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
    
}

void main(void)
{
    int array[12] = {0};
    int size = -1;
    Insert(array, 17, size++);
    Insert(array, 0, size++);
    Insert(array, 10, size++);
    Insert(array, 7, size++);
    Insert(array, 30, size++);
    print_array(array, size + 1);
    getchar();
}