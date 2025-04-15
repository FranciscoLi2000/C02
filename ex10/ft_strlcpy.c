#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	
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

#include <stdio.h>

int	main(void)
{
	unsigned int	size;
	const char	src[50];
	char	dst[50];

	size = 50;
	printf("Enter the source string: ");
	scanf("%s", src);
	printf("return %u\n", ft_strlcpy(dst, src, size));
	printf("dest: %s\n", dst);
	return (0);
}
