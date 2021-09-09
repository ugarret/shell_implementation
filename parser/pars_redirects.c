#include "mini.h"

char	*redir_input(char *s, t_matur *matur, t_redir *redir)
{
	int		fd;

	s = skip_space(++s);
	redir->input = pars_select(&s, matur);
	while (*s != '\0' && *s != ' ' && *s != ';' && *s != '|' && \
												*s != '>' && *s != '<')
		redir->input = my_strjoin(redir->input, pars_select(&s, matur));
	fd = open(redir->input, O_RDONLY);
	if (fd >= 0)
		close(fd);
	else
	{
		redir->error = 1;
		while (*s != '\0' && *s != ';' && *s != '|')
			s++;
	}
	return (s);
}

char	*redir_output(char *s, t_matur *matur, t_redir	*redir)
{
	char	*out;
	int		fd;

	if (*(s + 1) == '>')
		fd = 2;
	else
		fd = 1;
	s = skip_space(s + fd);
	out = my_strjoin(my_itoa(fd), pars_select(&s, matur));
	while (*s != '\0' && *s != ' ' && *s != ';' && *s != '|' && \
												*s != '>' && *s != '<')
		out = my_strjoin(out, pars_select(&s, matur));
	my_lstadd_back(&redir->output, my_lstnew((void *)out));
	return (s);
}

char	*redir_space(char *s, t_matur *matur, t_lstc *collector)
{
	char	*p;

	s = skip_space(s);
	while (*s && *s != '<' && *s != '>' && *s != '|' && *s != ';')
	{
		p = pars_select(&s, matur);
		while (*s != '\0' && *s != ' ' && *s != ';' && *s != '|')
			p = strjoin_free(p, pars_select(&s, matur));
		add_to_lst(collector, p);
		s = skip_space(s);
	}
	return (s);
}

void	redir_pars(char **str, t_matur *matur, t_lstc *collector)
{
	t_redir	redir;
	char	*s;

	my_bzero(&redir, sizeof(redir));
	s = *str;
	while (*s != '\0' && *s != ';' && *s != '|')
	{
		if (*s == '<')
			s = redir_input(s, matur, &redir);
		if (*s == '>')
			s = redir_output(s, matur, &redir);
		if (*s == ' ')
			s = redir_space(s, matur, collector);
	}
	allocate_mem(matur, collector);
	work_with_redirect(&redir, matur);
	if (*s == '|' || *s == ';')
		s += 1;
	*str = skip_space(s);
}
