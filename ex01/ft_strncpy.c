#include <unistd.h>

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int i;

    i = 0;
    while (i < n && src[i] != '\0') // Copiar caracteres válidos
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n) // Rellenar el resto con '\0'
    {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}
