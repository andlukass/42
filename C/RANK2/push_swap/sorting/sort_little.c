/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:51:49 by user              #+#    #+#             */
/*   Updated: 2023/08/26 09:04:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_bigger(int value, int *array, int size)
{
	int	index;

	index = 0;
	if (size <= 1)
		return (0);
	while (index < size)
	{
		if(value < array[index])
			return (0);
		index++;
	}
	return (1);
}

void	bubble_stack_sort(t_data *data)
{
	int	value;
	t_stack	*current;

	current = data->stack_a;
	while(!is_sorted(data->stack_a))
	{
		while(data->a_len != 1)
		{
			current = data->stack_a;
			value = current->value;
			current = current->next;
			if (value < current->value)
				pb(data);
			else
				sa(data);
			if(is_sorted(data->stack_a))
				break ;
		}
		while(data->b_len > 0)
			pa(data);
	}
}

void	get_values(t_data *data, int *values, int size)
{
	int	index;
	t_stack	*current;

	index = 0;
	current = data->stack_a;
	while(current->next)
	{
		values[index] = current->value;
		current = current->next;
		index++;
	}
	values[index] = current->value;
}

void	sort_four_more(t_data *data, int size)
{
	int	values[size];
	int	index;
	int	to_move;
	int	size_before;

	index = 0;
	to_move = 0;
	size_before = size;
	while (!is_sorted(data->stack_a))
	{
		get_values(data, values, size);
		// printf("v0: %d, v1: %d, v2: %d, v3: %d\n", values[0], values[1]
		// 	, values[2], values[3]);
		// printf("TOMOVE: %d v0: %d\n", to_move, values[0]);
		if (values[0] - values[1] == 1)
		{
			sa(data);
		}
		get_values(data, values, size);
		if (values[size-2] == to_move && size > 2)
		{	
			// printf("TOMOVE: %d value: %d size: %d \n", to_move, values[size-1], size);
			rra(data);
		}
		get_values(data, values, size);
		if (values[0] - values[1] == 1)
		{
			sa(data);
		}
		get_values(data, values, size);
		if (values[size-1] == to_move && size > 1)
		{	
			// printf("TOMOVE: %d value: %d size: %d \n", to_move, values[size-1], size);
			rra(data);
		}
		get_values(data, values, size);
		if (values[0] == to_move)
		{	
			to_move++;
			// printf("TOMOVE: %d v0: %d\n", to_move, values[0]);
			pb(data);
			size--;
		}
		else
			ra(data);
		get_values(data, values, size);

		// while (is_sorted(data->stack_a) && size > 1 && size != size_before)
		// {	
		// 	// printf("teste\n");
		// 	pb(data);
		// 	size++;
		// }
	}
	while (data->a_len < size_before)
		pa(data);
	// bubble_stack_sort(data);
}

void	sort_little(t_data *data)
{
	if (is_sorted(data->stack_a))
		return ;
	else if(data->a_len == 2)
		sa(data);
	else if(data->a_len == 3)
		sort_three(data);
	else if(data->a_len >= 4)
		sort_four_more(data, data->a_len);
}
