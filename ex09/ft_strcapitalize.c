#include "exam_rank02.h"

char *ft_strcapitalize(char *str)
{
    int i;
    int in_word;

    in_word = 0;
    i = 0;
    while (str[i] != '\0')
    {
        if (in_word == 0 && (ft_islower(str[i]) || ft_isdigit(str[i])))
        {
            ft_toupper(str[i]);
            in_word = 1;
        }
        if (!ft_isalpha(str[i]))
            in_word = 0;
        i++;
    }
    str[i] = '\0';
    return (str);
}