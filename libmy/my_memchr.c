#include "libmy.h"

void	*my_memchr(const void *str, int smb, size_t n)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)str;
	while (i < n)
	{
		if (s[i] == (char)smb)
			return ((void *)(&s[i]));
		i++;
	}
	return (NULL);
}
