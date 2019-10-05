#include <stdio.h>
int main(void)
{
    char ch;
    int replace = 0;
    printf("Input a setence:\n");
    while((ch = getchar()) != '#')
    {
        switch(ch)
        {
            case '.': ++replace;
            break;
            case '!': ++replace;
            break;
        }
    }
    printf("replace: %d\n", replace);
    getchar();
    getchar();
    return 0;
}





















































































