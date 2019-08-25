#include <stdio.h>
#include <string.h>

#define WORD_LENGTH 32

void input_word(char word[]);

void reverse_string(char word[]);

int main(void)
{
    int scanf_count;
    char word[WORD_LENGTH];
    input_word(word);
    while(strlen(word) != 1 || word[0] != 'q')
    {
        reverse_string(word);
        printf("%s\n", word);
        input_word(word);
    }
    getchar();
    return 0;
}

void input_word(char word[])
{
    printf("Input a word:\n");
    scanf("%s", word);
}

void reverse_string(char word[])
{
    int n = strlen(word);
    char tmp;
    for(int i=0, end=n/2; i<end; i++)
    {
        tmp = word[i];
        word[i] = word[n-1-i];
        word[n-1-i] = tmp;
    }
}