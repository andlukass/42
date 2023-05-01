/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xX_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:30:47 by llopes-d          #+#    #+#             */
/*   Updated: 2023/05/01 13:54:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int xx_specifier(unsigned int nbr, char c)
{
	unsigned int index;
	unsigned int length;
	unsigned long int nbr_final[50];

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
		ft_putstr_base(L_HEX, index, nbr_final);
	else
		ft_putstr_base(U_HEX, index, nbr_final);
	return (length);
}
