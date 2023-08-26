/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:06:32 by user              #+#    #+#             */
/*   Updated: 2023/08/25 21:10:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void make_move(t_data *data, int *values, void (*move)(t_data *))
{
	int	index;
	t_stack	*current;

	if(move)
		move(data);
	index = 0;
	current = data->stack_a;
	while(current->next)
	{
		values[index] = current->value;
		current = current->next;
		index++;
	}
	values[index] = current->value;
}

void	sort_three(t_data *data)
{
	int	values[3];

	make_move(data, values, 0);
	if (values[0] > values[1] && values[0] > values[2])
		make_move(data, values, &ra);
	if ((values[2] < values[1] && values[2] < values[0]) || 
		(values[1] > values[0] && values[1] > values[2]))
		rra(data);
	if(!is_sorted(data->stack_a))
		sa(data);
}