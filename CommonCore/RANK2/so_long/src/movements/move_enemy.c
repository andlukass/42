/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:50:12 by user              #+#    #+#             */
/*   Updated: 2023/08/13 17:02:51 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	get_random_dir(int number)
{
	int	random;

	random = number % 4;
	if (random == 0)
		return ('d');
	if (random == 1)
		return ('l');
	if (random == 2)
		return ('r');
	if (random == 3)
		return ('u');
	return ('0');
}

static char	seek_player(t_avatar enemy, int p_x, int p_line, char random)
{
	int	e_x;
	int	e_line;

	e_x = enemy.position.x;
	e_line = enemy.position.line;
	if (enemy.closed_direction != '0')
		return (random);
	else if (p_line < e_line)
		return ('u');
	else if (p_line > e_line)
		return ('d');
	else if (p_x > e_x)
		return ('r');
	else if (p_x < e_x)
		return ('l');
	return (random);
}

void	move_enemy(t_game *game)
{
	int		random;

	random = get_random_dir(game->enemy_blocked + game->moves);
	game->enemy.closed_direction = is_closed(&game->enemy, game->map_splited);
	game->enemy.direction = seek_player(game->enemy,
			game->player.position.x, game->player.position.line, random);
	if (game->enemy.closed_direction != '0')
		game->enemy_blocked++;
	if ((game->time % game->frames == 0))
		move_player(&game->enemy, game->map_splited, game->enemy.direction);
}
