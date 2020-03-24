/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_map.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 11:33:22 by tvan-cit       #+#    #+#                */
/*   Updated: 2020/03/23 11:41:13 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	clear_struct(t_list *map)
{
	map->res_w = 0;
	map->res_h = 0;
	map->no_texture = NULL;
	map->so_texture = NULL;
	map->we_texture = NULL;
	map->ea_texture = NULL;
	map->sprite_texture = NULL;
	map->f_color_red = -1;
	map->f_color_green = -1;
	map->f_color_blue = -1;
	map->c_color_red = -1;
	map->c_color_green = -1;
	map->c_color_blue = -1;
	map->row_count = 0;
	map->column_count = 0;
	map->n_count = 0;
	map->save = 0;
}

int		get_map(char **line, t_list *map)
{
	char	*temp;

	if (!map->map_str)
		map->map_str = ft_strdup("");
	temp = map->map_str;
	map->map_str = ft_strjoin_cube(map->map_str,
	(const char*)(*line));
	if (!map->map_str)
		return (1);
	free(temp);
	return (0);
}
