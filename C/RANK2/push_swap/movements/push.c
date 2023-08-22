/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:54:20 by user              #+#    #+#             */
/*   Updated: 2023/08/22 16:23:57 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void pa(t_data *data)
{
	int	value;
	t_stack	*new;

	if (data->stack_b)
	{
		write(1, "pa\n", 3);
		value = data->stack_b->value;
		new = new_stack_value(value);
	}
	else
		return;
	del_stack_first(&data->stack_b);
	add_to_stack_first(&data->stack_a, new);
}

void pb(t_data *data)
{
	int	value;
	t_stack	*new;

	if (data->stack_a)
	{
		write(1, "pb\n", 3);
		value = data->stack_a->value;
		new = new_stack_value(value);
	}
	else
		return;
	del_stack_first(&data->stack_a);
	add_to_stack_first(&data->stack_b, new);
}