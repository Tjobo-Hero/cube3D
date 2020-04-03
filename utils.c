/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 11:26:45 by tvan-cit      #+#    #+#                 */
/*   Updated: 2020/04/03 16:50:37 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	set_player_direction(t_vars *t, char c)
{
	if (c == 'N')
		t->mid_ray = M_PI;
	else if (c == 'S')
		t->mid_ray = 0;
	else if (c == 'E')
		t->mid_ray = M_PI / 2;
	else if (c == 'W')
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

void		set_tile_width_and_height(t_vars *t)
{
	t->res3d_w = t->map->res_w;
	t->res3d_h = t->map->res_h;
}

void	draw_map(t_vars *t)
{
	int x;
	int y;

	y = 0;
	while (y < t->map->row_count)
	{
		x = 0;
		while (t->map->map_2d[y][x] != '\0')
		{
			if (t->map->map_2d[y][x] == 'N' || t->map->map_2d[y][x] == 'S' ||
			t->map->map_2d[y][x] == 'E' || t->map->map_2d[y][x] == 'W')
			{
				set_player_direction(t, t->map->map_2d[y][x]);
				t->x = x + 0.5;
				t->y = y + 0.5;
				printf("x: %f\n", t->x);
				printf("y: %f\n", t->y);
			}
			x++;
		}
		y++;
	}
}

void	init_angles(t_vars *t, t_ray_data *r)
{
	t->sp->sp_angle_l = r->ray_dir + 0.5 * M_PI;
	if (t->sp->sp_angle_l > 2 * M_PI)
		t->sp->sp_angle_l -= 2 * M_PI;
	t->sp->sp_angle_r = r->ray_dir - 0.5 * M_PI;
	if (t->sp->sp_angle_r < 0)
		t->sp->sp_angle_r += 2 * M_PI;
}
