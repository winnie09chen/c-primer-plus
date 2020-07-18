#include <stdio.h>
#include <stdlib.h>
#include "MergeSort.h"

void _merge_sort_merge(int array[], int p, int r, int q)
{
    int * marray = (int *) malloc(sizeof(int) * (q - p));
    int * marray_pos = marray;
    int l_begin = p;
    int l_end = r;
    int r_begin = r;
    int r_end = q;
    while(l_begin < l_end && r_begin < r_end)
    {
        if (array[l_begin] <= array[r_begin])
        {
            *marray_pos = array[l_begin++];
        }
        else
        {
            *marray_pos = array[r_begin++];
        }
        marray_pos++;
    }
    while (l_begin < l_end)
    {
        *marray_pos = array[l_begin++];
        marray_pos++;
    }
    while (r_begin < r_end)
    {
        *marray_pos = array[r_begin++];
        marray_pos++;
    }
    marray_pos = marray;
    for (; p < q; p++)
    {
        array[p] = *(marray_pos++);
    }
    free(marray);
}

void _merge_sort(int array[], int p, int r, int q)
{
    if (r - p > 1)
    {
        _merge_sort(array, p, (p+r)/2, r);

    }
    if (q - r > 1)
    {
        _merge_sort(array, r, (r+q)/2, q);
    } 
    _merge_sort_merge(array, p, r, q);
}

void merge_sort(int array[], int length)
{
    _merge_sort(array, 0, length/2, length);
}