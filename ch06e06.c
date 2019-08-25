#include <stdio.h>

// TODO: wait sprintf
int main(void)
{
    int max, min;
    printf("Input a max number:\n");
    scanf("%d", &max);
    printf("Input a min number:\n");
    scanf("%d", &min);
    printf("integer square cube\n");
    for (; min <= max; min++)
    {
        printf("%d %d %d\n", min, min*min, min*min*min);
    }
    getchar();
    getchar();
    return 0;
}
