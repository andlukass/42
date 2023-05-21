/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 23:13:16 by llopes-d          #+#    #+#             */
/*   Updated: 2023/05/21 17:11:04 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	//t_list	*temp;

// 	//temp = *lst;
// 	if (*lst)
// 	{
// 		while ((*lst)->next)
// 			*lst = (*lst)->next;
// 		(*lst)->next = new;
// 	}
// 	else
// 		*lst = new;
// }

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (*lst)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*lst = new;
}
