/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   all_map_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 10:59:39 by tvan-cit      #+#    #+#                 */
/*   Updated: 2020/04/22 19:26:32 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		check_save(t_list *map, char **argv)
{
	size_t	i;
	char	*save;

	save = "--save";
	i = ft_strlen(argv[2]);
	if (i > 6 || i < 6)
	{
		write(1, "Did you mean --save?\n", 21);
		return (1);
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		if (argv[2][i] != save[i])
		{
			write(1, "Did you mean --save?\n", 21);
			return (1);
		}
		i++;
	}
	map->save = 1;
	return (0);
}

int		check_filename(char **argv)
{
	size_t	i;
	size_t	i2;
	char	*cub;

	cub = ".cub";
	i = ft_strlen(argv[1]) - 1;
	i2 = 3;
	while (i > (ft_strlen(argv[1]) - 4))
	{
		if (argv[1][i] != cub[i2])
		{
			write(1, "Did you mean .cub?\n", 19);
			return (1);
		}
		i--;
		i2--;
	}
	return (0);
}

int		check_argc(t_list *map, int argc, char **argv)
{
	if (argc < 2 || argc > 3)
	{
		write(1, "I need one file to work\n", 24);
		return (1);
	}
	if (argc == 2)
	{
		if (check_filename(argv))
			return (1);
	}
	if (argc == 3)
	{
		if (check_save(map, argv))
			return (1);
	}
	return (0);
}

int		read_map(t_list *map, char **argv)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Open file failed\n", 18);
		return (1);
	}
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
		{
			close(fd);
			return (put_str(">>>READ FAILED<<<\n", 1));
		}
		if (get_map_info(line, map))
			return (1);
		free(line);
	}
	close(fd);
	return (0);
}

int		all_map_functions(t_list *map, int argc, char **argv)
{
	clear_struct(map);
	if (check_argc(map, argc, argv))
		return (1);
	if (read_map(map, argv))
		return (1);
	if (check_if_valid_info(map))
		return (put_str(">>>INFO NOT VALID<<<\n", 1));
	if (check_if_valid_map(map))
		return (put_str(">>>MAP NOT VALID<<<\n", 1));
	free(map->map_str);
	return (0);
}
