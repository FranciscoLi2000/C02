#include <unistd.h>
#include <ctype.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (islower(str[i]))
			str[i] = toupper(str[i]);
		i++;
	}
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char	str[50];

	printf("Enter a string: ");
	scanf("%s", str);
	printf("%s\n", ft_strupcase(str));
	return (0);
}
