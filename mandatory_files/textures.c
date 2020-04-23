/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/18 11:58:57 by tim           #+#    #+#                 */
/*   Updated: 2020/04/23 15:15:30 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	texture_north(t_vars *t, t_ray_data *r)
{
	t->no->pix_height = 1.0 / r->perp_dist;
	t->no->height_text = (t->no->pix_height * t->res3d_h) / 2.0;
	if (t->no->pix_height > 1.0)
		t->no->pix_height = 0.999999;
	t->no->pix_height = (t->no->pix_height * t->res3d_h) / 2.0;
	t->no->y_count = 0;
	t->no->text_step = ((t->no->img_height - 1.0) / 2.0) / t->no->height_text;
	t->no->img_h = (t->no->img_height / 2);
	t->no->h1 = (int)(r->pos_wall * t->no->img_width) *
	(t->no->bits_per_pixel / 8);
	t->no->half_res_h = (t->res3d_h / 2);
	if (t->res3d_h % 2 != 0)
		t->no->pix_height++;
	while (t->no->y_count <= (int)t->no->pix_height)
	{
		my_mlx_pixel_put3d(t, t->x_count, t->no->half_res_h + t->no->y_count,
		*(unsigned int*)(t->no->addr + ((t->no->img_h + (int)(t->no->text_step
		* t->no->y_count)) * t->no->line_length + t->no->h1)));
		my_mlx_pixel_put3d(t, t->x_count, t->no->half_res_h - t->no->y_count,
		*(unsigned int*)(t->no->addr + ((t->no->img_h - (int)(t->no->text_step *
		t->no->y_count)) * t->no->line_length + t->no->h1)));
		t->no->y_count++;
	}
	texture_north2(t);
}

void	texture_south(t_vars *t, t_ray_data *r)
{
	t->so->pix_height = 1.0 / r->perp_dist;
	t->so->height_text = (t->so->pix_height * t->res3d_h) / 2.0;
	if (t->so->pix_height > 1.0)
		t->so->pix_height = 0.999999;
	t->so->pix_height = (t->so->pix_height * t->res3d_h) / 2.0;
	t->so->y_count = 0;
	t->so->text_step = ((t->so->img_height - 1.0) / 2.0) / t->so->height_text;
	t->so->img_h = (t->so->img_height / 2);
	t->so->h1 = (int)(r->pos_wall * t->so->img_width) *
	(t->so->bits_per_pixel / 8);
	t->so->half_res_h = (t->res3d_h / 2);
	while (t->so->y_count <= (int)t->so->pix_height)
	{
		my_mlx_pixel_put3d(t, t->x_count, t->so->half_res_h + t->so->y_count,
		*(unsigned int*)(t->so->addr + ((t->so->img_h + (int)(t->so->text_step
		* t->so->y_count)) * t->so->line_length + t->so->h1)));
		my_mlx_pixel_put3d(t, t->x_count, t->so->half_res_h - t->so->y_count,
		*(unsigned int*)(t->so->addr + ((t->so->img_h - (int)(t->so->text_step *
		t->so->y_count)) * t->so->line_length + t->so->h1)));
		t->so->y_count++;
	}
	texture_south2(t);
}

void	texture_east(t_vars *t, t_ray_data *r)
{
	t->ea->pix_height = 1.0 / r->perp_dist;
	t->ea->height_text = (t->ea->pix_height * t->res3d_h) / 2.0;
	if (t->ea->pix_height > 1.0)
		t->ea->pix_height = 0.999999;
	t->ea->pix_height = (t->ea->pix_height * t->res3d_h) / 2.0;
	t->ea->y_count = 0;
	t->ea->text_step = ((t->ea->img_height - 1.0) / 2.0) / t->ea->height_text;
	t->ea->img_h = (t->ea->img_height / 2);
	t->ea->h1 = (int)(r->pos_wall * t->ea->img_width) *
	(t->ea->bits_per_pixel / 8);
	t->ea->half_res_h = (t->res3d_h / 2);
	while (t->ea->y_count <= (int)t->ea->pix_height)
	{
		my_mlx_pixel_put3d(t, t->x_count, t->ea->half_res_h + t->ea->y_count,
		*(unsigned int*)(t->ea->addr + ((t->ea->img_h + (int)(t->ea->text_step
		* t->ea->y_count)) * t->ea->line_length + t->ea->h1)));
		my_mlx_pixel_put3d(t, t->x_count, t->ea->half_res_h - t->ea->y_count,
		*(unsigned int*)(t->ea->addr + ((t->ea->img_h - (int)(t->ea->text_step *
		t->ea->y_count)) * t->ea->line_length + t->ea->h1)));
		t->ea->y_count++;
	}
	texture_east2(t);
}

void	texture_west(t_vars *t, t_ray_data *r)
{
	t->we->pix_height = 1.0 / r->perp_dist;
	t->we->height_text = (t->we->pix_height * t->res3d_h) / 2.0;
	if (t->we->pix_height > 1.0)
		t->we->pix_height = 0.999999;
	t->we->pix_height = (t->we->pix_height * t->res3d_h) / 2.0;
	t->we->y_count = 0;
	t->we->text_step = ((t->we->img_height - 1.0) / 2.0) / t->we->height_text;
	t->we->img_h = (t->we->img_height / 2);
	t->we->h1 = (int)(r->pos_wall * t->we->img_width) *
	(t->we->bits_per_pixel / 8);
	t->we->half_res_h = (t->res3d_h / 2);
	while (t->we->y_count <= (int)t->we->pix_height)
	{
		my_mlx_pixel_put3d(t, t->x_count, t->we->half_res_h + t->we->y_count,
		*(unsigned int*)(t->we->addr + ((t->we->img_h + (int)(t->we->text_step
		* t->we->y_count)) * t->we->line_length + t->we->h1)));
		my_mlx_pixel_put3d(t, t->x_count, t->we->half_res_h - t->we->y_count,
		*(unsigned int*)(t->we->addr + ((t->we->img_h - (int)(t->we->text_step *
		t->we->y_count)) * t->we->line_length + t->we->h1)));
		t->we->y_count++;
	}
	texture_west2(t);
}
