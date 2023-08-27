/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:51:49 by user              #+#    #+#             */
/*   Updated: 2023/08/27 18:11:18 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_sorted(t_stack *stack)
{
	int	value;

	if (stack_len(stack) <= 1)
		return (1);
	while (stack->next)
	{
		value = stack->value;
		stack = stack->next;
		if (value > stack->value)
			return (0);
	}
	return (1);
}

static int	make_move(t_data *data, int *values, void (*move)(t_data *))
{
	int		index;
	t_stack	*current;

	if (move)
		move(data);
	index = 0;
	current = data->stack_a;
	while (current->next)
	{
		values[index] = current->value;
		current = current->next;
		index++;
	}
	values[index] = current->value;
	return (1);
}

static void	sort_four_more(t_data *data)
{
	int	*values;
	int	index;
	int	to_move;
	int	size;

	index = 0;
	to_move = 0;
	size = data->a_len;
	values = malloc(sizeof(int) * size);
	if (!values)
		return ;
	while (make_move(data, values, 0) && !is_sorted(data->stack_a))
	{
		if (values[0] - values[1] == 1)
			make_move(data, values, &sa);
		if (values[0] == to_move && to_move++ > -1 && size-- > -1)
			make_move(data, values, &pb);
		else
			make_move(data, values, &ra);
	}
	while (data->b_len > 0)
		make_move(data, values, &pa);
	free(values);
}

static void	sort_three(t_data *data)
{
	int	values[3];

	make_move(data, values, 0);
	if (values[0] > values[1] && values[0] > values[2])
		make_move(data, values, &ra);
	if ((values[2] < values[1] && values[2] < values[0])
		|| (values[1] > values[0] && values[1] > values[2]))
		rra(data);
	if (!is_sorted(data->stack_a))
		sa(data);
}

void	sort_little(t_data *data)
{
	if (is_sorted(data->stack_a))
		return ;
	else if (data->a_len == 2)
		sa(data);
	else if (data->a_len == 3)
		sort_three(data);
	else if (data->a_len >= 4)
		sort_four_more(data);
}
