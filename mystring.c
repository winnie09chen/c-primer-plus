#include <stdio.h>
#include <string.h>

char * my_strchr(char * str, char num)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == num)
        {
            return str+i;
        }
    }
    return NULL;
}

char * gang_strchar(char * str, char num)
{
    while (*str != num && *str != '\0')
    {
        str++;
    }
    return *str == '\0' ? NULL : str;
}

char * my_strcat(char * s1, char * s2)
{
    int i = 0;
    int j = 0;
    for(; s1[i] != '\0'; i++);
    for(; s2[j] != '\0'; j++)
    {
        s1[i + j] = s2[j];
    }
    s1[i + j] = '\0';
    return s1;
}

char * gang_strcat(char * s1, char * s2)
{
    char *s = s1;
    while(*s1++ != '\0');
    while(*s2 != '\0')
    {
        *s1++ = *s2++;
    }
    *s1 = '\0';
    return s;
}

char * my_strcpy(char * s1, char * s2)
{
    int i = 0;
    for(; s2[i] != '\0'; i++)
    {
        s1[i] = s2[i];
    }
    s1[i] = '\0';
    return s1;
}

int my_strcmp(char * s1, char * s2)
{
    int i = 0;
    for(; s1[i] != '\0'; i++)
    {
        if((s1[i] - s2[i]) > 0)
            return 1;
        else if((s1[i] - s2[i]) < 0)
            return -1;
        
    }
    if(s1[i] == s2[i])
    {
        return 0;
    }
    return -1;
}

int main(int argc, char* argv[])
{
    char str1[13] = "";
    char str2[20] = "a";
    char *s1 = str1;
    printf("strcmp: %d\n", my_strcmp(str2, s1));
    getchar();
}

// my_strchr
// my_strcat
// my_strcpy
// my_strcmp

