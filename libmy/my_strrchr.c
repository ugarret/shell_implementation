#include "libmy.h"

char	*my_strrchr(const char *str, int chr)
{
	int	len;

	len = my_strlen(str);
	while (len >= 0)
	{
		if (str[len] == (char)chr)
			return ((char *)&str[len]);
		len--;
	}
	return (NULL);
}
