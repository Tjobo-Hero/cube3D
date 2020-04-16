/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vancitters <vancitters@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 16:44:36 by vancitters     #+#    #+#                */
/*   Updated: 2020/04/16 19:20:47 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	texture_north2(t_vars *t)
{
	if (t->res3d_h % 2 == 0)
		my_mlx_pixel_put3d(t, t->x_count, t->no->half_res_h - t->no->y_count,
		*(unsigned int*)(t->no->addr + ((t->no->img_h - (int)(t->no->text_step
		* t->no->y_count)) * t->no->line_length + t->no->h1)));
	draw_floor_and_ceiling(t, t->no->y_count, t->x_count);
}

void	texture_south2(t_vars *t)
{
	if (t->res3d_h % 2 == 0)
		my_mlx_pixel_put3d(t, t->x_count, t->so->half_res_h - t->so->y_count,
		*(unsigned int*)(t->so->addr + ((t->so->img_h - (int)(t->so->text_step
		* t->so->y_count)) * t->so->line_length + t->so->h1)));
	draw_floor_and_ceiling(t, t->so->y_count, t->x_count);
}

void	texture_east2(t_vars *t)
{
	if (t->res3d_h % 2 == 0)
		my_mlx_pixel_put3d(t, t->x_count, t->ea->half_res_h - t->ea->y_count,
		*(unsigned int*)(t->ea->addr + ((t->ea->img_h - (int)(t->ea->text_step
		* t->ea->y_count)) * t->ea->line_length + t->ea->h1)));
	draw_floor_and_ceiling(t, t->ea->y_count, t->x_count);
}

void	texture_west2(t_vars *t)
{
	if (t->res3d_h % 2 == 0)
		my_mlx_pixel_put3d(t, t->x_count, t->we->half_res_h - t->we->y_count,
		*(unsigned int*)(t->we->addr + ((t->we->img_h - (int)(t->we->text_step
		* t->we->y_count)) * t->we->line_length + t->we->h1)));
	draw_floor_and_ceiling(t, t->we->y_count, t->x_count);
}
