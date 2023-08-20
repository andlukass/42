/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:42:02 by user              #+#    #+#             */
/*   Updated: 2023/08/20 15:55:49 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	get_map_size(t_game *game)
{
	int	lines;

	lines = ft_strchrcnt(game->map, '\n') + 1;
	game->y = (lines * BIT_SIZE);
	game->x = (ft_strlen(game->map) / lines) * BIT_SIZE;
}

int	is_ber(char *map_name)
{
	int	name_len;

	name_len = ft_strlen(map_name) - 1;
	if (map_name[name_len] != 'r' || map_name[name_len - 1] != 'e'
		|| map_name[name_len - 2] != 'b' || map_name[name_len - 3] != '.')
	{
		write(1, "The map format must be '.ber'\n", 31);
		return (ERROR);
	}
	return (OK);
}

int	get_map(t_game *game, char *map_name)
{
	int		map_fd;
	char	*line;

	map_fd = open(map_name, O_RDONLY);
	if (map_fd <= 0 || !is_ber(map_name))
		return (ERROR);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		game->map = ft_strjoin(game->map, line);
		free(line);
	}
	game->map_splited = ft_split(game->map, '\n');
	get_map_size(game);
	return (check_map(game));
}
