#include "libmy.h"

size_t	my_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = my_strlen(dst);
	srclen = my_strlen(src);
	if (dstsize == 0)
		return (srclen);
	if (dstlen >= dstsize)
		return (srclen + dstsize);
	while (dstlen + i + 1 < dstsize && src[i] != '\0')
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
