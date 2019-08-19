#include <stdio.h>

void Temperature(double t);
int main(void)
{
    double tem;
    int scanf_count;
    printf("Input F:\n");
    scanf_count = scanf("%lf", &tem);
    while (scanf_count == 1)
    {
        Temperature(tem);
        printf("Input F:\n");
        scanf_count = scanf("%lf", &tem);
    }
    getchar();
    getchar();
    return 0;
}
void Temperature(double t)
{
    const double C = 5.0/9.0*(t - 32.0);
    const double K = C + 273.16;
    printf("F = %.2lf,  C = %.2lf,  K = %.2lf\n", t, C, K);
}