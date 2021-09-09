#include "../mini.h"

char	*my_list(char **str)
{
	int		len;
	char	*s;
	int		i;

	s = *str;
	len = 0;
	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != ';' && s[i] != '\"' && s[i] != '\'' \
				&& s[i] != '$' && s[i] != '>' && s[i] != '<' && s[i] != '|')
	{
		len++;
		if (s[i] == '\\')
			i++;
		i++;
	}
	s = my_strn(*str, len);
	*str += i;
	return (s);
}

char	*my_strn(char *str, int len)
{
	char	*s;
	int		i;

	i = 0;
	s = malloc(sizeof(char) * (len + 1));
	while (str && i < len)
	{
		if (*str != '\\')
			s[i++] = *str;
		else if (*(str + 1) == '\\')
			s[i++] = *str++;
		str++;
	}
	s[i] = '\0';
	return (s);
}

char	*pars_select(char **str, t_matur *matur)
{
	if (**str == '$')
		return (env_variables(str, matur));
	else if (**str == '\"')
		return (double_quotes(str, matur));
	else if (**str == '\'')
		return (single_quotes(str));
	else
		return (my_list(str));
}

void	connector_search(char **line, t_matur *matur, t_lstc *c, t_lstc *p)
{
	*line = skip_space(*line);
	if (**line == ';')
	{
		list_processing(matur, c, p, line);
		*line += 1;
	}
	else if (**line == '|')
	{
		if (c->count != 0)
		{
			allocate_mem(matur, c);
			if (**matur->mass)
				add_to_lst(p, matur->mass);
			else
			{
				my_puterror("syntax error ", NULL, "'|'");
				matur->error = 258;
				*(*line + 1) = 0;
			}
			lst_free(c);
			*line += 1;
		}
	}
}

t_matur	*parser(char *str, t_matur *matur)
{
	t_lstc	collector;
	t_lstc	pipe_list;
	char	*s;

	my_bzero(&collector, sizeof(t_lstc));
	my_bzero(&pipe_list, sizeof(t_lstc));
	while (*str != '\0')
	{
		str = skip_space(str);
		if (*str == '<' || *str == '>')
		{
			redir_pars(&str, matur, &collector);
			clear_lst(&collector);
		}
		s = pars_select(&str, matur);
		while (*str != '\0' && *str != ' ' && *str != ';' && *str != '|')
			s = strjoin_free(s, pars_select(&str, matur));
		add_to_lst(&collector, s);
		connector_search(&str, matur, &collector, &pipe_list);
	}
	list_processing(matur, &collector, &pipe_list, &str);
	return (matur);
}
