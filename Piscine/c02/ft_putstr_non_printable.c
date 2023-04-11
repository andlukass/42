/* ************************************************************************** */
/*		                                                              */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:32:51 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/07 20:33:07 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

#define HEX "0123456789abcdef"

int	ft_char_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_hex(unsigned char c)
{
	ft_putchar('\\');
	ft_putchar(HEX[c / 16]);
	ft_putchar(HEX[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (ft_char_is_printable(*str))
			ft_putchar(*str);
		else
			ft_putchar_hex(*str);
		str++;
	}
}

/*int	main(void)
{
	char	test[25] = "hello\vare u good?";

	ft_putstr_non_printable(test);
}*/
