#include "libmy.h"

int	my_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (!str1)
		return (-1);
	if (!str2)
		return (1);
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
