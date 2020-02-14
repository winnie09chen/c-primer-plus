#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define STRLEN 1000
int main(void)
{
    int number[STRLEN];
    int number_time[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    srand((unsigned int) time(0));
    for(int i = 0; i < 1000; i++)
    {
        number[i] = rand() % 10 + 1;
    }
    for(int i = 0; i < 1000; i++)
    {
        ++number_time[number[i] - 1];
    }
    for(int i = 1; i <= 10; i++)
    {
        printf("%2d: %d\n", i, number_time[i - 1]);
    }
    getchar();
    getchar();
    return 0;
}