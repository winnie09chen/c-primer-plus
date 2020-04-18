#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
int two_to_ten(char number[]);
int main(void)
{
    char number[SIZE] = "00001001";
    int ten_base_number = two_to_ten(number);
    printf("%d", ten_base_number);
    getchar();
    getchar();
    return 0;
}


