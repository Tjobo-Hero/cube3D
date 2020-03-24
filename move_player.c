/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 15:08:57 by tvan-cit       #+#    #+#                */
/*   Updated: 2020/03/20 17:19:23 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	move_player(t_vars *t, float move)
{
	float temp_x;
	float temp_y;
	// float temp_angle;

	temp_x = t->x;
	temp_y = t->y;
	t->x += sin(t->mid_ray) * move;
	if (t->map->map_2d[(int)t->y][(int)t->x] == '1' ||
	t->map->map_2d[(int)t->y][(int)t->x] == '2')
		t->x = temp_x;
	t->y += cos(t->mid_ray) * move;
	if (t->map->map_2d[(int)t->y][(int)t->x] == '1' ||
	t->map->map_2d[(int)t->y][(int)t->x] == '2')
		t->y = temp_y;
	my_mlx_pixel_put(t, (t->x * t->tile_width),
	(t->y * t->tile_height), 0x000000);
}

void	move_crab(t_vars *t, float move)
{
	float temp_x;
	float temp_y;
	float x_dir;
	float y_dir;
	// float temp_angle;

	temp_x = t->x;
	temp_y = t->y;
	x_dir = sin(t->mid_ray + M_PI / 2);
	y_dir = cos(t->mid_ray + M_PI / 2);
	t->x += x_dir * move;
	if (t->map->map_2d[(int)t->y][(int)t->x] == '1' || t->map->map_2d[(int)t->y][(int)t->x] == '2')
		t->x = temp_x;
	t->y += y_dir * move;
	if (t->map->map_2d[(int)t->y][(int)t->x] == '1' || t->map->map_2d[(int)t->y][(int)t->x] == '2')
		t->y = temp_y;
	my_mlx_pixel_put(t, (t->x * t->tile_width), (t->y * t->tile_height), 0x000000);
}