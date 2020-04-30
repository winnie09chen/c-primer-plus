#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "sort.h"

// O(n2)
void BubbleSort(int array[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        bool IsSorted = true;
        for(int j = 0; j < size - i - 1; j++)
        {
            int temp = 0;
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                IsSorted = false;
            }
        }
        if(IsSorted)
        {
            goto a;
        }
    }
    a:;
}

void WineSort(int array[], int size)
{
    int temp = 0;
    for(int i = 0; i < size / 2; i ++)
    {
        bool IsSorted = true;
        for(int j = 0; j < size - i - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                IsSorted = false; 
            }
        }
        if(IsSorted)
        {
            goto a;
        }

        IsSorted = true;
        for(int j = size - i - 1; j > i; j--)
        {
            if(array[j] < array[j - 1])
            {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                IsSorted = false;
            }
        }
        if(IsSorted)
        {
            goto a;
        }
    }
    a:;
}

void NumberSort(int array[], int size)
{
    int max = array[0];
    int min = array[0];
    for(int i = 0; i < size; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
        else if(array[i] < min)
        {
            min = array[i];
        }
    }

    int * ptr;
    int d = max - min;
    ptr = (int *)calloc((d + 1), sizeof(int));

    for(int i = 0; i < size; i++)
    {
        ptr[array[i] - min]++;
    }

    static int j = 0;
    for(int i = 0; i < (d + 1); i++)
    {
        while(ptr[i]--)
        {
            array[j++] = i + min;
        }
    }
    free(ptr);
    ptr = NULL;
}
