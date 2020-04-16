/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_initialize.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vancitters <vancitters@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 12:32:31 by vancitters     #+#    #+#                */
/*   Updated: 2020/04/16 19:32:41 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

void	set_tile_width_and_height(t_vars *t)
{
	t->res3d_w = t->map->res_w;
	t->res3d_h = t->map->res_h;
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
			}
			x++;
		}
		y++;
	}
}
