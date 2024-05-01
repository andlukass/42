/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:03:20 by user              #+#    #+#             */
/*   Updated: 2023/08/13 19:27:52 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	print_loose(void)
{
	write(1, "	___  _ ____  _       _     ____  ____  ____  _____ \n \
	\\  \\///  _ \\/ \\ /\\  / \\   /  _ \\/  _ \\/ ___\\/  __/ \n \
	 \\  / | / \\|| | ||  | |   | / \\|| / \\|| _ \\|  \\ \n \
	 / /  | \\_/|| \\_/|  | |_/\\| \\_/|| \\_/|\\___ ||  /_ \n \
	/_/   \\____/\\____/  \\____/\\____/\\____/\\____/\\____\\ \n\n", 267);
}

static void	print_win(void)
{
	write(1, "	___  _ ____  _       _      _  _  \n \
	\\  \\///  _ \\/ \\ /\\  / \\  /|/ \\/ \\  /| \n \
	 \\  / | / \\|| | ||  | |  ||| || |\\ || \n \
	 / /  | \\_/|| \\_/|  | |/\\||| || | \\|| \n \
	/_/   \\____/\\____/  \\_/  \\|\\_/\\_/  \\| \n\n", 202);
}

void	collect_and_exit(t_game *game, char *map_letter)
{
	if (*map_letter == 'C')
	{
		*map_letter = '0';
		game->collectables = game->collectables - 1;
	}
	if (*map_letter == 'E' && !game->collectables)
	{
		print_win();
		free_all(game);
	}
}

void	avatar_transform(t_game *game)
{
	if (game->frames % 500 == 0)
		game->pressed = 0;
	if (game->pressed == 100 && game->ssj == 0)
	{
		mlx_destroy_image(game->mlx, game->player.body.id);
		set_mlx_image(&game->player.body, game->mlx,
			"src/img/avatar2.xpm", &game->canvas.endian);
		game->pressed = 0;
		game->ssj = 1;
	}
	if (game->pressed == 200 && game->ssj == 1)
	{
		mlx_destroy_image(game->mlx, game->player.body.id);
		set_mlx_image(&game->player.body, game->mlx,
			"src/img/avatar3.xpm", &game->canvas.endian);
		game->ssj = 2;
	}
}

void	touch_enemy(t_game *game)
{
	if ((game->player.position.line == game->enemy.position.line)
		&& (game->player.position.x == game->enemy.position.x))
	{
		if (game->ssj == 2)
		{
			mlx_destroy_image(game->mlx, game->enemy.body.id);
			set_mlx_image(&game->enemy.body, game->mlx,
				"src/img/transparent.xpm", &game->canvas.endian);
			return ;
		}
		print_loose();
		free_all(game);
	}
}
