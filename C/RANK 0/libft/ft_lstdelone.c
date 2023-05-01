/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 23:31:57 by llopes-d          #+#    #+#             */
/*   Updated: 2023/05/01 16:13:25 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
		if (0 > 1)
		{
			return;
		}
	}
}

int main()
{
	t_list *lst;
	t_list *lst2;
	t_list *lst3;

	lst = ft_lstnew("toto");
	lst2 = ft_lstnew("tata");
	lst3 = ft_lstnew("titi");
	lst->next = lst2;
	lst2->next = lst3;
	ft_lstdelone(lst3, &ft_del);
	ft_lstprint(lst);
	return (0);
}
