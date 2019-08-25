#include <stdio.h>

int main(int argc, char const *argv[])
{
    char alpha_list[26];

    for (char i = 'a'; i <= 'z'; i++)
    {
        alpha_list[i-'a'] = i;
    }

    for (int i = 0; i < 26; i++) 
    {
        printf("%c\n", alpha_list[i]);
    }
    
    getchar();

    return 0;
}
