#include "exam_rank02.h"

static void	convert_to_hex(char c, char *hex)
{
	char	*hex_base;
	int		first;
	int		second;

	hex_base = "0123456789abcdef";
	first = c / 16;
	second = c % 16;
	hex[0] = hex_base[first];
	hex[1] = hex_base[second];
	hex[2] = '\0';
}

void	ft_putstr_non_printable(char *str)
{
	char	hex[3];
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isprint(str[i]))
		{
			write(1, "\\", 1);
			convert_to_hex(str[i], hex);
			while (hex[i] != '\0')
			{
				write(1, &hex[i], 1);
				i++;
			}
		}
		write(1, &str[i], 1);
		i++;
	}
	str[i] = '\0';
}
