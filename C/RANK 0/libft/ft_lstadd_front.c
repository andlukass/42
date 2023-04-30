/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:58:30 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/30 23:05:27 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->content = content;
	new->next = NULL;
	return (new);
}*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
		new->next = *lst;
	*lst = new;
}

/*
int main(void)
{
    // Cria uma lista vazia
    t_list *my_list = NULL;
    
    // Adiciona o elemento 1 no início da lista
    t_list *new_element = ft_lstnew("Elemento 1");
    ft_lstadd_front(&my_list, new_element);
    
    // Adiciona o elemento 2 no início da lista
    new_element = ft_lstnew("Elemento 2");
    ft_lstadd_front(&my_list, new_element);
    
    // Adiciona o elemento 3 no início da lista
    new_element = ft_lstnew("Elemento 3");
    ft_lstadd_front(&my_list, new_element);
    
    // Imprime a lista
    t_list *current_element = my_list;
    while (current_element != NULL)
    {
        printf("%s\n", (char*)current_element->content);
        current_element = current_element->next;
    }
    
    return 0;
}*/