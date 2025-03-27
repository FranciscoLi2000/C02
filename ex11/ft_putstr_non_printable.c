#include <unistd.h>
#include <ctype.h>

static void	convert_to_hex(unsigned char c, char *hex)
{
	const char	*hex_base;
	
	hex_base = "0123456789abcdef";
	hex[0] = hex_base[c / 16];
	hex[1] = hex_base[c % 16];
	hex[2] = '\0';
}

void	ft_putstr_non_printable(char *str)
{
	char	hex[3];
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0')
	{
		if (!isprint((unsigned char)str[i]))
		{
			write(1, "\\", 1);
			convert_to_hex((unsigned char)str[i], hex);
			j = 0;
			while (hex[j] != '\0') // Usamos `j` para recorrer `hex`
			{
				write(1, &hex[j], 1);
				j++;
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
