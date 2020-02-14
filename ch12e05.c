#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int number[20];
    srand((unsigned int) time(0));
    for(int i = 0; i < 20; i++)
    {
        number[i] = rand() % 10 + 1;
    }
    bubble_sort(number, 20);
    for(int i = 0; i < 20; i++)
    {
        printf("%d ", number[i]);
    }
    getchar();
    getchar();
    return 0;
}