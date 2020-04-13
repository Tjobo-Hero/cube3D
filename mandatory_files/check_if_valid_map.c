/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_if_valid_map.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 11:23:51 by tvan-cit      #+#    #+#                 */
/*   Updated: 2020/04/13 15:27:18 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

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
	// printf("NEWSTR:%s\n", newstr);
	return (newstr);
}

int		make_2d_array(t_list *map)
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
		(map->column_count + 1));
		if (!map->map_2d[y])
		{
			free_willy(map->map_2d, y);
			return (put_str("MALLOC FAIL", 1));
		}
		while (map->map_str[i] != '\n')
		{
			map->map_2d[y][x] = map->map_str[i];
			x++;
			i++;
		}
		while (x < map->column_count)
		{
			map->map_2d[y][x] = ' ';
			x++;
		}
		i++;
		map->map_2d[y][x] = '\0';
		x = 0;
		y++;
	}
	return (0);
}

void		counting_row_and_column(t_list *map)
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

void		convert_2d_array(t_list *map)
{
	int y;
	int x;
	
	y = 0;
	while (y < map->row_count)
	{
		x = 0;
		while (map->map_2d[y][x] != '\0')
		{
			if (map->map_2d[y][x] == ' ')
				map->map_2d[y][x] = '1';
			x++;
		}
		y++;
	}
}

int			check_if_valid_map(t_list *map)
{
	// int y;

	// y = 0;
	counting_row_and_column(map);
	if (make_2d_array(map))
		return (1);
	// while (y < map->row_count)
	// {
	// 	printf("%s\n", map->map_2d[y]);
	// 	y++;
	// }
	if (check_2d_array(map))
		return (1);
	convert_2d_array(map);
	// y = 0;
	// while (y < map->row_count)
	// {
	// 	printf("%s\n", map->map_2d[y]);
	// 	y++;
	// }
	return (put_str(">>>MAP IS VALID || LEKKER BEZIG <<<\n", 0));
}
