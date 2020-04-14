/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_2d_array.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 15:30:42 by tvan-cit      #+#    #+#                 */
/*   Updated: 2020/04/14 11:53:44 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int		check_firstline(t_list *map, int y)
{
	int x;

	x = 0;
	while (map->map_2d[y][x] == ' ')
		x++;
	if (!(map->map_2d[y][x] == '\0' || map->map_2d[y][x] == '1'))
		return (1);
	while (x < (int)ft_strlen(map->map_2d[y]))
	{
		if (map->map_2d[y][x] == '1')
			x++;
		else if (map->map_2d[y][x] == ' ' && (map->map_2d[y + 1][x] == ' '
		|| map->map_2d[y + 1][x] == '1'))
			x++;
		else
			return (1);
	}
	return (0);
}

int		check_lastline(t_list *map, int y)
{
	int x;

	x = 0;
	while (map->map_2d[y][x] == ' ')
		x++;
	if (!(map->map_2d[y][x] == '\0' || map->map_2d[y][x] == '1'))
		return (1);
	while (x < (int)ft_strlen(map->map_2d[y]) && map->map_2d[y][x] != '\0')
	{
		if (map->map_2d[y][x] == '1')
			x++;
		else if (map->map_2d[y][x] == ' ' && (map->map_2d[y - 1][x] == ' '
		|| map->map_2d[y - 1][x] == '1'))
			x++;
		else
		{
			return (1);
		}
	}
	return (0);
}

int		check_middle_middle(t_list *map, int y, int x)
{
	while (x < (int)ft_strlen(map->map_2d[y]))
	{
		if (check_character(map, map->map_2d[y][x]))
			return (1);
		if (map->map_2d[y][x] == ' ')
		{
			if (!(map->map_2d[y - 1][x] == ' ' || map->map_2d[y - 1][x] == '1'))
				return (1);
			if (!(map->map_2d[y + 1][x] == ' ' || map->map_2d[y + 1][x] == '1'))
				return (1);
			if (x - 1 >= 0 && !(map->map_2d[y][x - 1] == ' '
			|| map->map_2d[y][x - 1] == '1'))
				return (1);
			if (x + 1 < (int)ft_strlen(map->map_2d[y]) &&
			!(map->map_2d[y][x + 1] == ' ' || map->map_2d[y][x + 1] == '1'))
				return (1);
		}
		x++;
	}
	return (0);
}

int		check_middle(t_list *map, int y)
{
	int x;

	x = 0;
	while (map->map_2d[y][x] == ' ')
		x++;
	if (!(map->map_2d[y][x] == '\0' || map->map_2d[y][x] == '1'))
		return (1);
	if (check_middle_middle(map, y, x))
		return (1);
	x = (int)ft_strlen(map->map_2d[y]) - 1;
	while (map->map_2d[y][x] == ' ' && x >= 0)
		x--;
	if (x == -1 && (map->map_2d[y][0] == '1' || map->map_2d[y][0] == ' '))
		return (0);
	if (map->map_2d[y][x] != '1')
		return (1);
	return (0);
}

int		check_2d_array(t_list *map)
{
	int y;

	y = 0;
	while (y < map->row_count)
	{
		if (y == 0)
		{
			if (check_firstline(map, y))
				return (put_str(">>>WRONG FIRST LINE<<<\n", 1));
		}
		if (y > 0 && y < map->row_count - 1)
		{
			if (check_middle(map, y))
				return (put_str(">>>WRONG MAP MIDDLE<<<\n", 1));
		}
		if (y == map->row_count - 1)
		{
			if (check_lastline(map, y))
				return (put_str(">>>WRONG LAST LINE<<<\n", 1));
		}
		y++;
	}
	if (map->n_count != 1)
		return (put_str(">>>NO STARTING POINT\n", 1));
	return (0);
}
