/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>
#include <stdlib.h>*/

int	ft_atoi(const char *str)
{
	int	result;
	int	negative;
	int	index;

	result = 0;
	index = 0;
	negative = 1;
	while (str[index] && ((str[index] >= 9
				&& str[index] <= 13) || str[index] == ' '))
		index++;
	if (str[index] == '-')
		negative *= -1;
	else if (str[index] != '+')
		return (0);
	index++;
	while (str[index] && ((str[index] >= 48 && str[index] <= 57)))
	{
		if (result == 0)
			result = str[index] - 48;
		else
			result = ((result * 10) + (str[index] - 48));
		index++;
	}
	return (result * negative);
}

/*int	main(void)
{
	printf("%d\n", ft_atoi("   -455 2"));
	// printf("%d\n", atoi("432423"));
}*/
