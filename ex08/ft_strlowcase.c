#include "exam_rank02.h"

char *ft_strlowcase(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (ft_isupper(str[i]))
            ft_tolower(str[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}