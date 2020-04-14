/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_if_valid_map.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 11:23:51 by tvan-cit      #+#    #+#                 */
/*   Updated: 2020/04/14 16:41:14 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

char	*ft_strjoin_cube(char *s1, char *s2)
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

int		fill_2d_array(t_list *map, int y, int *i)
{
	int x;

	x = 0;
	map->map_2d[y] = (char*)malloc(sizeof(char) *
	(map->column_count + 1));
	if (!map->map_2d[y])
	{
		free(map->map_str);
		free_willy(map->map_2d, y);
		return (put_str(">>>MALLOC FAIL<<<\n", 1));
	}
	while (map->map_str[*i] != '\n')
	{
		map->map_2d[y][x] = map->map_str[*i];
		x++;
		(*i)++;
	}
	while (x < map->column_count)
	{
		map->map_2d[y][x] = ' ';
		x++;
	}
	(*i)++;
	map->map_2d[y][x] = '\0';
	return (0);
}

int		make_2d_array(t_list *map)
{
	int y;
	int i;

	y = 0;
	i = 0;
	map->map_2d = (char **)malloc(sizeof(char*) *
	(map->row_count));
	if (!map->map_2d)
	{
		free(map->map_str);
		return (put_str(">>>MALLOC FAIL<<<\n", 1));
	}
	while (y < map->row_count)
	{
		if (fill_2d_array(map, y, &i))
			return (1);
		y++;
	}
	return (0);
}

void	counting_row_and_column(t_list *map)
{
	int i;
	int count;

	i = 0;
	while (map->map_str[i] != '\0')
	{
		if (map->map_str[i] == '\n')
			map->row_count++;
		i++;
	}
	i = 0;
	while (map->map_str[i] != '\0')
	{
		while (map->map_str[i] != '\n')
		{
			i++;
			count++;
		}
		if (count > map->column_count)
			map->column_count = count;
		count = 0;
		i++;
	}
}

int		check_if_valid_map(t_list *map)
{
	counting_row_and_column(map);
	if (make_2d_array(map))
	{
		free(map->map_str);
		return (1);
	}
	if (check_2d_array(map))
	{
		free(map->map_str);
		return (1);
	}
	convert_2d_array(map);
	return (put_str(">>>MAP IS VALID || LEKKER BEZIG <<<\n", 0));
}
