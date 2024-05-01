/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:27:16 by llopes-d          #+#    #+#             */
/*   Updated: 2023/05/29 14:20:06 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	p_specifier(void *adress)
{
	unsigned long int	index;
	unsigned long int	nbr;
	unsigned long int	nbr_final[50];

	index = 0;
	nbr = (unsigned long int)adress;
	if (!nbr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	while (nbr)
	{
		nbr_final[index] = nbr % 16;
		nbr = nbr / 16;
		index++;
	}
	return ((ft_putstr_base(L_HEX, index, nbr_final)) + 2);
}
