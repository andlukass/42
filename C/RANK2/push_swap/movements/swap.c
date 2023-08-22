/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:27:00 by user              #+#    #+#             */
/*   Updated: 2023/08/22 09:10:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **stack)
{
	int temp;
	t_stack *first;
	t_stack *second;

	if (stack_len(*stack) > 1)
	{
		first = *stack;
		temp = first->value;
		second = first->next;
		first->value = second->value;
		second->value = temp;
	}
}

void sa(t_data *data)
{
	swap(&data->stack_a);
}

void sb(t_data *data)
{
	swap(&data->stack_b);
}

void ss(t_data *data)
{
	swap(&data->stack_a);
	swap(&data->stack_b);
}