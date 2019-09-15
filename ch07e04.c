#include <stdio.h>
int main(void)
{
    char ch;
    int replace = 0;
    printf("Input a sentence:\n");
    while((ch = getchar()) != '#')
    {
        if(ch == '.')
        {
            ++replace;
        }
        else if(ch == '!')
        {
            ++replace;
        }
    }
    printf("replace: %d\n", replace);
    getchar();
    getchar();
    return 0;
}