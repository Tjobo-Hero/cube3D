/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vancitters <vancitters@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 11:52:53 by vancitters    #+#    #+#                 */
/*   Updated: 2020/04/26 20:14:09 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		check_character(t_list *map, char c)
{
	if (c == '1' || c == '0' || c == '2' || c == ' ')
		return (0);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		map->n_count++;
		if (map->n_count > 1)
			return (put_str(">>>TOO MANY STARTING POSITIONS<<<\n", 1));
		return (0);
	}
	return (put_str(">>>WRONG CHARACTER IN MAP<<<\n", 1));
}

void	convert_2d_array(t_list *map)
{
	int y;
	int x;

	y = 0;
	while (y < map->row_count)
	{
		x = 0;
		while (map->map_2d[y][x] != '\0')
		{
			if (map->map_2d[y][x] == ' ')
				map->map_2d[y][x] = '1';
			x++;
		}
		y++;
	}
}
