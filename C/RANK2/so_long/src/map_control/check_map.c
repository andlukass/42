/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:41:56 by user              #+#    #+#             */
/*   Updated: 2023/08/13 14:01:23 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_retangular(char **map)
{
	int	length;
	int	i;
	int	j;

	i = 0;
	length = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (i != 0 && length != j)
			return (ERROR);
		length = j;
		i++;
	}
	return (OK);
}

static int	has_walls(char **map)
{
	int	i;
	int	length;

	i = 0;
	while (map[0][i])
		if (map[0][i++] != '1')
			return (ERROR);
	length = i - 1;
	i = 0;
	while (map[i])
		if (map[i++][length] != '1')
			return (ERROR);
	i = 0;
	while (map[i])
		if (map[i++][0] != '1')
			return (ERROR);
	length = i - 1;
	i = 0;
	while (map[length][i])
		if (map[length][i++] != '1')
			return (ERROR);
	return (OK);
}

static int	is_complete(char *map)
{
	int	index;

	index = 0;
	while (map[index])
	{
		if (map[index] != 'E' && map[index] != 'P'
			&& map[index] != 'C' && map[index] != '0'
			&& map[index] != '1' && map[index] != 'B'
			&& map[index] != '\n')
			return (ERROR);
		index++;
	}
	index = 0;
	while (map[index])
	{
		if (map[index] == '\n' && map[index + 1] == '\n')
			return (ERROR);
		index++;
	}
	if (map[index - 1] == '\n' || map[0] == '\n')
		return (ERROR);
	return (OK);
}

static int	has_positions(char *map)
{
	int	count;

	count = ft_strchrcnt(map, 'E');
	if (count == 0 || count > 1)
		return (ERROR);
	count = ft_strchrcnt(map, 'P');
	if (count == 0 || count > 1)
		return (ERROR);
	count = ft_strchrcnt(map, 'B');
	if (count > 1)
		return (ERROR);
	count = ft_strchrcnt(map, 'C');
	if (count == 0)
		return (ERROR);
	if (!is_complete(map))
		return (ERROR);
	return (OK);
}

int	check_map(t_game *game)
{
	if (!is_retangular(game->map_splited)
		|| !has_walls(game->map_splited)
		|| !has_positions(game->map))
	{
		write(1, "Map Error\n", 11);
		return (ERROR);
	}
	fill_map(game);
	if (!check_path(*game, game->player.body.x,
			game->player.body.y))
	{
		write(1, "Map must have a valid path\n", 28);
		return (ERROR);
	}
	return (OK);
}
