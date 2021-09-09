#include "libmy.h"

int	my_putchar(int smb)
{
	int	res;

	res = write (1, &smb, 1);
	return (res);
}
