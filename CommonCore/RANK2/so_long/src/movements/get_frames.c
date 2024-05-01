/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frames.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:00:47 by user              #+#    #+#             */
/*   Updated: 2023/08/13 19:29:22 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_frames(char *map)
{
	int	map_len;

	map_len = ft_strlen(map);
	if (map_len <= 50)
		return (300);
	else if (map_len <= 200 && map_len > 50)
		return (200);
	else if (map_len <= 1000 && map_len > 200)
		return (80);
	else 
		return (20);
}
