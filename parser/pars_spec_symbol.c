#include "../mini.h"

char	my_bsol(char c)
{
	if (c == '\\' || c == '\"' || c == '\'' || c == '`' || c == '$')
		return (c);
	return (0);
}

char	*env_variables(char **str, t_matur *matur)
{
	char	*s;
	char	*p;
	int		i;

	*str += 1;
	p = *str;
	if (**str == ' ')
		return (my_strdup("$"));
	else if (**str == '?')
	{
		p++;
		*str = p;
		return (my_itoa(matur->error));
	}
	i = 0;
	while (p[i] && p[i] != ' ' && p[i] != ';' && p[i] != '\"' && p[i] != '\'' \
				&& p[i] != '$' && p[i] != '>' && p[i] != '<' && p[i] != '\\')
		i++;
	p = my_strn(*str, i);
	*str += i;
	s = search_element_in_list_on_key(&matur->env, p);
	free(p);
	if (s)
		return (my_strdup(s));
	return (s);
}

char	*my_strn_quotes(char **str, int len, char sep)
{
	char	*s;
	int		i;
	int		j;
	char	*tmp;

	tmp = *str;
	i = 0;
	j = 0;
	s = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		if (sep == '\"' && tmp[j] == '\\' && my_bsol(tmp[j + 1]))
			s[i++] = my_bsol(tmp[++j]);
		else if (tmp[j] != sep)
			s[i++] = tmp[j];
		j++;
	}
	s[i] = '\0';
	*str += len;
	return (s);
}

char	*double_quotes(char **str, t_matur *matur)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = ++(*str);
	while (tmp[j] && tmp[j] != '\"' && tmp[j] != '$')
	{
		if (tmp[j] != '\"')
			i++;
		if (tmp[j] == '\\' && my_bsol(tmp[j + 1]))
			j++;
		j++;
	}
	tmp = my_strn_quotes(str, i, '\"');
	*str += j - i;
	if (**str == '$')
	{
		tmp = strjoin_free(tmp, env_variables(str, matur));
		*str -= 1;
		tmp = strjoin_free(tmp, double_quotes(str, matur));
	}
	*str += (**str != 0);
	return (tmp);
}

char	*single_quotes(char **str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	(*str)++;
	tmp = *str;
	while (tmp[j] && tmp[j] != '\'')
	{
		if (tmp[j] != '\'')
			i++;
		j++;
	}
	tmp = my_strn_quotes(str, i, '\'');
	*str += j - i + 1;
	return (tmp);
}
