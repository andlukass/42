/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:14:16 by llopes-d          #+#    #+#             */
/*   Updated: 2023/08/27 17:49:23 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*temp;

	current = stack;
	while (current->next)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(current);
}
