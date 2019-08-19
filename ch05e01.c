#include <stdio.h>
int main(void)
{
    int minutes, hours, left;
    const min = 60;
    printf("Input minutes:\n");
    scanf("%d", &minutes);
    while (minutes > 0)
    {
        hours = minutes / min;
        left = minutes % min;
        printf("%d minutes is %d hours, %d minutes.\n", minutes, hours, left);
        printf("Input next minutes:\n");
        scanf("%d", &minutes);
    }
    printf("Done!\n");
    getchar();
    getchar();
    return 0;
}