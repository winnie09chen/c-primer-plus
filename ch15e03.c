#include <stdio.h>
int open_bit(int number);
int main(void)
{
    int number;
    int open;
    printf("Input one number: ");
    scanf("%d", &number);
    open = open_bit(number);
    printf("%d bits are open.\n", open);
    getchar();
    getchar();
    return 0;
}

int open_bit(int number)
{
    int count = 0;
    for(int i = 0; i < 8; i++)
    {
        if(number & 1 == 1)
        {
            count++;
        }
        number >>= 1;
    }
    
    return count;
}