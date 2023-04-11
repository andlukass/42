/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:53:59 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/14 14:54:03 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power == 1)
		return (nb);
	else
		return (nb * ft_recursive_power(nb, power-1));
}

/*int main()
{
	printf("%d",ft_recursive_power(2, 4));
}*/
