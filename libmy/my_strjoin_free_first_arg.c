#include "libmy.h"

char	*my_strjoin_free_first_arg(char *str1, char *str2)
{
	char	*comb;
	int		len1;
	int		len2;
	int		i;

	len1 = my_strlen(str1);
	len2 = my_strlen(str2);
	comb = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!comb)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		comb[i] = str1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		comb[i] = str2[i - len1];
		i++;
	}
	comb[i] = '\0';
	free(str1);
	return (comb);
}
