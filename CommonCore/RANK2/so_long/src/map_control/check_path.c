/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 09:11:05 by user              #+#    #+#             */
/*   Updated: 2023/08/13 14:43:22 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

typedef struct s_map
{
	int		collectables;
	int		flag;
	char	**map;
}	t_map;

static void	dfs(t_map *map, int x, int line)
{
	if (map->flag && map->collectables == 0)
		return ;
	if (map->map[line][x] == '1' || map->map[line][x] == 'P')
		return ;
	if (map->map[line][x] == 'C')
		map->collectables = map->collectables - 1;
	if (map->map[line][x] == '0' || map->map[line][x] == 'C' ||
		map->map[line][x] == 'B')
		map->map[line][x] = 'P';
	if (map->map[line][x] == 'E')
		map->flag = map->flag + 1;
	dfs(map, x + 1, line);
	dfs(map, x - 1, line);
	dfs(map, x, line + 1);
	dfs(map, x, line - 1);
}

int	check_path(t_game game, int x, int line)
{
	t_map	map;

	map.map = ft_split(game.map, '\n');
	map.collectables = game.collectables;
	map.flag = 0;
	x = x / BIT_SIZE;
	line = ((line - 10) / BIT_SIZE) + 1;
	dfs(&map, x + 1, line);
	dfs(&map, x - 1, line);
	dfs(&map, x, line + 1);
	dfs(&map, x, line - 1);
	ft_free_array(map.map);
	if (map.flag && map.collectables == 0)
		return (OK);
	else
		return (ERROR);
}
