# include "so_long.h"

int control = 0;

int key_hook(int keycode,t_game *param)
{
	control = keycode;
	printf("tecla digitada: %d\n", keycode);
	printf("\n");
	// if(control == 115)
	// {

	// }
	// if(control == 119)
	// {

	// }
	// if(control == 100)
	// {

	// }
	// if(control == 97)
	// {

	// }
}

int loop_hook(t_game *param)
{
	// usleep(50000);
	// if(control == 100)
	// 	mlx_put_image_to_window(param->mlx, param->win, param->boneco.paradodir, param->x, param->y);
	// if(control == 97)
	// 	mlx_put_image_to_window(param->mlx, param->win, param->boneco.paradoesq, param->x, param->y);
	// if(control == 115)
	// 	mlx_put_image_to_window(param->mlx, param->win, param->boneco.paradob, param->x, param->y);
	// if(control == 119)
	// 	mlx_put_image_to_window(param->mlx, param->win, param->boneco.paradoc, param->x, param->y);
	mlx_put_image_to_window(param->mlx, param->window, param->canvas.img, 0,0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	return *(unsigned int*) (data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)));
}

void print_image(t_data *canva, t_data *data, int x, int y)
{
	int indexX;
	int indexY;

	indexY = 0;
	while(indexY < data->height)
	{	
		indexX = 0;
		while(indexX < data->width)
		{
			my_mlx_pixel_put(canva, (x + indexX), (y + indexY), my_mlx_pixel_get(data, indexX, indexY));
			indexX++;
		}
		indexY++;
	}

}

void print_image_sub(t_data *canva, t_data *data, int x, int y, int sx, int  sy, int sw, int sh)
{
	int indexX;
	int indexY;

	indexY = 0;
	while(indexY < sh)
	{	
		indexX = 0;
		while(indexX < sw)
		{
			if(my_mlx_pixel_get(data, sx + indexX, sy + indexY) != -16777216)
				my_mlx_pixel_put(canva, (x + indexX), (y + indexY), my_mlx_pixel_get(data, sx + indexX, sy + indexY));
			indexX++;
		}
		indexY++;
	}

}

void print_background(t_data *canva, t_data *data)
{
	int indexY;
	int indexX;

	indexY = 0;
	while(indexY < 320)
	{
		indexX = 0;
		while(indexX < 320)
		{
			print_image(canva, data, indexY, indexX);
			indexX = indexX + 32;
		}
		indexY = indexY + 32;
	}
}


int main()
{
	t_game game;
	int size = 20;

	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 320, 320, "teste");
	game.canvas.img = mlx_new_image(game.mlx, 320, 320);
	game.canvas.addr = mlx_get_data_addr(game.canvas.img, &game.canvas.bits_per_pixel, &game.canvas.line_length, &game.canvas.endian);

	game.background.img = mlx_xpm_file_to_image(game.mlx, "background.xpm", &game.background.width, &game.background.height);
	game.background.addr = mlx_get_data_addr(game.background.img, &game.background.bits_per_pixel, &game.background.line_length, &game.canvas.endian);

	game.boneco.img = mlx_xpm_file_to_image(game.mlx, "full.xpm", &game.boneco.width, &game.boneco.height);
	game.boneco.addr = mlx_get_data_addr(game.boneco.img, &game.boneco.bits_per_pixel, &game.boneco.line_length, &game.boneco.endian);

	print_background(&game.canvas, &game.background);
	print_image_sub(&game.canvas, &game.boneco, 20, 20, 10, 10, 40, 55);

	printf("%d\n\n", my_mlx_pixel_get(&game.boneco, 1 , 1));

	mlx_loop_hook(game.mlx, loop_hook,  &game);
	mlx_hook(game.window, 02, (1L<<0),  key_hook, &game);
	// mlx_key_hook(game.window, key_hook, &game);
	mlx_loop(game.mlx);
}


//W = 119
//a = 97
//s = 115
//d = 100
