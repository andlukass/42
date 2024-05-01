/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:50:16 by llopes-d          #+#    #+#             */
/*   Updated: 2023/08/13 19:27:24 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->background.id);
	mlx_destroy_image(game->mlx, game->player.body.id);
	mlx_destroy_image(game->mlx, game->enemy.body.id);
	mlx_destroy_image(game->mlx, game->dragon.id);
	mlx_destroy_image(game->mlx, game->ball.id);
	mlx_destroy_image(game->mlx, game->fence.id);
	mlx_destroy_image(game->mlx, game->moves_canvas.id);
	mlx_destroy_image(game->mlx, game->canvas.id);
}

void	init_images(t_game *game)
{
	game->canvas.id = mlx_new_image(game->mlx, game->x, game->y);
	game->canvas.addr = mlx_get_data_addr(game->canvas.id,
			&game->canvas.bits_per_pixel, &game->canvas.line_length,
			&game->canvas.endian);
	game->moves_canvas.id = mlx_new_image(game->mlx, game->x, 20);
	game->moves_canvas.addr = mlx_get_data_addr(game->moves_canvas.id,
			&game->moves_canvas.bits_per_pixel, &game->moves_canvas.line_length,
			&game->moves_canvas.endian);
	set_mlx_image(&game->background, game->mlx, "src/img/background.xpm",
		&game->canvas.endian);
	set_mlx_image(&game->fence, game->mlx, "src/img/fence.xpm",
		&game->canvas.endian);
	set_mlx_image(&game->ball, game->mlx, "src/img/ball.xpm",
		&game->canvas.endian);
	set_mlx_image(&game->dragon, game->mlx, "src/img/dragon1.xpm",
		&game->canvas.endian);
	set_mlx_image(&game->enemy.body, game->mlx, "src/img/enemy.xpm",
		&game->canvas.endian);
	set_mlx_image(&game->player.body, game->mlx, "src/img/avatar.xpm",
		&game->canvas.endian);
}
