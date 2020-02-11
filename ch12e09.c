#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 100
char *next_word(char *st);
int main(void)
{
    char *word_ptr;
    char words[STRLEN];
    char ** words_ptr;
    int word_count;
    puts("How many words do you want to enter:");
    scanf("%d", &word_count);
    getchar();
    words_ptr = (char **)malloc(word_count * sizeof(char *));
    puts("Enter a sentence:");
    fgets(words, STRLEN, stdin);
    word_ptr = words;
    for(int i = 0; i < word_count; i++)
    {
        word_ptr = next_word(word_ptr);
        words_ptr[i] = (char *)malloc((strlen(word_ptr) + 1) * sizeof(char));
        strcpy(words_ptr[i], word_ptr);
        word_ptr += strlen(word_ptr) + 1;
    }
    for(int u = 0; u < word_count; u++)
    {
        puts(words_ptr[u]);
    }
    getchar();
    getchar();
    return 0;
}

char * next_word(char *st)
{
    char * p;
    if (*st == '\0')
    {
        return NULL;
    }
    while (isspace(*st) && *st != '\0')
    {
        st++;
    }
    p = st; // first char
    while (!isspace(*st) && *st != '\0')
    {
        st++;
    }
    *st = '\0';
    return p;
}