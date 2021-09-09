#include "libmy.h"

int	my_isalnum(int smbl)
{
	if (my_isalpha(smbl) || my_isdigit(smbl))
		return (1);
	else
		return (0);
}
