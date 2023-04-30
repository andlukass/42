/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 18:01:57 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/30 18:49:15 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putstr_base(char *base, long int index, unsigned long *nbr_final)
{
	while (--index >= 0)
		write(1, &base[nbr_final[index]], 1);
}
