/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:28:32 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/30 19:05:56 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	s_specifier(char *str)
{
	if (!str)
	{
		write(1, (const void *)"(null)", 6);
		return (6);
	}
	return (ft_putstr_len(str));
}
