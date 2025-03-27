#include <unistd.h>
#include <ctype.h>

char *ft_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (islower(str[i]))
            str[i] = toupper(str[i]);
        i++;
    }
    return (str);
}
