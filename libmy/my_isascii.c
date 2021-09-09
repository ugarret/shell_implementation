int	my_isascii(int smbl)
{
	if (smbl >= 0 && smbl <= 127)
		return (1);
	else
		return (0);
}
