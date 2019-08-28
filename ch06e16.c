#include <stdio.h>
int main(void)
{
    int dollar_Daphne = 100, tmp, tmp_2, dollar_Deirdre = 100;
    printf("Daphne's money is %d\n", dollar_Daphne);
    printf("Deirdre's money is %d\n", dollar_Deirdre);
    while (dollar_Deirdre <= dollar_Daphne)
    {
        tmp = 100/5;
        dollar_Daphne += tmp;
        printf("Daphne's money is %d\n", dollar_Daphne);
        tmp_2 = dollar_Deirdre/5;
        dollar_Deirdre += tmp_2;
        printf("Deirdre's money is %d\n", dollar_Deirdre);
    }
    getchar();
    return 0;
} 