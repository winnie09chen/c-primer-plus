#include <stdio.h>

int main(void)
{
    float pints, cups, ounces, tablespoons, teaspoons;
    printf("input cups:\n");
    scanf("%f", &cups);
    pints = cups/2;
    ounces = cups*8;
    tablespoons = ounces*2;
    teaspoons = tablespoons/3;
    printf("%f pints, %f cups, %f ounces, %f tablespoons, %f teaspoons\n", pints, cups, ounces, tablespoons, teaspoons);

    return 0;

}