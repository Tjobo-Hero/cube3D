/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_map_info.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vancitters <vancitters@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 12:23:16 by vancitters    #+#    #+#                 */
/*   Updated: 2020/04/23 14:33:32 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		check_end_line(char *line, int *i)
{
	while (line[*i] == ' ')
		(*i)++;
	if (!(line[*i] == '\n' || line[*i] == '\0'))
		return (put_str(">>>WRONG CHARACTER COLOR<<<\n", 1));
	return (0);
}

int		check_character_info(char *line, t_list *map)
{
	skip_beginning(&line, map);
	if (map->res_h >= 0 && map->res_w >= 0 &&
	map->f_color_blue >= 0 && map->f_color_green >= 0 &&
	map->f_color_red >= 0 && map->c_color_blue >= 0 &&
	map->c_color_green >= 0 && map->c_color_red >= 0 &&
	map->so_texture != NULL &&
	map->no_texture != NULL && map->we_texture != NULL
	&& map->ea_texture != NULL &&
	map->sprite_texture != NULL)
		map->begin_map = 1;
	if (map->begin_map == 0)
	{
		if (*line != 'N' && *line != 'S' && *line != 'W' && *line != 'R'
		&& *line != 'F' && *line != 'C' && *line != 'E' && *line != ' '
		&& *line != '\0')
			return (put_str(">>>WRONG CHARACTER INFO<<<\n", 1));
	}
	else if (map->begin_map == 1)
	{
		if (*line != '0' && *line != '1' && *line != '2' && *line != 'N'
		&& *line != 'S' && *line != 'E' && *line != 'W' && *line != ' '
		&& *line != '\n' && *line != '\0')
			return (put_str(">>>WRONG CHARACTER MAP<<<\n", 1));
	}
	return (0);
}

void	skip_beginning(char **line, t_list *map)
{
	if (map->begin_map != 1)
	{
		while (*line[0] == ' ')
			(*line)++;
	}
}

int		check_double_path(t_list *map, char c)
{
	if (c == 'N' && map->no_texture != NULL)
		return (1);
	if (c == 'S' && map->so_texture != NULL)
		return (1);
	if (c == 'E' && map->ea_texture != NULL)
		return (1);
	if (c == 'W' && map->we_texture != NULL)
		return (1);
	if (c == 's' && map->sprite_texture != NULL)
		return (1);
	return (0);
}

int		convert_color(char *line, int *i, t_list *map)
{
	int num;

	num = 0;
	if (line[*i] == 'C' || line[*i] == 'F')
		(*i)++;
	while (line[*i] == ' ')
		(*i)++;
	if (line[*i] == '-')
		return (-1);
	else if (line[*i] == ',' && map->comma == 0)
		return (-1);
	else if (line[*i] != ',' && map->comma >= 1)
		return (-1);
	else if (line[*i] == ',' && map->comma >= 1)
		(*i)++;
	while (line[*i] == ' ')
		(*i)++;
	map->comma++;
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - 48);
		(*i)++;
	}
	return (num);
}
