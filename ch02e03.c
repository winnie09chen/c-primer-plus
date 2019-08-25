#include <stdio.h>

int main(void)
{
    int age, day;
    printf("How old are you\?\n");
    scanf("%d", &age);
    day = age*365;
    printf("%d, %d\n",age, day);
    return 0;
}