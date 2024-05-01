/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:54:12 by user              #+#    #+#             */
/*   Updated: 2023/08/13 14:00:14 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_length(int nb)
{
	int	length;

	length = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		length++;
	}
	return (length);
}

static void	put_str_to_window(t_game game, char *str)
{
	mlx_put_image_to_window(game.mlx, game.window,
		game.moves_canvas.id, 0, game.y + 5);
	mlx_string_put(game.mlx, game.window, (game.x / 2) - 45,
		game.y + 15, 0x00FFFFFF, str);
}

void	print_movements(t_game game, int moves)
{
	char	moves_str[50];
	char	*final_str;
	int		length;

	length = get_length(moves);
	moves_str[length] = '\0';
	if (moves == 0)
		moves_str[0] = '0';
	length--;
	while (moves > 0)
	{
		moves_str[length] = moves % 10 + '0';
		moves = moves / 10;
		length--;
	}
	if (game.x > 96)
		final_str = strdup("NUMBER OF MOVES: ");
	else
		final_str = strdup("MOVES: ");
	final_str = ft_strjoin(final_str, moves_str);
	put_str_to_window(game, final_str);
	free(final_str);
}
