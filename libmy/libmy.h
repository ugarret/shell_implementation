#ifndef LIBMY_H
# define LIBMY_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	*my_memset(void *memptr, int val, size_t len);
void	my_bzero(void *str, size_t n);
void	*my_memcpy(void *dst, const void *src, size_t n);
void	*my_memccpy(void *dst, const void *src, int smb, size_t n);
void	*my_memmove(void *dst, const void *src, size_t len);
void	*my_memchr(const void *str, int smb, size_t n);
int		my_memcmp(const void *str1, const void *str2, size_t n);
size_t	my_strlen(const char *str);
size_t	my_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	my_strlcat(char *dst, const char *src, size_t dstsize);
char	*my_strchr(const char *str, int chr);
char	*my_strrchr(const char *str, int chr);
char	*my_strnstr(const char *hst, const char *ndl, size_t len);
int		my_strncmp(const char *str1, const char *str2, size_t n);
int		my_atoi(char *str);
int		my_isalpha(int smbl);
int		my_isdigit(int smbl);
int		my_isalnum(int smbl);
int		my_isascii(int smbl);
int		my_isprint(int smbl);
int		my_toupper(int ltr);
int		my_tolower(int ltr);
void	*my_calloc(size_t count, size_t size);
char	*my_strdup(const char *str);
char	*my_substr(char const *str, unsigned int start, size_t len);
char	*my_strjoin(char const *str1, char const *str2);
char	*my_strjoin_free_first_arg(char *str1, char *str2);
char	*my_strtrim(char const *str, char const *set);
char	**my_split(char const *str, char smb);
char	*my_itoa(int num);
char	*my_strmapi(char const *str, char (*f)(unsigned int, char));
void	my_putchar_fd(char c, int fd);
int		my_putchar(int smb);
void	my_putstr_fd(char *s, int fd);
void	my_putendl_fd(char *s, int fd);
void	my_putnbr_fd(int nbr, int fd);
void	my_lstadd_back(t_list **lst, t_list *new);
t_list	*my_lstnew(void *content);
void	my_lstclear(t_list **lst, void (*del_f)(void *));
void	free_arr(char **array);

#endif
