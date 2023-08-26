/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:32:39 by user              #+#    #+#             */
/*   Updated: 2023/08/25 22:36:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	value;
	
	if (stack_len(stack) <= 1)
		return (1);
	while(stack->next)
	{
		value = stack->value;
		stack = stack->next;
		if(value > stack->value)
			return (0);
	}
	return (1);
}