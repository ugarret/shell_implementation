#include "libmy.h"

void	*my_memcpy(void *dst, const void *src, size_t n)
{
	char	*destination;
	char	*source;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	destination = (char *)dst;
	source = (char *)src;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}
