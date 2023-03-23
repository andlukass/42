/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:31:36 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/21 18:31:38 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

int	check_base(char *base)
{
	int	control;
	int	index;	

	index = 0;
	while (base[index])
	{
		control = index + 1;
		if (base[index] == '+' || base[index] == '-')
			return (0);
		if (base[index] < 32 || base[index] > 126)
			return (0);
		while (base[control])
		{
			if (base[index] == base[control])
				return (0);
			control++;
		}
		index++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nbr_final[50];
	unsigned int	index;
	unsigned int	unbr;

	unbr = nbr;
	if (nbr < 0)
	{
		unbr = -nbr;
		write(1, "-", 1);
	}
	index = 0;
	if (ft_strlen(base) >= 2 && check_base(base))
	{
		while (unbr)
		{
			nbr_final[index++] = unbr % ft_strlen(base);
			unbr = unbr / ft_strlen(base);
		}
		while (--index > 0)
		{
			write(1, &base[nbr_final[index]], 1);
		}
		write(1, &base[nbr_final[index]], 1);
	}
}

int	main()
{
	//char base[] = "0123456789";
	char base[] = "01";
	//char base[] = "0123456789ABCDEF";
	//char base[] = "poneyvif";
	ft_putnbr_base(-2147483648, base);
}