# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tvan-cit <tvan-cit@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/22 15:33:02 by tvan-cit      #+#    #+#                  #
#    Updated: 2020/04/25 08:38:55 by vancitters    ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 	= 	cub3D
MLX 	= 	libmlx.dylib

SRC		= 	main.c get_next_line.c get_next_line_utils.c get_map_info.c \
			check_if_valid_info.c get_map.c check_if_valid_map.c \
			check_2d_array.c maze.c all_map_functions.c utils.c \
			find_wall.c draw_world.c move_player.c \
			textures.c initialize_textures.c draw_floor_and_ceiling.c \
			initialize_sprite.c sprites.c draw_sprites.c initialize_data.c \
			textures2.c export_bmp.c utils_initialize.c utils_map_info.c \
			utils_map.c utils_ray.c utils_color_info.c utils_color_info2.c \
			utils_resolution_info.c utils_sprite.c utils_player_move.c utils_initialize_struct_data.c \

LIB	 	=	$(subst .c,.o, $(SRC))
SRC2	=	$(addprefix mandatory_files/,$(SRC))

CC = 		gcc -O3 -g -Wall -Werror -Wextra -std=gnu99 -I minilibx -L minilibx \
			-lmlx -framework OpenGL -framework AppKit -o \

all: $(NAME)

$(MLX):
			# make -C minilibx
			# cp -r minilibx/$(MLX) .

$(NAME): $(MLX)
	$(CC) $(NAME) $(SRC2)

clean:
			# make -C minilibx clean
			/bin/rm -f $(LIB)
			# /bin/rm -f $(MLX)
			/bin/rm -f screenshot.bmp

fclean: clean
			/bin/rm -f $(NAME)

re: fclean all
