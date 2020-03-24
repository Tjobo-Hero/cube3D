/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 11:26:45 by tvan-cit       #+#    #+#                */
/*   Updated: 2020/03/20 12:53:45 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	set_player_direction(t_vars *t, char c)
{
	if (c == 'N')
		t->mid_ray = M_PI;
	if (c == 'S')
		t->mid_ray = 0;
	if (c == 'E')
		t->mid_ray = M_PI / 2;
	if (c == 'W')
		t->mid_ray = M_PI * 1.5;
}

void	screen_cleaner(t_vars *t)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < t->res3d_w)
	{
		while (y < t->res3d_h)
		{
			my_mlx_pixel_put3d(t, x, y, 0x0000FF00);
			y++;
		}
		y = 0;
		x++;
	}
}

int		exit_program(t_vars *t)
{
	// int i;
	// int j;
	
	// i = 0;
	// j = 0;
	// while (t->map->map_2d[i])
	// {
	// 	free(t->map->map_2d[i]);
	// 	i++;
	// }
	free(t->map->map_2d);
	write(1, "EXITED THE PROGRAM CLEAN\n", 25);
	exit(0);
	return (-1);
}
