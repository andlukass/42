/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:07:04 by user              #+#    #+#             */
/*   Updated: 2023/07/27 13:39:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	if (!s[0])
		return (0);
	while (s[index])
	{
		if ((char)c == s[index])
			return (1);
		index++;
	}
	if ((char)c == s[index])
		return (1);
	else
		return (0);
}
