#include <unistd.h>

static void	print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[c >> 4], 1);
	write(1, &hex[c & 0xF], 1);
}

static void	print_address(void *addr)
{
	unsigned long	address = (unsigned long)addr;
	char	hex_addr[16];
	int	i;

	address = (unsigned long)addr;
	i = 15;
	while (i >= 0)
	{
		hex_addr[i] = "0123456789abcdef"[address % 16];
		address /= 16;
		i--;
	}
	write(1, hex_addr, 16);
	write(1, ": ", 2);
}

static void	print_memory_line(unsigned char *p, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < len)
			print_hex(p[i]);
		else
			write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
	}
	i = 0;
	while (i < len)
	{
		if (p[i] >= 32 && p[i] <= 126)
			write(1, &p[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*p;

	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_address(p + i);
		if (size - i < 16)
			print_memory_line(p + i, size - i);
		print_memory_line(p + i, 16);
		i += 16;
	}
	return (addr);
}

#include <stdio.h>

int	main(void)
{
	unsigned int	size;
	unsigned char	*str;

	size = 100;
	printf("Enter a string: ");
	scanf("%s", str);
	ft_print_memory((void*)str, size);

	return (0);
}
