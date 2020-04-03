/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:28 by tvan-cit      #+#    #+#                 */
/*   Updated: 2020/04/03 14:22:33 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	draw_map(t_vars *t)
{
	int x;
	int y;

	y = 0;
	while (y < t->map->row_count)
	{
		x = 0;
		while (t->map->map_2d[y][x] != '\0')
		{
			if (t->map->map_2d[y][x] == 'N' || t->map->map_2d[y][x] == 'S' ||
			t->map->map_2d[y][x] == 'E' || t->map->map_2d[y][x] == 'W')
			{
				set_player_direction(t, t->map->map_2d[y][x]);
				t->x = x + 0.5;
				t->y = y + 0.5;
				printf("x: %f\n", t->x);
				printf("y: %f\n", t->y);
			}
			x++;
		}
		y++;
	}
}

int		main(int argc, char **argv)
{
	t_list	map;
	t_vars	t;

	t.map = &map;	
	write(1, ">>>CHECKING MAP<<<\n", 20);
	if (all_map_functions(&map, argc, argv))
	{
		write(1, ">>>CHECK INPUT<<<\n", 19);
		return (-1);
	}
	draw_map(&t);
	maze(&map, &t);
	return (0);
}
