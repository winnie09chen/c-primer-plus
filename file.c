#include <stdio.h>
#include <stdlib.h>
#define SIZE 200
int main(int argc, char * argv[])
{
    FILE * ptr = NULL;
    char ch[SIZE], file[20];
    char choose, quit;
    int row = 0, paper = 0, input_paper;
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

    b: row = 0;
    paper = 0;
    while(fgets(ch, SIZE, ptr) != NULL)
    {
        if(row % 10 == 0)
        {
            ++paper;
        }
        ++row;
    }

    printf("Do you want to quit: ");
    scanf("%c", &quit);
    getchar();

    while(quit == 'n')
    {
        printf("Which mode do you want open the file\na) choose the page\nb) another file\n");
        scanf("%c", &choose);
        getchar();

        if(choose == 'a')
        {
            printf("Which paper do you want to open(1 - %d): ", paper);
            scanf("%d", &input_paper);
            getchar();

            rewind(ptr);
            row = 0;
            input_paper -= 1;

            for(int i = 0; i < input_paper * 10; i++)
            {
                if(fgets(ch, SIZE, ptr) == NULL)
                {
                    break;
                }
                row++;
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
        }

        if(choose == 'b')
        {
            printf("Which file do you want to open: ");
            gets_s(file, 20);
            if((ptr = fopen(file, "r")) == NULL)
            {
                fprintf(stderr, "Can't open the file.\n");
                exit(EXIT_FAILURE);
            }
            goto b;
        }
        a: printf("Do you want to quit: ");
        scanf("%c", &quit);
        getchar();
    }
    getchar();
    getchar();
    return 0;
}