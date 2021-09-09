#include "../mini.h"

char	*skip_space(char *str)
{
	while (*str != '\0' && *str == ' ')
		str++;
	return (str);
}
