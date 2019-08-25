#include <stdio.h>
int main(void)
{
    int lower, upper, scanf_count, temp, temp_2;
    temp_2 = 0;
    printf("Enter lower and upper integer limits: ");
    scanf_count = scanf("%d %d", &lower, &upper);
    printf("The sums of the squares from %d to %d is ", lower*lower, upper*upper);
    for(;scanf_count == 1, lower <= upper;lower++)
    {
        temp = lower*lower;
        temp_2 += temp;
    }
    printf("%d\n", temp_2);
    getchar();
    getchar();
    return 0;
}
