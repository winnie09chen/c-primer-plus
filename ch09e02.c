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
    int b = 0;
    int c = 0;
    for(; b < i; b++)
    {
        for(c = 0; c < j; c++)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
}
