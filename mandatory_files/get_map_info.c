/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_map_info.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 14:54:53 by tvan-cit      #+#    #+#                 */
/*   Updated: 2020/04/23 16:01:55 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		get_texture(char *line, t_list *map, char c)
{
	line++;
	if (c != 's')
		line++;
	while (*line != '.' && *line != '\0')
	{
		if (*line != ' ')
			return (put_str(">>>TEXTURE ERROR<<<\n", 1));
		line++;
	}
	if (check_double_path(map, c))
		return (put_str(">>>DOUBLE PATH<<<\n", 1));
	if (c == 'N')
		map->no_texture = ft_strdup(line);
	else if (c == 'S')
		map->so_texture = ft_strdup(line);
	else if (c == 'E')
		map->ea_texture = ft_strdup(line);
	else if (c == 'W')
		map->we_texture = ft_strdup(line);
	else if (c == 's')
		map->sprite_texture = ft_strdup(line);
	return (0);
}

int		get_resolution(char *line, t_list *map)
{
	if (*line == 'R')
		line++;
	while (*line == ' ')
		line++;
	if (!(*line >= '0' && *line <= '9'))
		return (put_str(">>>WRONG CHARACTER RESOLUTION BEGIN<<<\n", 1));
	if (convert_res_width(&line, map))
		return (1);
	while (*line == ' ')
		line++;
	if (!(*line >= '0' && *line <= '9'))
		return (put_str(">>>WRONG CHARACTER RESOLUTION MIDDLE<<<\n", 1));
	if (convert_res_height(&line, map))
		return (1);
	while (*line == ' ')
		line++;
	if (!(*line == '\n' || *line == '\0'))
		return (put_str(">>>WRONG CHARACTER RESOLUTION END<<<\n", 1));
	return (0);
}

int		get_color(char *line, t_list *map)
{
	int i;

	i = 0;
	if (*line == 'F')
	{
		if (check_double_color_floor(map))
			return (1);
		if (fill_floor_color(line, map, &i))
			return (1);
		return (check_end_line(line, &i));
	}
	if (*line == 'C')
	{
		if (check_double_color_ceiling(map))
			return (1);
		if (fill_ceiling_color(line, map, &i))
			return (1);
		return (check_end_line(line, &i));
	}
	return (0);
}

int		get_info(char *line, t_list *map)
{
	skip_beginning(&line, map);
	if (*line == '\n')
		return (0);
	else if (*line == 'N' && line[1] == 'O')
		return (get_texture(line, map, 'N'));
	else if (*line == 'W' && line[1] == 'E')
		return (get_texture(line, map, 'W'));
	else if (*line == 'E' && line[1] == 'A')
		return (get_texture(line, map, 'E'));
	else if (*line == 'S' && line[1] == 'O')
		return (get_texture(line, map, 'S'));
	else if ((*line == 'S' && line[1] != 'O')) // nog een nieuwe functie toevoegen
		return (get_texture(line, map, 's'));
	else if (*line == 'R')
		return (get_resolution(line, map));
	else if (*line == 'F')
		return (get_color(line, map));
	else if (*line == 'C')
		return (get_color(line, map));
	if (map->begin_map == 1)
	{
		if (get_map(line, map))
			return (1);
	}
	return (0);
}

int		get_map_info(char *line, t_list *map)
{
	if (check_character_info(line, map))
		return (1);
	if (get_info(line, map))
	{
		if (map->begin_map == 1)
			free(map->map_str);
		return (1);
	}
	return (0);
}
