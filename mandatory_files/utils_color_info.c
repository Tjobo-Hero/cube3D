/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_color_info.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vancitters <vancitters@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 13:55:42 by vancitters    #+#    #+#                 */
/*   Updated: 2020/04/14 21:30:58 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		check_color_value_floor(t_list *map)
{
	if (map->f_color_red == -1 || map->f_color_green == -1
		|| map->f_color_blue == -1)
		return (1);
	return (0);
}

int		check_color_value_ceiling(t_list *map)
{
	if (map->c_color_red == -1 || map->c_color_green == -1
		|| map->c_color_blue == -1)
		return (1);
	return (0);
}

int		fill_ceiling_color(char *line, t_list *map, int *i)
{
	map->c_color_red = convert_color(line, i, map);
	map->c_color_green = convert_color(line, i, map);
	map->c_color_blue = convert_color(line, i, map);
	if (check_color_value_ceiling(map))
		return (put_str(">>> COMMMA/NEGATIVE CEILING?<<<\n", 1));
	return (0);
}

int		fill_floor_color(char *line, t_list *map, int *i)
{
	map->f_color_red = convert_color(line, i, map);
	map->f_color_green = convert_color(line, i, map);
	map->f_color_blue = convert_color(line, i, map);
	if (check_color_value_floor(map))
		return (put_str(">>> COMMMA/NEGATIVE FLOOR?<<<\n", 1));
	return (0);
}

int		check_double_color_floor(t_list *map)
{
	map->comma = 0;
	if (map->f_color_red > -1 || map->f_color_green > -1
		|| map->f_color_blue > -1)
		return (put_str(">>>DOUBLE COLOR PATH FLOOR<<<\n", 1));
	return (0);
}
