#include <stdio.h>
void reverse_number(int number);
int main(void)
{
    int number[8];
    for(int question_count = 0;question_count < 8;question_count++)
    {
        printf("Input a number:\n");
        scanf("%d", number);
    }
    while(number[0] != 'q')
    {
        reverse_number(number);
        printf("%d\n", number);
    }
    getchar();
    getchar();
    return 0;
}
void reverse_number(int number)
{
    int n = strlen(number);
    int tmp;
    for(int i=0, end=n/2; i<end; i++)
    {
        tmp = number[i];
        number[i] = number[n-1-i];
        number[n-1-i] = tmp;
    }
}
