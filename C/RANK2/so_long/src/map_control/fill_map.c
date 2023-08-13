/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:41:51 by user              #+#    #+#             */
/*   Updated: 2023/08/13 14:03:19 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	fill_avatar(t_avatar *avatar, int x, int y)
{
	avatar->body.x = (x * BIT_SIZE);
	avatar->body.y = ((y - 1) * BIT_SIZE) + 10;
}

void	fill_map(t_game *game)
{
	int	line;
	int	x;

	line = 0;
	game->collectables = 0;
	while (game->map_splited[++line])
	{
		x = 0;
		while (game->map_splited[line][x])
		{
			if (game->map_splited[line][x] == 'P')
				fill_avatar(&game->player, x, line);
			if (game->map_splited[line][x] == 'B')
			{
				game->has_enemy = 1;
				fill_avatar(&game->enemy, x, line);
			}
			if (game->map_splited[line][x++] == 'C')
				game->collectables++;
		}
	}
	if (!game->has_enemy)
		fill_avatar(&game->enemy, 0, 0);
}
