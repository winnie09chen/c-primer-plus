#include <stdio.h>
#include "Heap.h"

#define SIZE 9

int main(void)
{
    int array[SIZE] = {0, 5, 3, 5, 2, 17, 9, 30, 4};
    BuildHeap(array, SIZE);
    for (int i = 0;  i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    getchar();
    return 0;
}