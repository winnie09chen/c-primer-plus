#include "mylib.h"
#include <stdio.h>

#define STRLEN 100

int main(void)
{
    char words[STRLEN];
    int num;
    puts("Enter a sentence(contain numbers):");
    gets_s(words, STRLEN);
    num = my_atoi(words);
    printf("%d\n", num);
    getchar();
    getchar();
    return 0;
}
