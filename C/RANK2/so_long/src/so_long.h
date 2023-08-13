/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:31:57 by user              #+#    #+#             */
/*   Updated: 2023/08/13 16:38:55 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

# define BIT_SIZE 32
# define ERROR 0
# define OK 1

typedef struct s_image
{
	void	*id;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_image;

typedef struct s_avatar_sprite
{
	int		x;
	int		y;
	int		width;
	int		height;
}	t_avatar_sprite;

typedef struct s_avatar_position
{
	int		x;
	int		line;
}	t_avatar_position;

typedef struct s_avatar
{
	char				closed_direction;
	char				direction;
	t_image				body;
	t_avatar_sprite		sprite;
	t_avatar_position	position;
}	t_avatar;

typedef struct s_game
{
	long long int	time;
	int				exit_position;
	int				enemy_blocked;
	int				collectables;
	int				has_enemy;
	int				pressed;
	int				frames;
	int				moves;
	int				ssj;
	int				x;
	int				y;
	void			*window;
	void			*mlx;
	char			**map_splited;
	char			*map;
	t_avatar		player;
	t_avatar		enemy;
	t_image			moves_canvas;
	t_image			background;
	t_image			dragon;
	t_image			canvas;
	t_image			fence;
	t_image			ball;
}	t_game;

/*--------------------- IMAGES ------------------------*/
void	set_mlx_image(t_image *image, void *mlx, char *source, int *endian);
void	move_avatar_sprite(t_avatar *avatar, int initial);
void	print_background(t_image *canva, t_image *image, int y, int x);
void	print_image(t_image *canva, t_image *image, int x, int y);
void	put_pixel_canva(t_image *image, int x, int y, int pixel);
void	print_avatar(t_image *canva, t_avatar *avatar);
void	print_movements(t_game game, int moves);
void	destroy_images(t_game *game);
void	init_images(t_game *game);
void	print_itens(t_game *game);
void	print_exit(t_game *game);
int		get_pixel_canva(t_image *image, int x, int y);
/*-----------------------------------------------------*/
/*--------------------- MAP ---------------------------*/
void	fill_map(t_game *game);
void	get_avatar_position(t_avatar *avatar);
int		check_path(t_game game, int x, int line);
int		get_map(t_game *game, char	*map_name);
int		check_map(t_game *game);
/*-----------------------------------------------------*/
/*--------------------- MOVEMENTS ---------------------*/
void	move_player(t_avatar *avatar, char **map, char dir);
void	avatar_sprite(t_avatar *avatar, int time);
char	is_closed(t_avatar *avatar, char **map);
void	init_avatar_sprite(t_avatar *avatar);
void	dragon_sprite(t_game *game);
void	move_enemy(t_game *game);
int		get_frames(char *map);
/*-----------------------------------------------------*/
/*--------------------- UTILS -------------------------*/
char	**ft_split(char const *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strchrcnt(char *str, char c);
int		ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
void	*ft_bzero(char *s, size_t n);
void	ft_free_array(char **array);
/*-----------------------------------------------------*/
/*--------------------- GAME --------------------------*/
void	collect_and_exit(t_game *game, char *map_letter);
void	avatar_transform(t_game *game);
void	init_game_vars(t_game *game);
void	touch_enemy(t_game *game);
void	free_all(t_game *game);
/*------------------------------------------------------*/

#endif
