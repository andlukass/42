/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:27:00 by user              #+#    #+#             */
/*   Updated: 2023/08/22 19:24:11 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **stack)
{
	int temp;
	int	length;
	t_stack *first;
	t_stack *second;

	length = stack_len(*stack);
	if (length < 2)
		return ;
	first = *stack;
	temp = first->value;
	second = first->next;
	first->value = second->value;
	second->value = temp;
}

void sa(t_data *data)
{
		write(1, "sa\n", 3);
		swap(&data->stack_a);
}

void sb(t_data *data)
{
		write(1, "sb\n", 3);
		swap(&data->stack_b);
}

void ss(t_data *data)
{
		write(1, "ss\n", 3);
		swap(&data->stack_a);
		swap(&data->stack_b);
}
