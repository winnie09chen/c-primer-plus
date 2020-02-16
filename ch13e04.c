#include <stdlib.h>
#include <stdio.h>
int main(int argc, char * argv[])
{
    FILE * ptr = NULL;
    char array[200];
    if(argc == 1)
    {
        fprintf(stderr, "No file to print.\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 1; i <= argc; i++)
    {
        if((ptr = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "Can't open the file, %s.\n", argv[i]);
            break;
        }
        while(fgets(array, 200, ptr) != NULL)
        {
            fputs(array, stdout);
        }
        if (ptr != NULL)
        {
            fclose(ptr);
        }
    }

    return 0;
}