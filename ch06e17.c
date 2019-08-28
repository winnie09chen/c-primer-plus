#include <stdio.h>
int main(void)
{
    int dollar = 1000000, tmp, leave = 100000, year = 0;
    printf("In year %d, Chuckie Lucky's money is %d\n", year, dollar);
    while(dollar >= 0)
    {
        tmp = dollar/8;
        dollar = dollar + tmp;
        dollar -= leave;
        ++year;
        printf("In year %d, Chuckie Lucky's money is %d\n", year, dollar);
    }
    getchar();
    return 0;
}