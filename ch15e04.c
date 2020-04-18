#include <stdio.h>
#include <stdlib.h>
int search_bit(int value, int bit);
int main(void)
{
    int value, bit;
    printf("Input a value:");
    scanf("%d", &value);
    printf("Input a bit:");
    scanf("%d", &bit);
    printf("This bit is %d.\n", search_bit(value, bit));
    getchar();
    getchar();
    return 0;
}

int search_bit(int value, int bit)
{
    int n = 1 << bit;
    if((value & n) == n)
    {
        return 1;
    }
    return 0;
}