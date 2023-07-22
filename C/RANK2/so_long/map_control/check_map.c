#include "../so_long.h"

static int is_retangular(char **map)
{
	int i;
	int j;
	int length;

	i = 0;
	length = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
			j++;
		if(i != 0 && length != j)
			return (0);
		length = j;
		i++;
	}
	if(i >= j)
		return (0);
	return (1);
}

static int has_walls(char **map)
{
	int i;
	int j;
	int length;

	i = 0;
	while(map[0][i])
		if(map[0][i++] != '1')
			return (0);
	length = i - 1;
	i = 0;
	while(map[i])
		if(map[i++][length] != '1')
			return (0);
	i = 0;
	while(map[i])
		if(map[i++][0] != '1')
			return (0);
	length = i - 1;
	i = 0;
	while(map[length][i])
		if(map[length][i++] != '1')
			return (0);
	return (1);
}

static int is_complete(char* map)
{
	int index;

	index = 0;
	while(map[index])
	{
		if(map[index] != 'E' && map[index] != 'P' &&
			map[index] != 'C' && map[index] != '0' &&
			map[index] != '1' && map[index] != '\n')
			return (0);
		index++;
	}
	return (1);
}

static int has_positions(char *map)
{
	int count;

	count = ft_strchrcnt(map, 'E');
	if(count == 0 || count > 1)
		return (0);

	count = ft_strchrcnt(map, 'P');
	if(count == 0 || count > 1)
		return (0);

	count = ft_strchrcnt(map, 'C');
	if(count == 0)
		return (0);
	if(!is_complete(map))
		return (0);
	return (1);
}

int check_map(t_game *game)
{
	if(!is_retangular(game->map_splited) ||
		!has_walls(game->map_splited) ||
		!has_positions(game->map))
		return (0);
	fill_map(game);
	return (1);
}