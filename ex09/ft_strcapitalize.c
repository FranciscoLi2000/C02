#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	in_word;

	i = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			if (!in_word)
				str[i] &= ~32;
			else
				str[i] |= 32;
			in_word = 1;
		}
		else
			in_word = 0;
		i++;
	}
	return (str);
}

/* 位运算基础
C 语言的位运算是直接对整数的二进制位进行操作，主要有以下几种：

按位与 &：用于提取某些位，常见于权限管理或判断奇偶性。

按位或 |：用于设置某些位，例如把小写字母转换成大写。

按位异或 ^：用于翻转某些位，比如大小写转换。

按位取反 ~：把所有位取反（0 变 1，1 变 0）。

左移 << 和 右移 >>：用于位移运算，类似乘法或除法。

*/
#include <stdio.h>

int	main(void)
{
	char	str[50];

	printf("Enter a string: ");
	scanf("%s", str);
	printf("%s\n", ft_strcapitalize(str));
	return (0);
}
