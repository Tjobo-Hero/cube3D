/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_map_info.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 14:54:53 by tvan-cit       #+#    #+#                */
/*   Updated: 2020/03/11 15:30:20 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

char	*get_texture(char **line)
{
	while (**line != '.')
		(*line)++;
	if (**line == '.' && (*line)[1] == '/')
		return (ft_strdup((const char*)(*line)));
	return (0);
}

void	get_resolution(char **line, t_list *map)
{
	while (!(**line >= '0' && **line <= '9'))
		(*line)++;
	while (**line >= '0' && **line <= '9')
	{
		map->res_w = map->res_w * 10 + (**line - 48);
		(*line)++;
	}
	while (**line == ' ')
		(*line)++;
	while (**line >= '0' && **line <= '9')
	{
		map->res_h = map->res_h * 10 + (**line - 48);
		(*line)++;
	}
}

int		convert_color(char **line)
{
	int i;

	i = 0;
	while (!(**line >= '0' && **line <= '9') && **line != '\0')
	{
		if (**line == '-')
			return (-1);
		(*line)++;
	}
	while (**line >= '0' && **line <= '9')
	{
		i = i * 10 + (**line - 48);
		(*line)++;
	}
	return (i);
}

void	get_color(char **line, t_list *map)
{
	if (**line == 'F')
	{
		map->f_color_red = convert_color(line);
		map->f_color_green = convert_color(line);
		map->f_color_blue = convert_color(line);
	}
	if (**line == 'C')
	{
		map->c_color_red = convert_color(line);
		map->c_color_green = convert_color(line);
		map->c_color_blue = convert_color(line);
	}
}

int		get_map_info(char **line, t_list *map)
{
	while (**line == ' ')
		(*line)++;
	if (**line == 'S' && (*line)[1] == ' ')
		map->sprite_texture = get_texture(line);
	else if (**line == 'N' && (*line)[1] == 'O')
		map->no_texture = get_texture(line);
	else if (**line == 'W' && (*line)[1] == 'E')
		map->we_texture = get_texture(line);
	else if (**line == 'E' && (*line)[1] == 'A')
		map->ea_texture = get_texture(line);
	else if (**line == 'S' && (*line)[1] == 'O')
		map->so_texture = get_texture(line);
	else if (**line == 'R')
		get_resolution(line, map);
	else if (**line == 'F')
		get_color(line, map);
	else if (**line == 'C')
		get_color(line, map);
	else if ((**line == '1' && (*line)[1] == ' ') ||
	(**line == '0' && (*line)[1] == ' '))
	{
		if (get_map(line, map))
			return (-1);
	}
	return (0);
}
