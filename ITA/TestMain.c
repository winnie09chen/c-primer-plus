#include <stdio.h>
#include "DynamicProgramming.h"

void print_array(int array[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
}

int main(void)
{
    int p[5] = {0, 3, 7, 3, 3};
    int n = 5;
    int q;
    q = BottomUpCutRod(p, n);
    printf("%d", q);
    getchar();
    return 0;
}