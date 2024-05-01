/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:27:00 by user              #+#    #+#             */
/*   Updated: 2023/08/27 15:10:59 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **stack, int length, char *move)
{
	int		temp;
	t_stack	*first;
	t_stack	*second;

	if (length < 2)
		return ;
	first = *stack;
	temp = first->value;
	second = first->next;
	first->value = second->value;
	second->value = temp;
	write(1, move, 3);
}

void	sa(t_data *data)
{
	swap(&data->stack_a, data->a_len, "sa\n");
}

void	sb(t_data *data)
{
	swap(&data->stack_b, data->b_len, "sb\n");
}

void	ss(t_data *data)
{
	if (data->a_len > 1 && data->b_len > 1)
	{
		swap(&data->stack_a, data->a_len, "\0\0\0");
		swap(&data->stack_b, data->b_len, "ss\n");
	}
}
