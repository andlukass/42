/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:20:05 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/04 21:20:11 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void escrever(char final)
{
	write(1, &final, 1);
}

void ft_putnbr(int nb)
{

	if(nb == -2147483648)
	{
		escrever('-');
		escrever('2');
		nb = 147483648;
	}
	if(nb < 0)
	{
		nb = nb * -1;
		escrever('-');
		ft_putnbr(nb);
	}
	else if(nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		escrever(nb + '0');
	}
}

int main()
{
	ft_putnbr(-2147483648);
}
