#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx.h"
#include <stdio.h>

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_data {
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
	int width;
	int height;
} t_data;

typedef struct s_game
{

	void *mlx;
	void *window;
	t_data canvas;
	t_data background;
	t_data boneco;
	int y;
	int x;

} t_game;





#endif
