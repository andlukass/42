/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:19:20 by llopes-d          #+#    #+#             */
/*   Updated: 2023/06/21 20:12:02 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minitalk.h"

int	ft_atoi_base(char *s, int base)
{
	int		result;
	int		digit;
	int		i;
	int		j;

	result = 0;
	digit = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (j < base)
		{
			if (DIGITS[j] == s[i])
			{
				digit = j;
				break ;
			}
			j++;
		}
		result = result * base + digit;
		i++;
	}
	return (result);
}
