#include <stdio.h>
#include "SelectSort.h"

int _select_sort_find_min(int array[], int length, int start)
{
    int min;
    int pos = start;
    min = array[start];
    for(int i = start + 1; i < length; i++)
    {
        if(array[i] < min)
        {
            min = array[i];
            pos = i;
        }
    }
    return pos;
}

void select_sort(int array[], int length)
{
    int little_pos_1 = 0;
    int min;
    int little_pos_2;
    while(little_pos_1 < length)
    {
        little_pos_2 = _select_sort_find_min(array, length, little_pos_1);
        min = array[little_pos_2];
        array[little_pos_2] = array[little_pos_1];
        array[little_pos_1] = min;
        little_pos_1++;
    }
}