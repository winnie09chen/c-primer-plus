#include <stdio.h>
#include <string.h>
int main(int argc, char * argv[])
{
    for(; argc > 1; argc--)
    {
        fputs(argv[argc - 1], stdout);
        fputs(" ", stdout);
    }
    getchar();
    getchar();
    return 0;
}