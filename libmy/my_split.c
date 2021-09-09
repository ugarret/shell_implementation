#include "libmy.h"

int	my_count_word(char const *str, char smb)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == smb)
			i++;
		if (str[i] != '\0')
		{
			count++;
			while (str[i] != smb && str[i] != '\0')
				i++;
		}
	}
	return (count);
}

char	*my_malloc_for_word(char const *str, char smb)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] != smb && str[i])
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	word[i] = '\0';
	i--;
	while (i >= 0)
	{
		word[i] = str[i];
		i--;
	}
	return (word);
}

static char	**my_error_malloc(char **arr, int j)
{
	while (j >= 0)
	{
		free(arr[j]);
		j--;
	}
	free(arr);
	arr = NULL;
	return (arr);
}

char	**my_split(char const *str, char smb)
{
	int		j;
	char	**arr;
	int		count_word;

	if (!str)
		return (NULL);
	j = 0;
	count_word = my_count_word(str, smb);
	arr = (char **)malloc(sizeof(char *) * (count_word + 1));
	if (!arr)
		return (NULL);
	while (j != count_word)
	{
		while (*str == smb && *str != '\0')
			str++;
		arr[j] = my_malloc_for_word(str, smb);
		if (arr[j] == NULL)
			return (my_error_malloc(arr, j));
		while (*str != smb && *str != '\0')
			str++;
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
