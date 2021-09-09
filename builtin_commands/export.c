#include "../mini.h"

static int	my_strchr_index(const char *str, int chr)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)chr)
			return (i);
		i++;
	}
	return (-1);
}

static void	add_or_replace(t_matur *matur, char *str)
{
	int		equally;
	char	*key;
	char	*value;

	equally = my_strchr_index(str, '=');
	if (equally != -1)
	{
		key = my_strtrim(my_substr(str, 0, equally), "+");
		value = my_substr(str, equally + 1, my_strlen(&str[equally + 1]));
		if (!(search_element_in_list_on_key(&matur->env, key)))
			add_element(&matur->env, new_element(key, value));
		else if (str[equally - 1] == '+')
			add_value(&matur->env, key, value);
		else
			replace_value(&matur->env, key, value);
	}
	else
	{
		key = my_strdup(str);
		if (!(search_element_in_list_on_key(&matur->env, key)))
			add_element(&matur->env, new_element(key, NULL));
	}
}

static void	print_two_str(char *str1, char *str2, int fd)
{
	if (str1)
		my_putstr_fd(str1, fd);
	if (str2)
		my_putstr_fd(str2, fd);
}

static void	print_export(t_matur *matur)
{
	t_list_env	*tmp;

	tmp = sort_elements_of_list(matur->env);
	while (tmp != NULL)
	{
		print_two_str("declare -x ", tmp->key, 1);
		if (tmp->value != NULL)
			print_two_str("=", tmp->value, 1);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}

void	my_export(t_matur *matur)
{
	int			i;
	int			flag;

	i = 1;
	flag = 0;
	if (matur->mass[i] == NULL)
		print_export(matur);
	while (matur->mass[i] != NULL)
	{
		if (validation_of_arguments(matur->mass[i], matur))
			add_or_replace(matur, matur->mass[i]);
		else
			flag = 1;
		i++;
	}
	if (!flag)
		matur->error = 0;
}
