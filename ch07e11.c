#include <stdio.h>
int main(void)
{
    int scanf_count;
    float vegetable_yang_pound = 2.05, vegetable_lettuce_pound = 1.15, vegetable_corrot_pound = 1.09;
    float yang_pound = 0, lettuce_pound = 0, corrot_pound = 0, pound = 0;
    float money = 0, money_cargo_fee = 0, money_discount = 0;
    char a = 'a';
    while (a != 'q')
    {
        printf("a) yang\n");
        printf("b) lettuce\n");
        printf("c) corrot\n");
        printf("q) check out\n");
        printf("Input your level:\n");
        scanf("%c", &a);
        getchar();
        switch (a)
        {
        case 'a':
            printf("Input your yang pound:\n");
            scanf("%f", &yang_pound);

            getchar();
            break;
        case 'b':
            printf("Input your lettuce pound:\n");
            scanf("%f", &lettuce_pound);
            getchar();
            break;
        case 'c':
            printf("Input your corrot pound:\n");
            scanf("%f", &corrot_pound);
            getchar();
            break;
        default:
            break;
        }
    }
    pound = yang_pound + lettuce_pound + corrot_pound;
    money = yang_pound * vegetable_yang_pound + lettuce_pound * vegetable_lettuce_pound + corrot_pound * vegetable_corrot_pound;
    if (money >= 100)
    {
        money_discount = money * 0.05;
    }
    if (pound <= 5)
    {
        money_cargo_fee = 6.5;
    }
    else if (pound > 5 && pound <= 20)
    {
        money_cargo_fee = 14;
    }
    else
    {
        money_cargo_fee = (pound - 20) * 0.5 + 14;
    }
    printf("money: %.2f\n", money);
    printf("discount: %.2f\n", -money_discount);
    printf("cargo: %.2f\n", money_cargo_fee);
    printf("pounds: %.2f\n", pound);
    printf("Your vegetable is $%.2f\n", money - money_discount + money_cargo_fee);
    getchar();
    getchar();
    return 0;
}