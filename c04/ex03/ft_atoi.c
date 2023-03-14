/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:53:59 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/14 14:54:03 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	isspc(char c)
{
	int	result;

	result = 0;
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r')
	{
		result = 1;
	}
	if (c == '\t' || c == '\v')
	{
		result = 1;
	}	
	return (result);
}

int	isnum(char c)
{
	int	result;

	result = 0;
	if ((c >= 48 && c <= 57) || (c == 43 || c == 45))
	{
		result = 1;
	}
	return (result);
}

void	get_number(int *final_number, int index, char *str)
{
	int	buff;
	int	dash_count;

	buff = 0;
	dash_count = 0;
	while (str[index] != '\0' && (isnum(str[index]) || isspc(str[index])))
	{
		if (str[index] == '-')
			dash_count++;
		if (!(isspc(str[index]) || str[index] == '+' || str[index] == '-'))
		{
			if (final_number == 0)
				*final_number = str[index] - 48;
			else
			{
				buff = str[index] - 48;
				*final_number = (*final_number * 10) + buff;
			}
		}
	index++;
	}
	printf("%d\n", dash_count);
	if (dash_count % 2 != 0)
		*final_number = *final_number * -1;
}

int	ft_atoi(char *str)
{
	int	final_number;

	final_number = 0;
	get_number(&final_number, 0, str);
	return (final_number);
}

/*int	main()
{
	char test1[] = "-- \n +-+----+-5252-+aa7";

	printf("%d\n",ft_atoi(test1));
}*/