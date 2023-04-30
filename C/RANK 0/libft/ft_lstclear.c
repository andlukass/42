/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 23:36:45 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/30 23:41:19 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *temp;
    t_list *aux;

    temp = *lst;
    while(temp->next)
    {
        aux = temp;
        del(aux);
        free(aux);
        temp = temp->next;
    }
}
