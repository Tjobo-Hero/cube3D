/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_resolution_info.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vancitters <vancitters@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 14:24:50 by vancitters    #+#    #+#                 */
/*   Updated: 2020/04/14 21:31:21 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		convert_res_width(char **line, t_list *map)
{
	unsigned int num;

	num = 0;
	if (map->res_w > -1)
		return (put_str(">>>DOUBLE RESOLUTION<<\n", 1));
	while (**line >= '0' && **line <= '9')
	{
		num = num * 10 + (**line - 48);
		(*line)++;
	}
	map->res_w = num;
	return (0);
}

int		convert_res_height(char **line, t_list *map)
{
	unsigned int num;

	num = 0;
	if (map->res_h > -1)
		return (put_str(">>>DOUBLE RESOLUTION<<\n", 1));
	while (**line >= '0' && **line <= '9')
	{
		num = num * 10 + (**line - 48);
		(*line)++;
	}
	map->res_h = num;
	return (0);
}
