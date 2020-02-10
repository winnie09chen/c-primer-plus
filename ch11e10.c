#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mylib.h"
#define STRLEN 100
int main(void)
{
    char words[STRLEN];
    char letter;
    puts("Enter a sentence:");
    fgets(words, STRLEN, stdin);
    puts("Enter a letter to delete:");
    scanf("%c", &letter);
    delete_letter(words, letter);
    puts(words);
    getchar();
    getchar();
    return 0;
}
