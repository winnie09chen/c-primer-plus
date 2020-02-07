#include <stdio.h>
#include <string.h>
#define STRLEN 100
#define FIND 1
int string_find(char * st, char find);
int main(void)
{
    char words[STRLEN];
    char find;
    int location;
    puts("Enter a sentence:");
    fgets(words, STRLEN, stdin);
    puts("Which letter do you want to find:");
    scanf("%c", &find);
    location = string_find(words, find);
    printf("This letter is at number %d of the array.\n", location);
    getchar();
    getchar();
    return 0;
}
int string_find(char * st, char find)
{
    int num = 0;
    while(st[num] != '\0')
    {
        if(st[num] == find)
            return num + 1;
        else if(st[num] != find)
            ++num;
    }
    return 0;
}