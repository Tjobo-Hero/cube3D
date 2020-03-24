/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 11:23:51 by tvan-cit       #+#    #+#                */
/*   Updated: 2020/03/18 14:15:50 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int			ft_strlen_and_line_check(int i, t_list *map)
{
	int column_count;

	column_count = 0;
	while (map->map_str[i] != '\n')
	{
		column_count++;
		i++;
	}
	column_count = ((column_count / 2) + 1);
	return (column_count);
}

char		**free_willy(char **newstr, int i_n)
{
	while (newstr)
	{
		i_n--;
		free(newstr[i_n]);
	}
	free(newstr);
	return (NULL);
}

char		*ft_strjoin_cube(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		i2;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	i2 = 0;
	newstr = ((char*)malloc(sizeof(char) *
	((ft_strlen(s1) + ft_strlen(s2)) + 2)));
	if (!newstr)
		return (NULL);
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
	{
		newstr[i + i2] = s2[i2];
		i2++;
	}
	newstr[i + i2] = '\n';
	newstr[i + i2 + 1] = '\0';
	return (newstr);
}

int			make_2d_array(t_list *map)
{
	int y;
	int x;
	int i;

	y = 0;
	x = 0;
	i = 0;
	map->map_2d = (char **)malloc(sizeof(char*) *
	(map->row_count));
	if (!map->map_2d)
		return (1);
	while (y < map->row_count)
	{
		map->map_2d[y] = (char*)malloc(sizeof(char) *
		(ft_strlen_and_line_check(i, map) + 1));
		if (!map->map_2d[y])
		{
			free_willy(map->map_2d, y);
			return (1);
		}
		while (map->map_str[i] != '\n')
		{
			while (map->map_str[i] == ' ')
				i++;
			map->map_2d[y][x] = map->map_str[i];
			x++;
			i++;
		}
		i++;
		map->map_2d[y][x] = '\0';
		if ((int)ft_strlen(map->map_2d[y]) != map->column_count)
			return (1);
		x = 0;
		y++;
	}
	// map->map_2d[y] = NULL;
	return (0);
}

int			convert_map(t_list *map)
{
	int i;
	int ret;

	ret = 0;
	i = 0;
	while (map->map_str[i] != '\0')
	{
		if (map->map_str[i] == '\n')
			map->row_count++;
		i++;
	}
	map->column_count = ((ft_strlen(map->map_str)
	/ map->row_count) / 2);
	if (make_2d_array(map))
	{
		write(1, ">>>LINE TOO LONG<<<\n", 20);
		return (1);
	}
	if (check_2d_array(map))
		return (1);
	write(1, ">>>MAP IS VALID || LEKKER BEZIG <<<\n", 37);
	return (0);
}
