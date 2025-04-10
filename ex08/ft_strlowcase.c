#include <unistd.h>
#include <ctype.h>

char	*ft_strlowcase(char *str)
{
	int	i;

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

#include <stdio.h>

int	main(void)
{
	char	str[50];

	printf("Enter a string: ");
	scanf("%s", str);
	printf("%s\n", ft_strlowcase(str));
	return (0);
}
