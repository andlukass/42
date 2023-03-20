#include <unistd.h>

void		ft_putchar(char c)
{
    write(1 , &c, 1);
}

void		ft_put_base(int nb, char *base)
{
	int		len;

	len = 0;
	while (base[len])
		len = len + 1;
	if (nb >= len)
	{
		ft_put_base(nb / len, base);
		ft_put_base(nb % len, base);
	}
	else
		ft_putchar(base[nb]);
}

char		check_str(char *str, char *str2)
{
	if (*str && *str2 && *str == *str2)
		return (check_str(str + 1, str2 + 1));
	if (*str == '\0' && *str2 == '\0')
		return (1);
	return (0);
}

void		ft_putnbr_base(int nbr, char *base)
{
	if (check_str(base, "0123456789"))
		ft_put_base(nbr, "0123456789");
	else if (check_str(base, "01"))
		ft_put_base(nbr, "01");
	else if (check_str(base, "0123456789ABCDEF"))
		ft_put_base(nbr, "0123456789ABCDEF");
	else if (check_str(base, "poneyvif"))
		ft_put_base(nbr, "01234567");
}

int main()
{
    //char base[] = "0123456789";
    //char base[] = "01";
    char base[] = "0123456789ABCDEF";
    //char base[] = "poneyvif";
    ft_putnbr_base(1635,base);
}
