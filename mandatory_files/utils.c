/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 11:26:45 by tvan-cit      #+#    #+#                 */
/*   Updated: 2020/04/26 20:17:31 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		put_str(char *str, int num)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (num);
}

int		exit_program(t_vars *t)
{
	int i;

	i = 0;
	while (i < t->map->row_count)
	{
		free(t->map->map_2d[i]);
		i++;
	}
	free(t->map->map_2d);
	write(1, "EXITED THE PROGRAM CLEAN\n", 25);
	exit(0);
	return (-1);
}

char	**free_willy(char **newstr, int i_n)
{
	while (newstr)
	{
		i_n--;
		free(newstr[i_n]);
	}
	free(newstr);
	return (NULL);
}

int		leave_game(t_vars *t)
{
	mlx_destroy_window(t->mlx2, t->win2);
	exit_program(t);
	return (0);
}

int		ft_strlen(const char *str)
{
	int len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
