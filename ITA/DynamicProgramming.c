#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "DynamicProgramming.h"

#define MAX(A, B) ((A) > (B) ? (A) : (B))

static inline void _init_array(int * ptr, int n)
{
    for(int i = 0; i < n; i++)
        ptr[i] = 0;
}

int BottomUpCutRod(int p[], int n)
{
    int * r;
    r = (int *)malloc(n * sizeof(int));
    _init_array(r, n);
    for(int i = 1; i <= n; i++)
    {
        int q = INT_MIN;
        for(int j = 1; j <= i; j++)
        {
            q = MAX(q, p[j] + r[i - j]);
        }
        r[i] = q;
    }
    return r[n];
}