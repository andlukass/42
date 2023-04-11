/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:53:59 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/14 14:54:03 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	index;

	index = nb - 1;
	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	while (index > 0)
	{
		nb = nb * index;
		index--;
	}
	return (nb);
}

/*int main()
{
	printf("%d",ft_iterative_factorial(0));
}*/
