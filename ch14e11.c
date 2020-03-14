    #include <stdio.h>

    #define ARRAY_LENGTH 4

    void transform(int *source, int *target, int length, int (*fp)(int));
    int add_one(int);
    int minus_one(int);
    int print_int(int);

    int main(void)
    {
        int source[] = {0, 1, 2, 3};
        int target[] = {0, 0, 0, 0};
        int choose;
        int (* fp) (int);

        printf("What mode do you want to print array (0 / 1): ");
        scanf("%d", &choose);

        if(choose == 0)
            fp = add_one;
        else
            fp = minus_one;

        transform(source, target, ARRAY_LENGTH, fp);
        transform(source, NULL, ARRAY_LENGTH, print_int);
        printf("\n");
        transform(target, NULL, ARRAY_LENGTH, print_int);
        printf("\n");
        
        getchar();
        getchar();
        return 0;
    }

    void transform(int source[], int target[], int length, int (*fp)(int))
    {
        int t = 0;
        for(int i = 0; i < length; i++)
        {
            t = fp(source[i]);
            if (target != NULL)
            {
                target[i] = t;
            }
        }
    }

    int add_one(int number)
    {
        return number + 1;
    }

    int minus_one(int number)
    {
        return number - 1;
    }

    int print_int(int i)
    {
        printf("%d ", i);
        return i;
    }
