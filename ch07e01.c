#include <stdio.h>
int main(void)
{
    char ch;
    int space = 0, new_line = 0, alpha = 0;
    printf("Input a sentence:\n");
    while((ch = getchar()) != '#')
    {
        switch(ch)
        {
            case ' ': ++space;
            break;
            case '\n': ++new_line;
            break;
            default: ++alpha;
        }
    }
    printf("space: %d\n", space);
    printf("new line: %d\n", new_line);
    printf("other word: %d\n", alpha);
    getchar();
    getchar();
    return 0;
}