#include "../so_long.h"

static void get_map_size(t_game *game)
{
	int index;
	int lines;
	lines = ft_strchrcnt(game->map, '\n') + 1;
	game->y = lines * BIT_SIZE;
	game->x = (ft_strlen(game->map) / lines) * BIT_SIZE;
}

int get_map(t_game *game, char *map_name)
{
	int map_fd;
	char *line;

	map_fd = open(map_name, O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(map_fd);
		if(line == NULL)
			break;
		game->map = ft_strjoin(game->map, line);
	}
	free(line);
	game->map_splited = ft_split(game->map, '\n');
	get_map_size(game);
	return (check_map(game));
}