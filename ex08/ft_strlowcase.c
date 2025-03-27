#include <unistd.h>
#include <ctype.h>

char *ft_strlowcase(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (isupper(str[i]))
            tolower(str[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}