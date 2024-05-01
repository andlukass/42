GREEN := \033[32m
RED := \033[31m
END := \033[0m

NAME= so_long

SRC = src/main.c \
		src/utils/ft_bzero.c src/utils/ft_split.c src/utils/ft_strchr.c\
		src/utils/ft_strjoin.c src/utils/ft_strchrcnt.c \
		src/utils/ft_strlen.c src/utils/get_next_line.c \
		src/utils/ft_free_array.c \
		src/map_control/get_map.c src/map_control/check_map.c \
		src/map_control/fill_map.c src/map_control/get_avatar_position.c \
		src/map_control/check_path.c \
		src/movements/is_closed.c src/movements/get_frames.c \
		src/movements/move_player.c src/movements/move_enemy.c \
		src/movements/sprite_control.c \
		src/image_control/set_mlx_image.c src/image_control/pixel_control.c \
		src/image_control/print_image.c src/image_control/print_map.c \
		src/image_control/image_control.c src/image_control/print_movements.c \
		src/game_control/game_control.c src/game_control/free_all.c\
		src/game_control/init_game_vars.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -Wall -Wextra -Werror $(OBJ) -L.mlx -lmlx -I.mlx  -lXext -lX11 -lm -lz -o $(NAME)
	@echo "\n$(GREEN)> Compilation done!🎉\n$(END)"

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -I.mlx  -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@echo "\n$(RED)> Cleaned! 🗑️\n$(END)"

fclean:
	@rm -rf $(NAME) $(OBJ)
	@echo "\n$(RED)> All cleaned! 🗑️\n$(END)"

re: clean all
