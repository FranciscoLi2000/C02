#include <unistd.h>
/*
char *ft_strcpy(char *dest, char *src)
{
    unsigned int  i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}*/
char    *ft_strcpy(char *dest, char *src)
{
    char    *dst;

    *dst = dest;
    while ((*dst++ = *src++));
    return (dest);
}
