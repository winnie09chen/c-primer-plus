#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
    int total = 1;
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    for(; num2 > 0; num2--)
    {
        total *= num1;
    }
    printf("%d", total);
    getchar();
    getchar();
    return 0;
}