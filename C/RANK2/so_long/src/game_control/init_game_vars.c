/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:43:23 by llopes-d          #+#    #+#             */
/*   Updated: 2023/08/13 16:24:36 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_game_vars(t_game *game)
{
	game->exit_position = 0;
	game->enemy_blocked = 0;
	game->has_enemy = 0;
	game->pressed = 0;
	game->moves = 0;
	game->time = 0;
	game->ssj = 0;
	game->map = NULL;
}
