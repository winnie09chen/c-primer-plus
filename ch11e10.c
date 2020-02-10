#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define STRLEN 100
delete_space(char * st);
int main(void)
{
    char words[STRLEN];
    puts("Enter a sentence:");
    fgets(words, STRLEN, stdin);
    delete_space(words);
    puts(words);
    getchar();
    getchar();
    return 0;
}
delete_space(char * st)
{
    int u = 0, i = 0;
    for(; st[u] != '\0'; u++)
    {
        if(isgraph(st[u]))
        {
            st[i]= st[u];
            i++;
        }   
    }
    st[i] = '\0';
}