/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:58:27 by llopes-d          #+#    #+#             */
/*   Updated: 2023/09/03 14:26:16 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_unique(int *array, int length)
{
	int	index;
	int	j;

	index = 0;
	while (index < length)
	{
		j = -1;
		while (++j < length)
			if (array[j] == array[index] && j != index)
				return (ERROR);
		index++;
	}
	return (OK);
}

static int	valid_number(char *arg)
{
	int			index;

	index = -1;
	while (arg[++index])
	{
		if (!is_number(arg[index]))
		{
			if (((arg[0] == '+' || arg[0] == '-') && (arg[1] || arg[1] == ' ') 
					&& index++ == 0) || arg[index] == ' ')
				continue ;
			return (ERROR);
		}
	}
	if (index > 11)
		return (ERROR);
	return (OK);
}

static void	get_indexes(int *array, int length)
{
	int	*copy;
	int	index;
	int	j;

	index = -1;
	copy = malloc(sizeof(int) * length);
	if (!copy)
		return ;
	while (++index < length)
		copy[index] = array[index];
	bubble_sort(copy, length);
	index = -1;
	while (++index < length)
	{
		j = -1;
		while (++j < length)
		{
			if (array[index] == copy[j])
			{
				array[index] = j;
				break ;
			}
		}
	}
	free(copy);
}

static int	atolarize(int *array, int length, char *arguments[])
{
	int			index;
	long int	value;

	index = 0;
	while (index < length)
	{
		if (!valid_number(arguments[index]))
			return (ERROR);
		value = ft_atoi(arguments[index]);
		if (value > 2147483647 || value < -2147483648)
			return (ERROR);
		array[index] = value;
		index++;
	}
	if (!is_unique(array, length))
		return (ERROR);
	return (OK);
}

int	init_stacks(t_data *data, int length, char *arguments[])
{
	int			index;
	int			*array;

	index = 0;
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->a_len = length;
	data->b_len = 0;
	array = malloc(sizeof(int) * length);
	if (!array)
		return (ERROR);
	if (!atolarize(array, length, arguments))
	{
		free(array);
		return (ERROR);
	}
	get_indexes(array, length);
	while (index < length)
		add_to_stack_last(&data->stack_a, new_stack_value(array[index++]));
	free(array);
	return (OK);
}
