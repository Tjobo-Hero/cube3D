# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tvan-cit <tvan-cit@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/22 15:33:02 by tvan-cit      #+#    #+#                  #
#    Updated: 2020/04/03 16:45:52 by vancitters    ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = 	main.c get_next_line.c get_next_line_utils.c get_map_info.c \
		check_if_valid_map.c get_map.c convert_map.c \
		check_2d_array.c maze.c all_map_functions.c utils.c \
		find_wall.c draw_world.c move_player.c \
		textures.c initialize_textures.c draw_floor_and_ceiling.c \
		initialize_sprite.c sprites.c draw_sprites.c initialize_data.c textures2.c \

LIB	  =	$(subst .c,.o, $(SRC))

CC = gcc -O3 -Wall -Werror -Wextra -std=gnu99 -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit -o

all: $(NAME)

$(NAME):
	$(CC) $(NAME) $(SRC)
	
clean:
	/bin/rm -f $(LIB)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all