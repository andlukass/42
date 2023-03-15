/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:59:08 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/03 12:26:35 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	numbers[3];

	numbers[0] = '0';
	while (numbers[0] <= '7')
	{
		numbers[1] = numbers[0] + 1;
		while (numbers[1] <= '9')
		{
			numbers[2] = numbers[1] + 1;
			while (numbers[2] <= '9')
			{
				write(1, &numbers, 3);
				if (numbers[0] < '7')
				{
					write(1, ", ", 3);
				}
				numbers[2]++;
			}
			numbers[1]++;
		}
		numbers[0]++;
	}	
}
