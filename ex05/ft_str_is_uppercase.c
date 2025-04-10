#include <unistd.h>
#include <ctype.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!isupper(str[i]))
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>

int	main(void)
{
	char	str[50];

	printf("Enter a string: ");
	scanf("%s", str);
	printf("%i\n", ft_str_is_uppercase(str));
	return (0);
}
