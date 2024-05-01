/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:05:01 by user              #+#    #+#             */
/*   Updated: 2023/08/27 16:36:21 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	iterate_stack(t_data *data, int length, int bit, int is_stack_a)
{
	t_stack	*current;

	while (length-- > 0)
	{
		if (is_stack_a)
		{
			current = data->stack_a;
			if ((current->value >> bit) & 1)
				ra(data);
			else
				pb(data);
		}
		else
		{
			current = data->stack_b;
			if (!((current->value >> bit) & 1))
				rb(data);
			else
				pa(data);
		}
	}
}

static void	bitwise(t_data *data, int bit)
{
	iterate_stack(data, data->a_len, bit, 1);
	bit++;
	iterate_stack(data, data->b_len, bit, 0);
}

void	sort_large(t_data *data)
{
	int	length;
	int	bit;
	int	max_bit;

	max_bit = 1;
	bit = 0;
	length = data->a_len;
	while (((length / 2) > 0) && max_bit++)
		length = length / 2;
	while (bit < max_bit)
		bitwise(data, bit++);
	length = data->b_len;
	while (length-- > 0)
		pa(data);
}
