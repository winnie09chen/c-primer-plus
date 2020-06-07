#include <stdio.h>
#include "mylib.h"
#define ARRAY_SIZE 11

int main(void)
{
    int array[ARRAY_SIZE] = { 45, 67, 4, 2, 45, 67, 9, 100, 23, 7, 11};

    //merge_sort(array, ARRAY_SIZE);
    select_sort(array, ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d\n", array[i]);
    }
    getchar();
    return 0;
}