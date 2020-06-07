#include "mylib.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>


int my_power(int n, int p)
{
    int m = 1;
    for(int i = 0; i < p; i++)
    {
        m *= n;
    }
    return m;
}

int my_atoi(char * st)
{
    int number = strlen(st);
    int d = 0;
    int total = 0;
    for(int i = 0; i < number; i++)
    {
        if(!isdigit(st[i]))
        {
            return 0;
        }
        d = st[i] - '0';
        total += d * my_power(10, number - i - 1);
    }
    return total;
}

void delete_letter(char * st, char letter)
{
    int u = 0, i = 0;
    for(; st[u] != '\0'; u++)
    {
        if(letter != st[u])
        {
            st[i]= st[u];
            i++;
        }   
    }
    st[i] = '\0';
}

void bubble_sort(int *array, int size)
{
    int tmp;
    for (int i = size; i > 0; i--)
    {
        for (int j = 1; j < i; j++)
        {
            if (array[j-1] > array[j])
            {
                tmp = array[j-1];
                array[j-1] = array[j];
                array[j] = tmp;
            }
        }
    }
}

int two_to_ten(char number[])
{
    int two_base_number[8];
    int total = 0, turn_number = 1;
    for(int i = 0; i < 8; i++)
    {
        two_base_number[8 - i - 1] = (int)number[i] - 48;
    }

    for(int i = 0; i < 8; i++)
    {
        total += two_base_number[i] * turn_number;
        turn_number *= 2;
    }
    return total;
}

int find_a_peak(int first, int last, int array[])
{
    int i = (last + first) / 2;
    if(array[i - 1] > array[i])
    {
        find_a_peak(first, i - 1, array);
    }
    else if(array[i + 1] > array[i])
    {
        find_a_peak(i + 1, last, array);
    }
    else
    {
        return array[i];
    }
    return -1;
}

static void _merge_sort_merge(int array[], int p, int r, int q)
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

static void _merge_sort(int array[], int p, int r, int q)
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

static inline int _select_sort_find_min(int array[], int length, int start)
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

