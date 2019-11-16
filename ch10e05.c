#include <stdio.h>
#define SIZE 8
void delta_of_max_and_min(int * begin, int * end, int * max, int * min);
int main(void)
{
    int max = 0, min = 0;
    int array[8] = {2, 4, 6, 234, 345, 23, 35, 2345};
    delta_of_max_and_min(array, array + SIZE, &max, &min);
    printf("%td", max - min);
    getchar();
    getchar();
    return 0;
}
void delta_of_max_and_min(int * begin, int * end, int * max, int * min)
{
    *max = *begin;
    *min = *begin;
    while(begin < end)
    {
        if(*begin > *max)
        {
            *max = *begin;
        }
        if(*begin < *min)
        {
            *min = *begin;
        }
        begin++;
    }
}