#include "libmy.h"

void	my_putendl_fd(char *s, int fd)
{
	my_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
