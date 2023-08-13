/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:06:49 by user              #+#    #+#             */
/*   Updated: 2023/07/27 13:38:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_bzero(char *s, size_t n)
{
	size_t	index;

	if (!s[0])
		return (NULL);
	index = 0;
	while (index < n)
		s[index++] = '\0';
	return (NULL);
}
