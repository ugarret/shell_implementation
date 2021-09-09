#include "libmy.h"

char	*my_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	int		i;
	int		size;

	if (!str)
		return (NULL);
	i = 0;
	size = my_strlen(str);
	if ((int)start >= size)
		len = 0;
	if (size - (int)start > (int)len - 1)
		substr = (char *)malloc(sizeof(*str) * (len + 1));
	else
		substr = (char *)malloc(sizeof(*str) * (size - start + 1));
	if (!substr)
		return (NULL);
	while (i < (int)len && str[start + i] != '\0')
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
