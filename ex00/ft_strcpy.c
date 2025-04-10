#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
char	*ft_strcpy(char *dest, char *src)
{
	char	*dst;

	*dst = dest;
	while ((*dst++ = *src++));
	return (dest);
}*/

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[50];
	char	s2[50];

	printf("Enter a string: ");
	scanf("%s", s1);
	printf("Original: %s\n", strcpy(s2, s1));
	printf("mine: %s\n", ft_strcpy(s2, s1));
	return (0);
}
