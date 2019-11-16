#include <stdio.h>
# define SIZE 5
void reverse(float * begin, float * end);
int main(void)
{
    float array[5] = {1.1, 1.2, 1.3, 1.4, 1.5};
    reverse(array, array + SIZE);
    getchar();
    getchar();
    return 0;
}
void reverse(float * begin, float * end)
{
    while(end > begin)
    {
        end--;
        printf("%.1f, ", *end);
    }
}