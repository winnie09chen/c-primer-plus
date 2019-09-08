#include <stdio.h>
void calc_dollars(float dollars);
int main(void)
{
    float dollars;
    int dollars_2;
    char levels;
    printf("Input dollars:\n");
    scanf("%f", &dollars);
    getchar();
    printf("Input your level:\n");
    printf("a) bachelordom : 17850 dollars is 15 percents, the rest is 28 percents.\n");
    printf("b) head of a household : 23900 dollars is 15 percents, the rest is 28 percents.\n");
    printf("c) married : 29750 dollars is 15 percents, the rest is 28 percents.\n");
    printf("d) divorced : 14875 dollars is 15 percents, the rest is 28 percents.\n");
    scanf("%c", &levels);
    switch (levels)
    {
    case 'a': dollars_2 = 17850; 
        break;
    case 'b': dollars_2 = 23900;
        break;
    case 'c': dollars_2 = 29750;
        break;
    default: dollars_2 = 14875;
        break;
    }
    float s;
    if(dollars <= dollars_2)
    {
        dollars = dollars * 0.85;
    }
    else
    {
        dollars = dollars_2*0.85 + (dollars - dollars_2)*0.72;
    }
    printf("Your dollars is %.2f\n", dollars);
    getchar();
    getchar();
    return 0;
}
