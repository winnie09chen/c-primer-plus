#include <stdio.h>
int main(void)
{
    float dollar_Daphne = 100, tmp, tmp_2, dollar_Deirdre = 100;
    printf("Daphne's money is %.2f\n", dollar_Daphne);
    printf("Deirdre's money is %.2f\n", dollar_Deirdre);
    while (dollar_Deirdre <= dollar_Daphne)
    {
        tmp = 100*0.05;
        dollar_Daphne += tmp;
        printf("Daphne's money is %.2f\n", dollar_Daphne);
        tmp_2 = dollar_Deirdre*0.05;
        dollar_Deirdre += tmp_2;
        printf("Deirdre's money is %.2f\n", dollar_Deirdre);
    }
    getchar();
    return 0;
} 