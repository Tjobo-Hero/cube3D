/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_2d_array.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 15:30:42 by tvan-cit       #+#    #+#                */
/*   Updated: 2020/03/11 15:29:59 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int		check_character(char c, t_list *map, int y)
{
	if (map->map_2d[y][0] != '1')
	{
		write(1, ">>>WRONG FIRST CHARACTER<<<\n", 29);
		return (1);
	}
	if (map->map_2d[y][map->column_count - 1] != '1')
	{
		write(1, ">>>WRONG LAST CHARACTER<<<\n", 28);
		return (1);
	}
	if (c == '1' || c == '0' || c == '2')
		return (0);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		map->n_count++;
		return (0);
	}
	write(1, ">>>WRONG CHARACTER IN MAP<<<\n", 30);
	return (1);
}

int		check_first_and_last_line(t_list *map, int x, int y)
{
	while (x < map->column_count)
	{
		if (map->map_2d[y][x] != '1')
		{
			write(1, ">>>WRONG FIRST OR LAST LINE<<<\n", 32);
			return (1);
		}
		x++;
	}
	return (0);
}

int		check_2d_array(t_list *map)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (y < map->row_count)
	{
		if (y == 0 || y == map->row_count - 1)
		{
			if (check_first_and_last_line(map, x, y))
				return (1);
		}
		while (x < map->column_count)
		{
			if (check_character(map->map_2d[y][x], map, y))
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	if (map->n_count != 1)
		return (1);
	return (0);
}
