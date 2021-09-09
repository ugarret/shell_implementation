int	my_toupper(int ltr)
{
	if (ltr >= 97 && ltr <= 122)
		return (ltr - 32);
	else
		return (ltr);
}
