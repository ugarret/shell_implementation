#include "libmy.h"

void	*my_memccpy(void *dst, const void *src, int smb, size_t n)
{
	char	*destination;
	char	*source;
	size_t	i;

	destination = (char *)dst;
	source = (char *)src;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		if (source[i] == (char)smb)
			return (destination + i + 1);
		i++;
	}
	return (NULL);
}
