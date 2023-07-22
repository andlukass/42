#include "../so_long.h"

void dragon_sprite(t_game *game)
{
	if(game->time % 20 == 0)
	{
		if(!game->collectables)
			set_mlx_image(&game->dragon, game->mlx, "img/dragon3.xpm", &game->canvas.endian);
		else
			set_mlx_image(&game->dragon, game->mlx, "img/dragon1.xpm", &game->canvas.endian);
	}
	if(game->time % 40 == 0)
	{
		set_mlx_image(&game->dragon, game->mlx, "img/dragon2.xpm", &game->canvas.endian);
	}
}