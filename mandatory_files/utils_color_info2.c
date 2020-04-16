/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_color_info2.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: vancitters <vancitters@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 13:58:24 by vancitters    #+#    #+#                 */
/*   Updated: 2020/04/14 21:31:02 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		check_double_color_ceiling(t_list *map)
{
	map->comma = 0;
	if (map->c_color_red > -1 || map->c_color_green > -1
		|| map->c_color_blue > -1)
		return (put_str(">>>DOUBLE COLOR PATH CEILING<<<\n", 1));
	return (0);
}
