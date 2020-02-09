#include <stdio.h>
#include <string.h>
#define STRLEN 100
void word_back(char * word, int num);
int main(void)
{
    char words[STRLEN];
    int num;
    puts("Enter a sentence:");
    fgets(words, STRLEN, stdin);
    num = strlen(words);
    word_back(words, num);
    puts(words);
    getchar();
    getchar();
    return 0;
}
void word_back(char * word, int num)
{
    char temp;
    for(int i = 0; i < num / 2; i++)
    {
       temp = word[i];
       word[i] = word[num - i - 1];
       word[num - i - 1] = temp;
    }
}