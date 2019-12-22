#include <stdio.h>

void print_array(int ar[][5]);

void array_avg(int ar[][5]);

void array_biggest(int ar[][5]);

void print_array_pt(int *pt, int rows, int cols);

void array_avg_pt(int *pt, int rows, int cols);

void array_biggest_pt(int *pt, int rows, int cols);

int main(void)
{
    int ar[3][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    for(int num = 0; num < 3; num++)
    {
        
        printf("print 5 number: \n");
        scanf("%d %d %d %d %d", ar[num], ar[num]+1, ar[num]+2, ar[num]+3, ar[num]+4);
    }
    array_avg_pt(ar, 3 ,5);
    array_biggest_pt(ar, 3, 5);
    getchar();
    getchar();
}
void print_array(int ar[][5]) // debug
{
    for(int a = 0; a < 3; a++)
    {
        for(int b = 0; b < 5; b++)
        {
            printf("%d ", ar[a][b]);
        }
        printf("\n");
    }
}

void array_avg(int ar[][5])
{
    int total = 0;
    int all_total = 0;
    for(int a = 0; a < 3; a++)
    {
        total = 0;
        for(int b = 0; b < 5; b++)
        {
            total += ar[a][b];
            all_total += ar[a][b];
        }
        printf("avg of row %d items: %d\n", a, total / 5);
    }
    printf("avg of all items: %d\n", all_total / (3 * 5));
}

void array_biggest(int ar[][5])
{
    int biggest = ar[0][0]; 
    for(int a = 0; a < 3; a++)
    {
        for(int b = 0; b < 5; b++)
        {
            if(ar[a][b] > biggest)
            {
                biggest = ar[a][b];
            }
        }
    }
    printf("The biggest item in the array is ");
    printf("%d", biggest);
}

void print_array_pt(int *pt, int rows, int cols)
{
    for (; rows > 0; rows--)
    {
        for (int c = cols; c > 0; c--)
        {
            printf("%d ", *pt++);
        }
        printf("\n");
    }
}

void array_avg_pt(int *pt, int rows, int cols)
{
    int total = 0;
    int all_total = 0;
    for(int r = 0; r < rows; r++)
    {
        total = 0;
        for(int c = cols; c > 0; c--)
        {
            total += *pt;
            all_total += *pt;
            pt++;
        }
        printf("avg of row %d items: %d\n", r, total / cols);
    }
    printf("avg of all items: %d\n", all_total / (rows * cols));
}

void array_biggest_pt(int *pt, int rows, int cols)
{
    int *end_pt = pt + rows * cols;
    int biggest = *pt;
    while (pt < end_pt)
    {
        if (biggest < *pt)
        {
            biggest = *pt;
        }
        pt++;
    }
     printf("The biggest item in the array is %d\n", biggest);
}