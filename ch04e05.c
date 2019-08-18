#include <stdio.h>
int main(void)
{
    float speed, file_size;
    printf("Input download speed:\n");
    scanf("%f", &speed);
    printf("Input file size:\n");
    scanf("%f", &file_size);
    printf("At %.2f megabits per second, a file of %.2f megabytes\n", speed, file_size);
    printf("downloads in %.2f seconds.\n", file_size/(speed/8));
    getchar();
    getchar();
    return 0;
}
