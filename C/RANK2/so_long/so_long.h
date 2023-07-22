#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# define PLAYER_SPEED 16
# define BIT_SIZE 32


typedef struct s_image
{
	void *id;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
	int width;
	int height;
	int x;
	int y;
} t_image;

typedef struct s_avatar_sprite
{
	int x;
	int y;
	int width;
	int height;
} t_avatar_sprite;

typedef struct s_avatar_position
{
	int x;
	int line;
} t_avatar_position;

typedef struct s_avatar
{
	t_image body;
	t_avatar_sprite sprite;
	t_avatar_position position;
	char direction;
	char closed_direction;
} t_avatar;

typedef struct s_game
{
	char *map;
	char **map_splited;
	void *mlx;
	void *window;
	t_image canvas;
	t_avatar avatar;
	t_avatar enemy;
	t_image fence;
	t_image ball;
	t_image dragon;
	t_image background;
	int collectables;
	int moves;
	int exit_position;
	int pressed;
	int ssj;
	long long int time;
	int x;
	int y;
} t_game;

void print_image(t_image *canva, t_image *image, int x, int y);

void print_avatar(t_image *canva, t_avatar *avatar);

void print_background(t_image *canva, t_image *image, int y, int x);

int get_pixel_canva(t_image *image, int x, int y);

void put_pixel_canva(t_image *image, int x, int y, int color);

char get_random_direction(int time);

void dragon_sprite(t_game *game);

void avatar_sprite(t_avatar *avatar, int time);

void move_player(t_avatar *avatar, int line, int x, char **map, char dir);

int get_map(t_game *game, char *map_name);

int check_map(t_game *game);

void fill_map(t_game *game);

void set_mlx_image(t_image *image, void *mlx, char *source, int *endian);

char is_closed(t_avatar *avatar, int line, int x, char **map);

int ft_strchrcnt(char *str, char c);

char *ft_strjoin(char *s1, char *s2);

void *ft_bzero(char *s, size_t n);

char **ft_split(char const *s, char c);

int	ft_strchr(const char *s, int c);

char **ft_split(char const *s, char c);

int	ft_strlen(const char *s);

char	*get_next_line(int fd);

#endif
