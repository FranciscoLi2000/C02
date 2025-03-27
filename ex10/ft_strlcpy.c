#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
    unsigned int i;
	unsigned int j;
	
	i = 0;
	j = 0;
    if (!src)
        return (0);
    while (src[i] !='\0')
        i++;
    if (size == 0)
        return (i);
    while (j < size - 1 && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
    dest[size - 1] = '\0';
    return (i);
}
