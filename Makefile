# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tvan-cit <tvan-cit@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/22 15:33:02 by tvan-cit       #+#    #+#                 #
#    Updated: 2020/03/23 12:19:19 by tim           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = 	main.c get_next_line.c get_next_line_utils.c get_map_info.c \
		check_if_valid_map.c get_map.c convert_map.c \
		check_2d_array.c maze.c all_map_functions.c utils.c \
		find_wall.c draw_world.c move_player.c \
		textures.c initialize_textures.c draw_floor_and_ceiling.c \
		initialize_sprite.c sprites.c \

LIB	  =	$(subst .c,.o, $(SRC))

CC = gcc -Wall -Werror -Wextra -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit -o

all: $(NAME)

$(NAME):
	$(CC) $(NAME) $(SRC)
	
clean:
	/bin/rm -f $(LIB)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all