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

void	print_char(char c)
{
	char	*base;
	char	hexa1;
	char	hexa2;

	base = "0123456789abcdef";
	if (c < 32 || c == 127)
	{
		hexa1 = base[c / 16];
		hexa2 = base[c % 16];
		write(1, "\\", 1);
		write(1, &hexa1, 1);
		write(1, &hexa2, 1);
	}
	else
	{
		write(1, &c, 1);
	}
}

void	print_word(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		print_char(str[index]);
		index++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	print_word(str);
}

/*int	main(void)
{
	char	test[25] = "hello\vare u good?";

	ft_putstr_non_printable(test);
}*/
