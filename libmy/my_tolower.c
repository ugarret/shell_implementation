int	my_tolower(int ltr)
{
	if (ltr >= 65 && ltr <= 90)
		return (ltr + 32);
	else
		return (ltr);
}
