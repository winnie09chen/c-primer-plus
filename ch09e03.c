#include <stdio.h>
void chline(char ch, int i, int j);
int main(void)
{
    int i = 3, j = 5;
    char ch = '#';
    chline(ch, i, j);
    getchar();
    getchar();
    return 0;
}
void chline(char ch, int i, int j)
{
    int a = 1;
    int b = 1;
    for(; a < i; a++)
    {
        printf(".\n");
    }
    for(; b < j; b++)
    {
        printf(".");
    }
    printf("%c", ch);
}