#include <stdio.h>

// a > b > c
void sort3(int * a, int * b, int * c);

// a > b
void sort2(int * a, int * b);

int main(void)
{
    int a = -23, b = 14, c = 78;
    sort3(&a, &b, &c);
    printf("%d, %d, %d\n", a, b, c);
    getchar();
    return 0;
}

void sort2(int *a, int *b)
{
    int temp;
    if (*a < *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

void sort3(int * a, int * b, int * c)
{
    // a > b
    sort2(a, b);
    // a > c
    sort2(a, c);
    // b > c
    sort2(b, c);
}