/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:27:16 by llopes-d          #+#    #+#             */
/*   Updated: 2023/05/01 19:31:03 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	p_specifier(void *adress)
{
	unsigned long int	index;
	unsigned long int	length;
	unsigned long int	nbr;
	unsigned long int	nbr_final[50];

	index = 0;
	nbr = (unsigned long int)adress;
	if (!nbr)
	{
		write(1, (const void *)"(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	while (nbr)
	{
		nbr_final[index] = nbr % 16;
		nbr = nbr / 16;
		index++;
	}
	length = index + 2;
	ft_putstr_base(L_HEX, index, nbr_final);
	return (length);
}
