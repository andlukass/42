/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:05:01 by user              #+#    #+#             */
/*   Updated: 2023/08/27 09:32:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	have_bit_zero(t_stack *stack, int bit)
{
	while(stack->next)
	{
		if((stack->value >> bit) & 0)
			return (1);
		stack = stack->next;
	}
	if((stack->value >> bit) & 0)
			return (1);
	return (0);
}

static int	have_bit_one(t_stack *stack, int bit)
{
	while(stack->next)
	{
		// if((stack->value >> bit) & 1)
		// 	return (1); 
		stack = stack->next;
	}
	if((stack->value >> bit) & 1)
			return (1);
	return (0);
}

static void	bitwise(t_data *data, int bit, int max_bit)
{
	int		index;
	int		length;
	int		teste;
	t_stack	*current;

	index = 0;
	length = data->a_len;
	current = data->stack_a;
	while(index < length)
	{
		if ((current->value >> bit) & 1)
			ra(data);
		else
			pb(data);
		current = data->stack_a;
		index++;
	}
	bit++;
	length = data->b_len;
	while(length-- > 0)
	{
		if ((current->value >> bit) & 0)
			rb(data);
		else
			pa(data);
		current = data->stack_b;
	}
}

void	sort_large(t_data *data)
{
	int	length;
	int	bit;
	int	max_bit;

	max_bit = 1;
	bit = 0;
	length = data->a_len;
	while((length / 2) > 0)
	{
		max_bit++;
		length = length / 2;
	}
	while(bit < max_bit)
	{
		bitwise(data, bit,max_bit);
		bit++;
	}

	length = data->b_len;
	while(length-- > 0)
		pa(data);
}

