#include <stdio.h>
#include "sort.h"
#include "MaxHeap.h"
#define SIZE 6
int main(void)
{
    int array[SIZE] = {0, 5, 3, 7, 2, 6};
    /*BubbleSort(array, SIZE);
    printf("%d %d %d %d %d %d\n", array[0], array[1], array[2], array[3], array[4], array[5]);
    WineSort(array, SIZE);
    printf("%d %d %d %d %d %d\n", array[0], array[1], array[2], array[3], array[4], array[5]);
    NumberSort(array, SIZE);
    printf("%d %d %d %d %d %d\n", array[0], array[1], array[2], array[3], array[4], array[5]);*/
    HeapSort(array, SIZE);
    printf("%d %d %d %d %d %d\n", array[0], array[1], array[2], array[3], array[4], array[5]);
    getchar();
    return 0;
}