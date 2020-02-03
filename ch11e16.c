#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define STRING 100
int main(int argc, char * argv[])
{
    char word[STRING];
    puts("Enter a sentence: ");
    fgets(word, STRING, stdin);
    if(strcmp(argv[1], "-p") == 0)
    {
        puts(word);
    }
    else if(strcmp(argv[1], "-u") == 0)
    {
        for(int i = 0; i <= strlen(word); i++)
        {
            word[i] = toupper(word[i]);
            putchar(word[i]);
        }
    }
    else if(strcmp(argv[1], "-l") == 0)
    {
        for(int t = 0; t <= strlen(word); t++)
        {
            word[t] = tolower(word[t]);
            putchar(word[t]);
        }
    }
    getchar();
    getchar();
    return 0; 
}