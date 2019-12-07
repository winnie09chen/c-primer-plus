#include <stdio.h>
void copy_array(float array[][4]);
void copy_array1(float array[][4]);
int main(void)
{
    float array[3][4] = {{4.3, 55.7, 23.7, 6.1}, {45.3, 56.67, 45.77, 2.5}, {3.4, 55.22, 45.67, 22.45}};
    copy_array(array);
    copy_array1(array);
    getchar();
    getchar();
    return 0; 
}
void copy_array(float array[][4])
{    
    float empty[3][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    for(int a = 0; a < 3; a++)
    {
        for(int b = 0; b < 4; b++)
        {
            empty[a][b] = array[a][b];
            printf("%.2f ", empty[a][b]);
        }
    }
    printf("\n");
}

void copy_array1(float array[][4])
{
    float empty[3][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    for(int a = 0, r=0, c=0; a < 12; a++)
    {
        r = a / 4;
        c = a % 4;
        empty[r][c] = array[r][c];
        printf("%.2f ", empty[r][c]);
    }
    printf("\n");
}
