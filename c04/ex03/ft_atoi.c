/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:53:59 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/14 14:54:03 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	isspc(char c)
{
	int	result;

	result = 0;
	if ((c >= 9 && c <= 13) || c == ' ')
	{
		result = 1;
	}
	return (result);
}

int	get_number(int number, int index, char *str)
{
	while (str[index] && (str[index] >= '0' && str[index] <= '9'))
	{
		if (number == 0)
			number = str[index] - 48;
		else
			number = (number * 10) + (str[index] - 48);
		index++;
	}
	return (number);
}

int	ft_atoi(char *str)
{
	int	index;
	int	control;
	int	number;
	int	dash_count;

	dash_count = 0;
	control = 0;
	number = 0;
	index = -1;
	while ((str[++index]) && ((str[index] == '-' || str[index] == '+')
			|| isspc(str[index])))
	{
		if (isspc(str[index]) && (control > 0))
			return (0);
		if (str[index] == '-')
			dash_count++;
		if ((str[index] == '-' || str[index] == '+'))
			control++;
	}
	number = get_number(number, index, str);
	if (dash_count % 2 != 0)
		number = -number;
	return (number);
}

/*int	main()
{
	char test1[] = "\n    ------13256322.-a7";

	printf("ATOI: %d\n",ft_atoi(test1));
}*/