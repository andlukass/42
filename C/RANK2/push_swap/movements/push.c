/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:54:20 by user              #+#    #+#             */
/*   Updated: 2023/08/22 09:10:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void pa(t_data *data)
{
	int	value;
	t_stack	*new;

	if (data->stack_b)
	{
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
		value = data->stack_a->value;
		new = new_stack_value(value);
	}
	else
		return;
	del_stack_first(&data->stack_a);
	add_to_stack_first(&data->stack_b, new);
}