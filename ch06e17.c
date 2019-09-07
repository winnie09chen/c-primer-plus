#include <stdio.h>
int main(void)
{
    float dollar = 1000000, tmp, leave = 100000; 
    int year = 0;
    printf("In year %d, Chuckie Lucky's money is %.2f\n", year, dollar);
    while(dollar >= 0)
    {
        tmp = dollar*0.08;
        dollar = dollar + tmp;
        dollar -= leave;
        ++year;
        printf("In year %d, Chuckie Lucky's money is %.2f\n", year, dollar);
    }
    getchar();
    return 0;
}