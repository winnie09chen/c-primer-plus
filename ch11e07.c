#include <stdio.h>
#include <string.h>
#define STRLEN 100
void mystrncpy(char * st1, char * st2, int num);
int main(void)
{
    char words[STRLEN];
    char temp[STRLEN];
    int num;
    puts("Enter a sentence:");
    fgets(words, STRLEN, stdin);
    num = strlen(words);
    mystrncpy(words, temp, num);
    fputs(temp, stdout);
    getchar();
    getchar();
    return 0;
}
void mystrncpy(char * st1, char * st2, int num)
{
    for(int i = 0; i < num; i++)
    {
        st2[i] = st1[i];
    }
    st2[num] = '\0';
}