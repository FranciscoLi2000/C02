#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

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

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[60];
	char	s2[60];
	int		n;

	printf("Enter a string and an integer: ");
	scanf("%s %i", s1, &n);
	printf("Original: %s\n", strncpy(s2, s1, n));
	printf("Original: %s\n", ft_strncpy(s2, s1, n));
	return (0);
}
