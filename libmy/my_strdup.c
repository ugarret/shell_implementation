#include "libmy.h"

char	*my_strdup(const char *str)
{
	size_t	len;
	char	*copy;

	len = my_strlen(str);
	copy = (char *)malloc(sizeof(*str) * (len + 1));
	if (!copy)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
	{
		copy[len] = str[len];
		len++;
	}
	copy[len] = '\0';
	return (copy);
}
