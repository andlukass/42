/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xx_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:30:47 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/30 16:59:21 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	putstr(char *base, long int index, unsigned int *nbr_final)
{
	while (--index >= 0)
		write(1, &base[nbr_final[index]], 1);
}

int	xx_specifier(unsigned int nbr, char c)
{
	unsigned int	index;
	unsigned int	length;
	unsigned int	nbr_final[50];

	index = 0;
	if (!nbr)
	{
		write(1, (const void *)"0", 1);
		return (1);
	}
	while (nbr)
	{
		nbr_final[index] = nbr % 16;
		nbr = nbr / 16;
		index++;
	}
	length = index;
	if (c == 'x')
		putstr("0123456789abcdef", index, nbr_final);
	else
		putstr("0123456789ABCDEF", index, nbr_final);
	return (length);
}
