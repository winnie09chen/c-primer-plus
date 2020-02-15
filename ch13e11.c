#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 200

int main(int argc, char * argv[])
{
    FILE * ptr;
    char ar[LINE_LENGTH];
    if(argc != 3)
    {
        fprintf(stderr, "Usage: %s string filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((ptr = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Can't open the file, %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while(fgets(ar, LINE_LENGTH, ptr) != NULL)
    {
        if(strstr(ar, argv[1]) != NULL)
        {
            fputs(ar, stdout);
        }
    }
    fclose(ptr);
    return 0;
}