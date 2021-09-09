#include "libmy.h"

void	*my_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*destination;
	char		*source;

	if (!dst && !src)
		return (NULL);
	i = 0;
	destination = (char *)dst;
	source = (char *)src;
	if (dst > src)
	{
		while (len > 0)
		{
			destination[len - 1] = source[len - 1];
			len--;
		}
		return (dst);
	}
	while (i < len)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}
