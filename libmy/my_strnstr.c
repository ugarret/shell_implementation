#include "libmy.h"

char	*my_strnstr(const char *hst, const char *ndl, size_t len)
{
	size_t	bg;
	size_t	lt;

	bg = 0;
	lt = 0;
	if (!*ndl)
		return ((char *)hst);
	while (hst[bg] != '\0' && bg < len)
	{
		if (hst[bg] == ndl[lt])
		{
			while (hst[bg + lt] == ndl[lt] && hst[bg + lt] != '\0'
				&& ndl[lt] != '\0' && bg + lt < len)
				lt++;
		}
		if (lt == my_strlen(ndl))
			return ((char *)&hst[bg]);
		lt = 0;
		bg++;
	}
	return (NULL);
}
