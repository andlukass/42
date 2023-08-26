/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:05:01 by user              #+#    #+#             */
/*   Updated: 2023/08/26 09:10:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	bitwise(t_data *data, t_stack *stack, int bit)
{
	int	index;
	int	length;

	index = 0;
	length = data->a_len;
	while(index < length)
	{
		if(!((stack->value >> bit) & 1))
			pb(data);
		else
			ra(data);
		stack = data->stack_a;
		index++;
	}
	length = data->b_len;
	while(length-- > 0)
		pa(data);
}

void	sort_large(t_data *data)
{
	int length;
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
		bitwise(data ,data->stack_a, bit);
		bit++;
	}
}

