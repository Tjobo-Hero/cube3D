/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_world.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 11:55:21 by tvan-cit       #+#    #+#                */
/*   Updated: 2020/03/18 15:57:47 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void		my_mlx_pixel_put3d(t_vars *t, int x, int y, int color)
{
	char	*dst;

	dst = t->addr2 + (y * t->line_length2 + x *
	(t->bits_per_pixel2 / 8));
	*(unsigned int*)dst = color;
}

void		main_world(t_vars *t, t_ray_data *r)
{
	float	pix_height;
	int		y_count;

	pix_height = 1.0 / r->perp_dist;
	if (pix_height > 1.0)
		pix_height = 0.999999;
	pix_height = (pix_height * t->res3d_h) / 2.0;
	y_count = 0;
	while (y_count < pix_height)
	{
		my_mlx_pixel_put3d(t, t->x_count, (t->res3d_h / 2) + y_count, 0x000000FF);
		my_mlx_pixel_put3d(t, t->x_count, (t->res3d_h / 2) - y_count, 0x000000FF);
		y_count++;
	}
}
