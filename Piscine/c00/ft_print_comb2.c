/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:12:21 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/03 22:12:27 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	escrever(char real_numbers[4])
{
	char	numbers1[2];
	char	numbers2[2];

	numbers1[0] = real_numbers[0];
	numbers1[1] = real_numbers[1];
	numbers2[0] = real_numbers[2];
	numbers2[1] = real_numbers[3];
	write(1, &numbers1, 2);
	write(1, " ", 1);
	write(1, &numbers2, 2);
	if (!(numbers1[0] == '9' && numbers1[1] == '8'))
	{
		write(1, ", ", 1);
	}
}

void	ifs(char real_numbers[4])
{
	if (real_numbers[0] == '1' && real_numbers[2] == '1')
	{
		real_numbers[3] = '1';
	}
}

void	whiles(char real_numbers[4])
{
	while (real_numbers[0] <= '9')
	{
		while (real_numbers[1] <= '9')
		{
			while (real_numbers[2] <= '9')
			{	
				while (real_numbers[3] <= '9')
				{
					escrever(real_numbers);
					real_numbers[3]++;
				}
			real_numbers[2]++;
			real_numbers[3] = '0';
				ifs(real_numbers);
			}
			real_numbers[1]++;
		real_numbers[2] = real_numbers[0];
		real_numbers[3] = real_numbers[1] + 1;
		}
	real_numbers[1] = '0';
	real_numbers[0]++;
	}
}

void	ft_print_comb2(void)
{
	char	real_numbers[4];

	real_numbers[0] = '0';
	real_numbers[1] = '0';
	real_numbers[2] = '0';
	real_numbers[3] = '1';
	whiles(real_numbers);
}
