/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:33:54 by user              #+#    #+#             */
/*   Updated: 2023/08/13 14:00:46 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_background(t_image *canva, t_image *image, int y, int x)
{
	int	index_y;
	int	index_x;

	index_y = 0;
	while (index_y < y)
	{
		index_x = 0;
		while (index_x < x)
		{
			print_image(canva, image, index_x, index_y);
			index_x = index_x + BIT_SIZE;
		}
		index_y = index_y + BIT_SIZE;
	}
}

void	print_itens(t_game *game)
{
	int	index;
	int	line;
	int	bit;

	line = 0;
	bit = 0;
	while (game->map_splited[line])
	{
		index = 0;
		while (game->map_splited[line][index])
		{
			if (game->map_splited[line][index] == '1')
				print_image(&game->canvas, &game->fence, (index * BIT_SIZE),
					(line * BIT_SIZE));
			if (game->map_splited[line][index] == 'C')
				print_image(&game->canvas, &game->ball, (index * BIT_SIZE),
					(line * BIT_SIZE));
			index++;
		}
		line++;
	}
}

void	print_exit(t_game *game)
{
	int	index;
	int	line;

	line = 0;
	while (game->map_splited[line])
	{
		index = 0;
		while (game->map_splited[line][index])
		{
			if (game->map_splited[line][index] == 'E')
			{
				print_image(&game->canvas, &game->dragon,
					(index * BIT_SIZE), ((line - 1) * BIT_SIZE));
				game->exit_position = (line - 1) * BIT_SIZE;
			}
			index++;
		}
		line++;
	}
}

void	print_avatar(t_image *canva, t_avatar *avatar)
{
	int	index_x;
	int	index_y;

	index_y = 0;
	while (index_y < avatar->sprite.height)
	{
		index_x = 0;
		while (index_x < avatar->sprite.width)
		{
			if (get_pixel_canva(&avatar->body, avatar->sprite.x + index_x,
					avatar->sprite.y + index_y) != -16777216)
			{
				put_pixel_canva(canva, (avatar->body.x + index_x),
					(avatar->body.y + index_y),
					get_pixel_canva(&avatar->body, avatar->sprite.x + index_x,
						avatar->sprite.y + index_y));
			}
			index_x++;
		}
		index_y++;
	}
}
