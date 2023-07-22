

CFLAGS=  -I/usr/local/lib/mlx #-Wall -Wextra -Werror

NAME= myGame
SRC = main.c utils/ft_bzero.c utils/ft_split.c \
		utils/ft_strchr.c utils/ft_strjoin.c \
		utils/ft_strlen.c utils/get_next_line.c \
		utils/ft_strchrcnt.c \
		map_control/get_map.c map_control/check_map.c \
		map_control/fill_map.c movements/is_closed.c \
		movements/move_player.c movements/get_random_direction.c \
		movements/dragon_sprite.c image_control/set_mlx_image.c \
		movements/avatar_sprite.c image_control/get_pixel_canva.c \
		image_control/put_pixel_canva.c image_control/print_image.c \
		image_control/print_avatar.c image_control/print_background.c 


OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L/usr/local/lib/mlx -lmlx -lXext -lX11 -lm -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(NAME) $(OBJ)

re: clean all
