/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:29:58 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/30 16:30:41 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_putstr_u(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
	}
	return (index);
}

static int	get_length_u(long int i)
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

int	u_specifier(unsigned int nb)
{
	char		str[50];
	int			length;
	long int	unb;

	unb = nb;
	length = get_length_u(unb);
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
	return (ft_putstr_u(str));
}
