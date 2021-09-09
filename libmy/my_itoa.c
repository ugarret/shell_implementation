#include "libmy.h"

int	my_count(long n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*my_itoa(int num)
{
	int		i;
	char	*str;
	int		len;
	long	n;

	n = num;
	i = 0;
	len = my_count(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
		i++;
	}
	str[len] = '\0';
	while (len > i)
	{
		str[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (str);
}
