#include <stdio.h>
void number(double num);
int main(void)
{
    int scanf_count;
    double num;
    printf("Input a number:\n");
    scanf_count = scanf("%lf", &num);
    while (scanf_count == 1)
    {
        number(num);
        printf("Input next value:\n");
        scanf_count = scanf("%lf", &num);
    }
    getchar();
    getchar();
    return 0;
}
void number(double num)
{
    const double num_a = num*num*num;
    printf("%.2lf*%.2lf*%.2lf = %.2lf\n", num, num, num, num_a);
}