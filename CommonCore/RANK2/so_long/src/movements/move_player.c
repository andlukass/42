/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:36:10 by user              #+#    #+#             */
/*   Updated: 2023/07/28 17:36:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_down(t_avatar *avatar, int line, int x, char **map)
{
	move_avatar_sprite(avatar, 9);
	if (map[line + 1][x] != '1' )
		avatar->body.y = avatar->body.y + BIT_SIZE;
}

static void	move_up(t_avatar *avatar, int line, int x, char **map)
{
	move_avatar_sprite(avatar, 200);
	if (map[line - 1][x] != '1')
		avatar->body.y = avatar->body.y - BIT_SIZE;
}

static void	move_rigth(t_avatar *avatar, int line, int x, char **map)
{
	move_avatar_sprite(avatar, 135);
	if (map[line][x + 1] != '1')
		avatar->body.x = avatar->body.x + BIT_SIZE;
}

static void	move_left(t_avatar *avatar, int line, int x, char **map)
{
	move_avatar_sprite(avatar, 70);
	if (map[line][x - 1] != '1')
		avatar->body.x = avatar->body.x - BIT_SIZE;
}

void	move_player(t_avatar *avatar, char **map, char dir)
{
	int	line;
	int	x;

	line = avatar->position.line;
	x = avatar->position.x;
	if (dir == 'u')
		move_up(avatar, line, x, map);
	if (dir == 'd')
		move_down(avatar, line, x, map);
	if (dir == 'l')
		move_left(avatar, line, x, map);
	if (dir == 'r')
		move_rigth(avatar, line, x, map);
}
