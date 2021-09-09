int	my_isprint(int smbl)
{
	if (smbl >= 32 && smbl <= 126)
		return (1);
	else
		return (0);
}
