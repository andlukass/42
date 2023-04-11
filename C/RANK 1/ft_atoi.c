/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>
#include <stdlib.h>*/
int ft_atoi(const char *str)
{
	int result;
	int index;
	int dash;

	result = 0;
	index = 0;
	dash = 0;
	while (str[index] && ((str[index] >= 9 && str[index] <= 13) || str[index] == ' '))
		index++;
	while (str[index] && ((str[index] == '+' || str[index] == '-')))
	{
		if (str[index] == '-')
			dash++;
		index++;
	}
	while (str[index] && ((str[index] >= 48 && str[index] <= 57)))
	{
		if (result == 0)
			result = str[index] - 48;
		else
			result = ((result * 10) + (str[index] - 48));
		index++;
	}
	return ((dash % 2 == 0) ? result : (result *= -1));
}
/*int main()
{
	printf("%d\n", ft_atoi("   --455 2"));
	// printf("%d\n", atoi("432423"));
}*/
