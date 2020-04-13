/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_map_info.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 14:54:53 by tvan-cit      #+#    #+#                 */
/*   Updated: 2020/04/13 21:44:08 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

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

char	*convert_texture(char *line)
{
	while (*line != '.')
		line++;
	if (*line == '.' && line[1] == '/')
		return (ft_strdup(line));
	return (0);
}

int		get_texture(char *line, t_list *map, char c)
{
	if (c != 's')
	{
		if (!(line[2] == ' ' || line[2] == '.'))
			return (put_str("TEXTURE ERROR\n", 1));
	}
	if (check_double_path(map, c))
		return (put_str(">>> DOUBLE PATH <<<\n", 1));
	if (c == 'N')
		map->no_texture = convert_texture(line);
	else if (c == 'S')
		map->so_texture = convert_texture(line);
	else if (c == 'E')
		map->ea_texture = convert_texture(line);
	else if (c == 'W')
		map->we_texture = convert_texture(line);
	else if (c == 's')
		map->sprite_texture = convert_texture(line);
	return (0);
}

int		get_resolution(char *line, t_list *map)
{
	unsigned int num;

	num = 0;
	while (!(*line >= '0' && *line <= '9'))
		line++;
	while (*line >= '0' && *line <= '9')
	{
		num = num * 10 + (*line - 48);
		line++;
	}
	map->res_w = num;
	num = 0;
	while (*line == ' ')
		line++;
	while (*line >= '0' && *line <= '9')
	{
		num = num * 10 + (*line - 48);
		line++;
	}
	map->res_h = num;
	while (*line == ' ')
		line++;
	if (!(*line == '\n' || *line == '\0'))
		return (put_str(">>>WRONG CHARACTER RESOLUTION<<<\n", 1));
	return (0);
}

int		convert_color(char *line, int *i)
{
	int num;

	num = 0;
	while (!(line[*i] >= '0' && line[*i] <= '9') && line[*i] != '\0')
	{
		if (line[*i] == '-')
			return (-1);
		(*i)++;
	}
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - 48);
		(*i)++;
	}
	return (num);
}

int		check_end_line(char *line, int *i)
{
	while (line[*i] == ' ')
		(*i)++;
	if (!(line[*i] == '\n' || line[*i] == '\0'))
		return (put_str(">>>WRONG CHARACTER COLOR<<<\n", 1));
	return (0);
}

int		get_color(char *line, t_list *map)
{
	int i;

	i = 0;
	if (*line == 'F')
	{
		map->f_color_red = convert_color(line, &i);
		map->f_color_green = convert_color(line, &i);
		map->f_color_blue = convert_color(line, &i);
		return (check_end_line(line, &i));
	}
	if (*line == 'C')
	{
		map->c_color_red = convert_color(line, &i);
		map->c_color_green = convert_color(line, &i);
		map->c_color_blue = convert_color(line, &i);
		return (check_end_line(line, &i));
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

int		get_info(char *line, t_list *map)
{
	skip_beginning(&line, map);
	if ((*line == 'S' && line[1] == ' ') || line[1] == '.')
		return (get_texture(line, map, 's'));
	else if (*line == 'N' && line[1] == 'O')
		return (get_texture(line, map, 'N'));
	else if (*line == 'W' && line[1] == 'E')
		return (get_texture(line, map, 'W'));
	else if (*line == 'E' && line[1] == 'A')
		return (get_texture(line, map, 'E'));
	else if (*line == 'S' && line[1] == 'O')
		return (get_texture(line, map, 'S'));
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
		return (1);
	return (0);
}
