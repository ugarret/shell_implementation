#include "libmy.h"

void	my_putnbr_fd(int nbr, int fd)
{
	if (nbr == -2147483648)
	{
		write(fd, "-2", 2);
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr / 10 > 0)
		my_putnbr_fd(nbr / 10, fd);
	my_putchar_fd(nbr % 10 + 48, fd);
}
