/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:29:58 by llopes-d          #+#    #+#             */
/*   Updated: 2023/05/29 14:16:41 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	u_specifier(unsigned int nb)
{
	char		str[50];
	int			length;
	long int	unb;

	unb = nb;
	length = ft_get_length(unb);
	str[length] = '\0';
	if (unb == 0)
		str[0] = '0';
	length--;
	while (unb > 0)
	{
		str[length] = unb % 10 + '0';
		unb = unb / 10;
		length--;
	}
	return (ft_putstr_len(str));
}
