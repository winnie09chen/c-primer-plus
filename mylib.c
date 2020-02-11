#include "mylib.h"

#include <ctype.h>

#include <string.h>

int my_power(int n, int p)
{
    int m = 1;
    for(int i = 0; i < p; i++)
    {
        m *= n;
    }
    return m;
}

int my_atoi(char * st)
{
    int number = strlen(st);
    int d = 0;
    int total = 0;
    for(int i = 0; i < number; i++)
    {
        if(!isdigit(st[i]))
        {
            return 0;
        }
        d = st[i] - '0';
        total += d * my_power(10, number - i - 1);
    }
    return total;
}

void delete_letter(char * st, char letter)
{
    int u = 0, i = 0;
    for(; st[u] != '\0'; u++)
    {
        if(letter != st[u])
        {
            st[i]= st[u];
            i++;
        }   
    }
    st[i] = '\0';
}