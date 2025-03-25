#include "exam_rank02.h"

char *ft_strupcase(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (ft_islower(str[i]))
            ft_toupper(str[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}