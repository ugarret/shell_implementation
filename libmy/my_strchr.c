#include "libmy.h"

char	*my_strchr(const char *str, int chr)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != (char)chr)
		i++;
	if (str[i] == (char)chr)
		return ((char *)&str[i]);
	return (NULL);
}
