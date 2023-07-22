#include "../so_long.h"

static void fill_collectables(t_game *game)
{

}

static void fill_exit(t_game *game)
{

}

static void fill_player(t_avatar *avatar, int x, int y)
{
	avatar->body.x = (x * BIT_SIZE);
	avatar->body.y = ((y - 1) * BIT_SIZE);
}


void fill_map(t_game *game)
{
	//fill_collectables(game);
	//fill_exit(game);
	int line;
	int x;

	line = 0;
	game->collectables = 0;
	while(game->map_splited[line])
	{
		x = 0;
		while(game->map_splited[line][x])
		{
			if(game->map_splited[line][x] == 'P')
				fill_player(&game->avatar, x, line);
			if(game->map_splited[line][x] == 'C')
				game->collectables++;
			x++;
		}
		line++;
	}
}