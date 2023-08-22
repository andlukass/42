/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:13:20 by user              #+#    #+#             */
/*   Updated: 2023/08/21 19:20:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		stack_len(t_stack *stack)
{
	int	index;

	index = 0;
	while(stack)
	{
		stack = stack->next;
		index++;
	}
	return (index);
}

void	del_stack_first(t_stack **stack)
{
	t_stack	*current;

	if(stack_len(*stack) > 0)
	{
		current = *stack;
		*stack = current->next;
	}
}

void	add_to_stack_last(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	if(*stack)
	{
		current = *stack;
		while(current->next)
			current = current->next;
		current->next = new;
	}
	else
		*stack = new;
}

void	add_to_stack_first(t_stack **stack, t_stack *new)
{
	if(*stack)
		new->next = *stack;
	*stack = new;
}

t_stack	*new_stack_value(int value)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}