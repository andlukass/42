# include "so_long.h"

void init_exit(t_game *game)
{
	int index;
	int line;
	int bit;

	line = 0;
	bit = 0;

	while(game->map_splited[line])
	{
		index = 0;
		while(game->map_splited[line][index])
		{
			if(game->map_splited[line][index] == 'E')
			{	
				print_image(&game->canvas, &game->dragon, (index * 32), ((line - 1) * 32));
				game->exit_position = (line - 1) * 32;
			}
			index++;
		}
		line++;
	}
}

void init_itens(t_game *game)
{
	int index;
	int line;
	int bit;

	line = 0;
	bit = 0;

	while(game->map_splited[line])
	{
		index = 0;
		while(game->map_splited[line][index])
		{
			if(game->map_splited[line][index] == '1')
				print_image(&game->canvas, &game->fence, (index * 32), (line * 32));
			if(game->map_splited[line][index] == 'C')
				print_image(&game->canvas, &game->ball, (index * 32), (line * 32));
			index++;
		}
		line++;
	}
}

void collect_dragon_balls(char *map_letter, int *collectables)
{
	if(*map_letter == 'C')
	{
		*map_letter = '0';
		*collectables = *collectables - 1;
	}
}

void update_canva(t_game *game)
{
	print_background(&game->canvas, &game->background, game->y, game->x);
	if(game->avatar.body.y < game->exit_position)
	{	
		init_itens(game);
		print_avatar(&game->canvas, &game->avatar);
		init_exit(game);
	}
	else
	{
		init_exit(game);
		init_itens(game);
		print_avatar(&game->canvas, &game->avatar);
	}
	print_avatar(&game->canvas, &game->enemy);
}

void get_avatar_position(t_avatar *avatar)
{
	avatar->position.line = (avatar->body.y / 32) + 1;
	avatar->position.x = (avatar->body.x / 32);
}

void avatar_transform(t_game *game)
{
	if(game->time % 190 == 0)
		game->pressed = 0;
	if(game->pressed == 22 && game->ssj == 0)
	{
		set_mlx_image(&game->avatar.body, game->mlx, "img/avatar2.xpm", &game->canvas.endian);
		game->pressed = 0;
		game->ssj = 1;
	}
	if(game->pressed == 26 && game->ssj == 1)
	{
		set_mlx_image(&game->avatar.body, game->mlx, "img/avatar3.xpm", &game->canvas.endian);
		game->ssj = 2;
	}
}

int loop_hook(t_game *game)
{
	game->time++;
	get_avatar_position(&game->avatar);
	get_avatar_position(&game->enemy);

	game->enemy.closed_direction = is_closed(&game->enemy, game->enemy.position.line, game->enemy.position.x, game->map_splited);

	if(game->avatar.position.x == game->enemy.position.x &game->avatar.position.line < game->enemy.position.line && game->enemy.closed_direction != 'u')
		game->enemy.direction = 'u';
	else if(game->avatar.position.x == game->enemy.position.x &game->avatar.position.line > game->enemy.position.line && game->enemy.closed_direction != 'd')
		game->enemy.direction = 'd';
	else if(game->avatar.position.line == game->enemy.position.line && game->avatar.position.x < game->enemy.position.x && game->enemy.closed_direction != 'l')
		game->enemy.direction = 'l';
	else if(game->avatar.position.line == game->enemy.position.line && game->avatar.position.x > game->enemy.position.x && game->enemy.closed_direction != 'r')
		game->enemy.direction = 'r';
	else if(game->avatar.position.line < game->enemy.position.line && game->avatar.position.x < game->enemy.position.x && game->enemy.closed_direction != 'u')
		game->enemy.direction = 'u';
	else if(game->avatar.position.line > game->enemy.position.line && game->avatar.position.x > game->enemy.position.x && game->enemy.closed_direction != 'd')
		game->enemy.direction = 'd';
	
	if(game->enemy.closed_direction != '0')
	{
		game->enemy.direction = get_random_direction(game->time);
		game->enemy.closed_direction = '0';
	}
	
	if(game->time % 10 == 0 && game->time > 100)	
	{	
		if(game->enemy.direction == 'd')
			move_player(&game->enemy, game->enemy.position.line, game->enemy.position.x, game->map_splited, game->enemy.direction);
		if(game->enemy.direction == 'u')
			move_player(&game->enemy, game->enemy.position.line, game->enemy.position.x, game->map_splited, game->enemy.direction);
		if(game->enemy.direction == 'r')
			move_player(&game->enemy, game->enemy.position.line, game->enemy.position.x, game->map_splited, game->enemy.direction);
		if(game->enemy.direction == 'l')
			move_player(&game->enemy, game->enemy.position.line, game->enemy.position.x, game->map_splited, game->enemy.direction);
	}

	update_canva(game);
	dragon_sprite(game);
	avatar_sprite(&game->avatar ,game->time);
	collect(game);
	collect_dragon_balls(&game->map_splited[game->avatar.position.line][game->avatar.position.x] , &game->collectables);

	avatar_transform(game);

	if((game->map_splited[game->avatar.position.line][game->avatar.position.x] == 'E') && !game->collectables)
	{	
		printf("GANHOU NA TELESENA xD\n");
		exit(0);
	}
	mlx_put_image_to_window(game->mlx, game->window, game->canvas.id, 0,0);
	return (0);
}

int key_hook(int keycode,t_game *game)
{
	char **map;
	int line;
	int x;

	line = game->avatar.position.line;
	x = game->avatar.position.x;
	map = game->map_splited;
		
	//printf("total de movimentos: %d\n\n", ++game->moves);
	if(keycode == 115 || keycode == 65364) // s
		move_player(&game->avatar, line, x, map, 'd');
	if(keycode == 119 || keycode == 65362) // w
		move_player(&game->avatar, line, x, map, 'u');
	if(keycode == 100 || keycode == 65363) // d
		move_player(&game->avatar, line, x, map, 'r');
	if(keycode == 97 || keycode == 65361) // a
		move_player(&game->avatar, line, x, map, 'l');
	if(keycode == 112)
		game->pressed++;
	if(keycode == 65307)
		exit(0);

	return (keycode);
}

void init_avatar_sprite(t_avatar *avatar)
{
	avatar->sprite.x = 12;
	avatar->sprite.y = 10;
	avatar->sprite.width = 55;
	avatar->sprite.height = 55;
}

void init_images(t_game *game)
{
	game->canvas.id = mlx_new_image(game->mlx, game->x, game->y);
	game->canvas.addr = mlx_get_data_addr(game->canvas.id, &game->canvas.bits_per_pixel, &game->canvas.line_length, &game->canvas.endian);

	set_mlx_image(&game->background, game->mlx, "img/background.xpm", &game->canvas.endian);
	set_mlx_image(&game->fence, game->mlx, "img/fence.xpm", &game->canvas.endian);
	set_mlx_image(&game->ball, game->mlx, "img/ball.xpm", &game->canvas.endian);
	set_mlx_image(&game->dragon, game->mlx, "img/dragon1.xpm", &game->canvas.endian);
	set_mlx_image(&game->enemy.body, game->mlx, "img/enemy.xpm", &game->canvas.endian);
	set_mlx_image(&game->avatar.body, game->mlx, "img/avatar.xpm", &game->canvas.endian);
}

int main(int argc, char *argv[])
{
	t_game game;

	game.exit_position = 0;
	game.pressed = 0;
	game.moves = 0;
	game.time = 0;
	game.ssj = 0;
	game.map = NULL;
	printf("game %d\n", game.pressed);

	if(argc != 2 || !get_map(&game, argv[1]))
		return (0);

	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.x, game.y, "Dragon Ball da Shoppe");
	init_images(&game);

	init_avatar_sprite(&game.avatar);
	init_avatar_sprite(&game.enemy);
	game.enemy.body.x = 128;
	game.enemy.body.y = 128;
	game.enemy.direction = '0';

	mlx_loop_hook(game.mlx, loop_hook,  &game);
	mlx_hook(game.window, 02, (1L<<0),  key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}