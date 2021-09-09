#include "libmy.h"

char	*my_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*fin_str;

	if (!str)
		return (NULL);
	i = 0;
	len = my_strlen(str);
	fin_str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!fin_str)
		return (NULL);
	while (i < (unsigned int)len)
	{
		fin_str[i] = (*f)(i, str[i]);
		i++;
	}
	fin_str[i] = '\0';
	return (fin_str);
}
