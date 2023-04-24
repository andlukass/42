static int	ft_putstr(char *str)
{
    int index;

    index = 0;
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
	}
    return (index);
}

static int	get_length(long int i)
{
	int	length;

	length = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i *= -1;
		length++;
	}
	while (i > 0)
	{
		i /= 10;
		length++;
	}
	return (length);
}

int di_specifier(int nb)
{
	char		str[50];
	int			length;
	long int	unb;

	unb = nb;
	length = get_length(unb);
	if (unb == 0)
		str[0] = 0 + '0';
	str[length] = '\0';
	length--;
	if (unb < 0)
	{
		str[0] = '-';
		unb = unb * -1;
	}
	while (unb > 0)
	{
		str[length] = unb % 10 + '0';
		unb = unb / 10;
		length--;
	}
    return (ft_putstr(str));
}