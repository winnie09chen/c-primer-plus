#include <stdio.h>
int is_primer(int number);
int main(void)
{
    int number;
    printf("Input a number:\n");
    scanf("%d", &number);
    while(number > 1)
    {
        for(int i = 1; i <= number; i++)
        {
            if(is_primer(i) == 1)
            {
                printf("%d\n", i);
            }
        }
        printf("Input a number:\n");
        scanf("%d", &number);
    }
    getchar();
    getchar();
    return 0;
}
int is_primer(int number)
{
    for(int j = 2; j <= number/2; ++j)
    {
        if(number % j == 0)
        {
            return 0;
        }
    }
    return 1;
}
