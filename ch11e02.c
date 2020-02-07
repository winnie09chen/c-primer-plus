#include <stdio.h>
#include <string.h>
#define STRLEN 100
void s_gets(char * st, int num);
int main(void)
{
    char words[STRLEN];
    puts("Enter a sentence:");
    fgets(words, STRLEN, stdin);
    s_gets(words, STRLEN);
    puts(words);
    getchar();
    getchar();
    return 0;
}
void s_gets(char * st, int num)
{
    for(int i = 0; i < num; i++)
    {
        if(st[i] == '\n')
            st[i] = '\0';
        else if(st[i] == '\t')
            st[i] = '\0';
        else if(st[i] == ' ')
            st[i] = '\0';
    }
}