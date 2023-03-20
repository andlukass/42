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

int	isnum(char c, int control, char *str)
{
	int	result;
	int	index;

	result = 0;
	index = 0;
	if (control == 0)
	{
		if ((c >= 48 && c <= 57) || (c == 43 || c == 45))
		{
				result = 1;
		}
		return (result);
	}
	else
	{
		while (str[index] != '\0' && ((str[index] == 43 || str[index] == 45)))
		{		
			if (str[index] == '-')
					result++;
			index++;
		}
	}
	return (result);
}

void	get_number(int *final_number, int index, char *str)
{
	int	buff;

	buff = 0;
	while (str[index] != '\0' && (isnum(str[index], 0, str)
			|| isspc(str[index])))
	{
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
}

int	ft_atoi(char *str)
{
	int	final_number;
	int	index;
	int	dash_count;
	int	space_after;

	index = 0;
	dash_count = 0;
	space_after = 0;
	while (str[index] && (dash_count <= 1))
	{	
		if ((str[index] == '-' || str[index] == '+') && dash_count < 1)
			dash_count++;
		if (isspc(str[index]) && dash_count >= 1)
			space_after++;
		if (space_after > 0)
			return (0);
		index++;
	}
	final_number = 0;
	dash_count = 0;
	get_number(&final_number, 0, str);
	dash_count = isnum(str[index], 1, str);
	if (dash_count % 2 != 0)
		final_number = final_number * -1;
	return (final_number);
}

/*int	main()
{
	char test1[] = "   -+-5252a-a7";

	printf("%d\n",ft_atoi(test1));
}*/