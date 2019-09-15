#include <stdio.h>
int main(void)
{
    int number;
    int odd = 0, even = 0, odd_sum = 0, even_sum = 0;
    float odd_avg, even_avg;
    printf("Input numbers:\n");
    
    while(1)
    {
        scanf("%d", &number);
        if(number == 0)
        {
            break;
        }
        if(number % 2 == 0)
        {
            ++even;
            even_sum += number;
        }
        else
        {
            ++odd;
            odd_sum += number;
        }
    }
    odd_avg = odd_sum / odd;
    even_avg = even_sum / even;
    printf("even: %d\n", even);
    printf("odd: %d\n", odd);
    printf("even_avg: %.2f\n", even_avg);
    printf("odd_avg: %.2f\n", odd_avg);
    getchar();
    getchar();
    return 0;
}