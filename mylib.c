#include "mylib.h"

#include <ctype.h>

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