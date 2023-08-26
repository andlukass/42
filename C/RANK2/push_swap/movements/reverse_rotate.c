/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:13:16 by llopes-d          #+#    #+#             */
/*   Updated: 2023/08/25 17:29:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	int index;
	int	length;
	t_stack	*last;
	t_stack	*penult;
	t_stack	*current;

	length = stack_len(*stack);
	if (length < 2)
		return ;
	index = 0;
	current = *stack;
	last = *stack;
	penult = *stack;
	while(index++ < length - 2)
		penult = penult->next;
	while(last->next)
		last = last->next;
	penult->next = NULL;
	last->next = *stack;
	*stack = last;
}

void rra(t_data *data)
{
		write(1, "rra\n", 4);
		reverse_rotate(&data->stack_a);
}

void rrb(t_data *data)
{
		write(1, "rrb\n", 4);
		reverse_rotate(&data->stack_b);
}

void rrr(t_data *data)
{
		write(1, "rrr\n", 4);
		reverse_rotate(&data->stack_a);
		reverse_rotate(&data->stack_b);
}
