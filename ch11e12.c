#include <stdio.h>
#include <ctype.h>

#define STRLEN 100

int main(void)
{
    char words[STRLEN];
    int i = 0;
    int lower = 0, upper = 0, word = 0, punc = 0, num = 0, isword = 0;
    
    puts("Enter a sentence:");
    fgets(words, STRLEN, stdin);

    while(words[i] != '\0')
    {
        if(islower(words[i]))
        {
            ++lower;
        }
        if(isupper(words[i]))
        {
            ++upper;
        }
        if(ispunct(words[i]))
        {
            ++punc;
        }
        if(isdigit(words[i]))
        {
            ++num;
        }
        if(!isspace(words[i]) && !ispunct(words[i]) && !isword)
        {
            isword = 1;
            ++word;
        }
        if(isspace(words[i]) || ispunct(words[i]) && isword)
        {
            isword = 0;
        }
        ++i;
    }
    printf("lower = %d, upper = %d, punct = %d, number = %d, word = %d\n", lower, upper, punc, num, word);
    getchar();
    getchar();
    return 0;
}