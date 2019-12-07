#include <stdio.h>
void copy_array(int * a, int * b);
int main(void)
{
    int array[7] = {6, 44, 6, 3, 7, 34, 123};
    copy_array(&array[2], &array[4]);
    getchar();
    getchar();
    return 0;
}
void copy_array(int * a, int * b)
{
    int c = 0;
    int empty[3] = {0, 0, 0};
    while(a <= b)
    {
        empty[c] = *a;
        a++;
        printf("%d ", empty[c]);
        c++;
    }
}