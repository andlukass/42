/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:06:42 by user              #+#    #+#             */
/*   Updated: 2023/08/15 20:50:31 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_canva(t_game *game)
{
	print_background(&game->canvas, &game->background, game->y, game->x);
	print_itens(game);
	if (game->player.body.y < game->exit_position)
	{
		print_avatar(&game->canvas, &game->player);
		print_exit(game);
	}
	else
	{
		print_exit(game);
		print_avatar(&game->canvas, &game->player);
	}
	if (game->has_enemy)
		print_avatar(&game->canvas, &game->enemy);
}

int	loop_hook(t_game *game)
{
	game->time++;
	get_avatar_position(&game->player);
	get_avatar_position(&game->enemy);
	if (game->has_enemy)
		move_enemy(game);
	update_canva(game);
	dragon_sprite(game);
	avatar_sprite(&game->player, game->time);
	collect_and_exit(game,
		&game->map_splited[game->player.position.line]
	[game->player.position.x]);
	avatar_transform(game);
	touch_enemy(game);
	mlx_put_image_to_window(game->mlx, game->window, game->canvas.id, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	int		line;
	int		x;
	char	**map;

	line = game->player.position.line;
	x = game->player.position.x;
	map = game->map_splited;
	if (keycode == 115 || keycode == 65364)
		move_player(&game->player, map, 'd');
	if (keycode == 119 || keycode == 65362)
		move_player(&game->player, map, 'u');
	if (keycode == 100 || keycode == 65363)
		move_player(&game->player, map, 'r');
	if (keycode == 97 || keycode == 65361)
		move_player(&game->player, map, 'l');
	if (keycode == 97 || keycode == 65361 || keycode == 100
		|| keycode == 65363 || keycode == 119 || keycode == 65362
		|| keycode == 115 || keycode == 65364 || keycode == 112)
		game->moves++;
	if (keycode == 112)
		game->pressed++;
	if (keycode == 65307)
		free_all(game);
	print_movements(*game, game->moves);
	return (keycode);
}

int	destroy_hook(t_game *game)
{
	free_all(game);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	init_game_vars(&game);
	if (argc != 2 || !get_map(&game, argv[1]))
	{
		write(1, "The game must receive one valid 'map'.ber\n", 43);
		free_all(&game);
	}
	game.frames = get_frames(game.map);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.x, game.y + 20,
			"Dragon Ball do AliExpress");
	init_images(&game);
	init_avatar_sprite(&game.player);
	init_avatar_sprite(&game.enemy);
	print_movements(game, game.moves);
	mlx_loop_hook(game.mlx, loop_hook, &game);
	mlx_hook(game.window, 02, (1L << 0), key_hook, &game);
	mlx_hook(game.window, 17, (1L << 2), destroy_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
