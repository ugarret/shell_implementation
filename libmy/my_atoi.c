#include "libmy.h"

int	my_atoi(char *str)
{
	int				i;
	unsigned long	num;
	int				znak;

	i = 0;
	num = 0;
	znak = 1;
	while (*str == ' ' || (*str > 8 && *str < 13) || *str == '\r')
		str++;
	if (*str == '+' && *(str + 1) != '-')
		str++;
	else if (*str == '-')
	{
		znak = znak * (-1);
		str++;
	}
	while (my_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * znak);
}
