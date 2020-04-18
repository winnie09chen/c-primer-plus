#include <stdio.h>
#include <string.h>
int main(void)
{
    int array1[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int array2[5];
    memcpy(array2, array1, 5 * sizeof(int));
    printf("%d %d %d %d %d\n", array2[0], array2[1], array2[2], array2[3], array2[4]);
    int array3[5];
    memcpy(array3, array1 + 3, 5 * sizeof(int));
    printf("%d %d %d %d %d\n", array3[0], array3[1], array3[2], array3[3], array3[4]);
    getchar();
    getchar();
    return 0;
}