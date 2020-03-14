#include <stdio.h>
#include <stdlib.h>
#define SIZE 200
int main(int argc, char * argv[])
{
    FILE * ptr = NULL;
    char ch[SIZE];
    int row = 0, paper = 0, input_paper, read_paper = 0;

    if(argc < 2)
    {
        fprintf(stderr, "No file to open.\n");
        exit(EXIT_FAILURE);
    }

    if((ptr = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Can't open the file.\n");
        exit(EXIT_FAILURE);
    }

    while(fgets(ch, SIZE, ptr) != NULL)
    {
        if(row % 10 == 0)
        {
            ++paper;
        }
        ++row;
    }

    printf("Which paper do you want to open(1 - %d): ", paper);
    scanf("%d", &input_paper);

    rewind(ptr);
    row = 0;
    input_paper -= 1;

    while(read_paper != input_paper && fgets(ch, SIZE, ptr) != NULL)
    {
        if(row % 10 == 0)
        {
            ++read_paper; 
        }
        ++row;
    }

    row = 0;

    while(fgets(ch, SIZE, ptr) != NULL)
    {
        if(row == 10)
        {
            goto a;
        }
        fputs(ch, stdout);
        ++row;
    }

    a: getchar();
    getchar();
    return 0;
}