#include <stdio.h>
void array_double(int ar[][5]);
int main(void)
{
    int ar[3][5] = {{2, 4, 6, 8, 0}, {1, 3, 5, 7, 9}, {2, 6, 324, 7423, 66}};
    array_double(ar);
    getchar();
    getchar();
    return 0;
}
void array_double(int ar[][5])
{
    for(int a = 0; a <= 2; a++)
    {
        for(int b = 0; b <= 4; b++)
        {
            printf("%d ", ar[a][b] * 2);
        }
    }
}