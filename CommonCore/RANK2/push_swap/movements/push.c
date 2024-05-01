/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:54:20 by user              #+#    #+#             */
/*   Updated: 2023/08/27 15:12:55 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **to_add, t_stack **to_rm, char *move)
{
	int		value;
	t_stack	*new;
	t_stack	*current;

	current = *to_rm;
	if (*to_rm)
	{
		write(1, move, 3);
		value = current->value;
		new = new_stack_value(value);
	}
	else
		return ;
	del_stack_first(to_rm);
	add_to_stack_first(to_add, new);
}

void	pa(t_data *data)
{
	push(&data->stack_a, &data->stack_b, "pa\n");
	data->a_len = data->a_len + 1;
	data->b_len = data->b_len - 1;
}

void	pb(t_data *data)
{
	push(&data->stack_b, &data->stack_a, "pb\n");
	data->a_len = data->a_len - 1;
	data->b_len = data->b_len + 1;
}
