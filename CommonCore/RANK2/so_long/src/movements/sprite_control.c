/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:27:27 by user              #+#    #+#             */
/*   Updated: 2023/08/13 19:28:12 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_avatar_sprite(t_avatar *avatar)
{
	avatar->sprite.x = 12;
	avatar->sprite.y = 10;
	avatar->sprite.width = 55;
	avatar->sprite.height = 55;
}

void	avatar_sprite(t_avatar *avatar, int time)
{
	if (time % 100 == 0)
		avatar->sprite.x = 12;
}

void	dragon_sprite(t_game *game)
{
	if (game->time % (game->frames / 2) == 0)
	{
		if (!game->collectables)
		{
			mlx_destroy_image(game->mlx, game->dragon.id);
			set_mlx_image(&game->dragon, game->mlx,
				"src/img/dragon3.xpm", &game->canvas.endian);
		}
		else
		{
			mlx_destroy_image(game->mlx, game->dragon.id);
			set_mlx_image(&game->dragon, game->mlx,
				"src/img/dragon1.xpm", &game->canvas.endian);
		}
	}
	if (game->time % game->frames == 0)
	{
		mlx_destroy_image(game->mlx, game->dragon.id);
		set_mlx_image(&game->dragon, game->mlx,
			"src/img/dragon2.xpm", &game->canvas.endian);
	}
}

void	move_avatar_sprite(t_avatar *avatar, int initial)
{
	avatar->sprite.y = initial;
	avatar->sprite.x = avatar->sprite.x + 64;
	if (avatar->sprite.x > 400)
		avatar->sprite.x = 10;
}
