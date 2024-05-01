/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xx_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:30:47 by llopes-d          #+#    #+#             */
/*   Updated: 2023/05/29 14:18:28 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	xx_specifier(unsigned int nbr, char c)
{
	unsigned int		index;
	unsigned long int	nbr_final[50];

	index = 0;
	if (!nbr)
		return (write(1, "0", 1));
	while (nbr)
	{
		nbr_final[index] = nbr % 16;
		nbr = nbr / 16;
		index++;
	}
	if (c == 'x')
		return (ft_putstr_base(L_HEX, index, nbr_final));
	else
		return (ft_putstr_base(U_HEX, index, nbr_final));
}
