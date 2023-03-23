/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:53:59 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/14 14:54:03 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	index;
	int	control;

	index = nb - 1;
	control = 1;
	if (nb <= 0 || nb == 1)
		return (0);
	while (index > 1)
	{
		if ((nb % index) == 0)
		{
			control = 0;
		}
	index--;
	}
	return (control);
}

/*int main()
{
	printf("%d",ft_is_prime(1987));
}*/
