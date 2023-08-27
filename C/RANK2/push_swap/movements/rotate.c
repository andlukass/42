/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:24:30 by llopes-d          #+#    #+#             */
/*   Updated: 2023/08/27 15:11:57 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **stack)
{
	int		index;
	int		length;
	t_stack	*first;
	t_stack	*current;

	length = stack_len(*stack);
	if (length < 2)
		return ;
	first = *stack;
	current = *stack;
	*stack = current->next;
	while (current->next)
		current = current->next;
	current->next = first;
	first->next = NULL;
}

void	ra(t_data *data)
{
	write(1, "ra\n", 3);
	rotate(&data->stack_a);
}

void	rb(t_data *data)
{
	write(1, "rb\n", 3);
	rotate(&data->stack_b);
}

void	rr(t_data *data)
{
	write(1, "rr\n", 3);
	rotate(&data->stack_a);
	rotate(&data->stack_b);
}
