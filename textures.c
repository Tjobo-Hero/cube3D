/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/18 11:58:57 by tim           #+#    #+#                 */
/*   Updated: 2020/04/03 11:48:44 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void    texture_north(t_vars *t, t_ray_data *r)
{
    char    *color;
    float   pix_height;
	int     y_count;
    float   text_step;
    int     height_text;                        // new
    int 	test;
	int		test1;
	int 	test2;	
	
    pix_height = 1.0 / r->perp_dist;
    height_text = (pix_height * t->res3d_h) / 2.0; // new
	if (pix_height > 1.0)
		pix_height = 0.999999;
	pix_height = (pix_height * t->res3d_h) / 2.0;
	y_count = 0;
    text_step = ((t->no->img_height_no - 1.0) / 2.0) / height_text; // new
	test = (t->no->img_height_no / 2);
	test1 = (int)(r->pos_wall * t->no->img_width_no) * (t->no->bits_per_pixel_no / 8);
	test2 = (t->res3d_h / 2);
	while (y_count <= (int)pix_height) // Kan mis gaan door de + 1;
	{
        color = t->no->addr_no + ((test + (int)(text_step * y_count)) * t->no->line_length_no + test1);
        //  printf("x_count_no: %i\n", t->x_count);
        my_mlx_pixel_put3d(t, t->x_count, test2 + y_count, *(unsigned int*)color);
        color = t->no->addr_no + ((test - (int)(text_step * y_count)) * t->no->line_length_no + test1);
		my_mlx_pixel_put3d(t, t->x_count, test2 - y_count, *(unsigned int*)color);
        y_count++;
    }
    if (t->res3d_h % 2 == 0)
    {
        color = t->no->addr_no + ((test - (int)(text_step * y_count)) * t->no->line_length_no + test1);
		my_mlx_pixel_put3d(t, t->x_count, test2 - y_count, *(unsigned int*)color);
    }
    draw_floor_and_ceiling(t, y_count, t->x_count);
}

void    texture_south(t_vars *t, t_ray_data *r)
{
    char    *color;
    float   pix_height;
	int     y_count;
    float   text_step;
    int     height_text;
    
    pix_height = 1.0 / r->perp_dist;
    height_text = (pix_height * t->res3d_h) / 2.0;
	if (pix_height > 1.0)
		pix_height = 0.999999;
	pix_height = (pix_height * t->res3d_h) / 2.0;
	y_count = 0;
    text_step = ((t->so->img_height_so - 1.0) / 2.0) / height_text; // new
	while (y_count <= (int)pix_height) // Kan mis gaan door de + 1;
	{
        color = t->so->addr_so + (((t->so->img_height_so / 2) + (int)(text_step * y_count)) * t->so->line_length_so + (int)(r->pos_wall * t->so->img_width_so) *
        (t->so->bits_per_pixel_so / 8));
        //  printf("x_count_so: %i\n", t->x_count);
        my_mlx_pixel_put3d(t, t->x_count, (t->res3d_h / 2) + y_count, *(unsigned int*)color);
        color = t->so->addr_so + (((t->so->img_height_so / 2) - (int)(text_step * y_count)) * t->so->line_length_so + (int)(r->pos_wall * t->so->img_width_so) *
        (t->so->bits_per_pixel_so / 8));
		my_mlx_pixel_put3d(t, t->x_count, (t->res3d_h / 2) - y_count, *(unsigned int*)color);
        y_count++;
    }
    if (t->res3d_h % 2 == 0)
    {
        color = t->so->addr_so + (((t->so->img_height_so / 2) - (int)(text_step * y_count)) * t->so->line_length_so + (int)(r->pos_wall * t->so->img_width_so) *
        (t->so->bits_per_pixel_so / 8));
		my_mlx_pixel_put3d(t, t->x_count, (t->res3d_h / 2) - y_count, *(unsigned int*)color);
    }
    draw_floor_and_ceiling(t, y_count, t->x_count);
}

void    texture_east(t_vars *t, t_ray_data *r)
{
    char    *color;
    float   pix_height;
	int     y_count;
    float   text_step;
    int     height_text;


    pix_height = 1.0 / r->perp_dist;
    height_text = (pix_height * t->res3d_h) / 2.0;
	if (pix_height > 1.0)
		pix_height = 0.999999;
	pix_height = (pix_height * t->res3d_h) / 2.0;
	y_count = 0;
    text_step = ((t->ea->img_height_ea - 1.0) / 2.0) / height_text; // new
	while (y_count <= (int)pix_height) // Kan mis gaan door de + 1;
	{
        color = t->ea->addr_ea + (((t->ea->img_height_ea / 2) + (int)(text_step * y_count)) * t->ea->line_length_ea + (int)(r->pos_wall * t->ea->img_width_ea) *
        (t->ea->bits_per_pixel_ea / 8));
        //  printf("x_count_ea: %i\n", t->x_count);
        my_mlx_pixel_put3d(t, t->x_count, (t->res3d_h / 2) + y_count, *(unsigned int*)color);
        color = t->ea->addr_ea + (((t->ea->img_height_ea / 2) - (int)(text_step * y_count)) * t->ea->line_length_ea + (int)(r->pos_wall * t->ea->img_width_ea) *
        (t->ea->bits_per_pixel_ea / 8));
		my_mlx_pixel_put3d(t, t->x_count, (t->res3d_h / 2) - y_count, *(unsigned int*)color);
        y_count++;
    }
    if (t->res3d_h % 2 == 0)
    {
        color = t->ea->addr_ea + (((t->ea->img_height_ea / 2) - (int)(text_step * y_count)) * t->ea->line_length_ea + (int)(r->pos_wall * t->ea->img_width_ea) *
        (t->ea->bits_per_pixel_ea / 8));
		my_mlx_pixel_put3d(t, t->x_count, (t->res3d_h / 2) - y_count, *(unsigned int*)color);
    }
    draw_floor_and_ceiling(t, y_count, t->x_count);
}

void    texture_west(t_vars *t, t_ray_data *r)
{
    char   *color;
    float   pix_height;
	int     y_count;
    float   text_step;
    int     height_text;
    
    pix_height = 1.0 / r->perp_dist;
    height_text = (pix_height * t->res3d_h) / 2.0;
	if (pix_height > 1.0)
		pix_height = 0.999999;
	pix_height = (pix_height * t->res3d_h) / 2.0;
	y_count = 0;
    text_step = ((t->we->img_height_we - 1.0) / 2.0) / height_text; // new
	while (y_count <= (int)pix_height) // Kan mis gaan door de + 1;
	{
        color = t->we->addr_we + (((t->we->img_height_we / 2) + (int)(text_step * y_count)) * t->we->line_length_we + (int)(r->pos_wall * t->we->img_width_we) *
        (t->we->bits_per_pixel_we / 8));
        my_mlx_pixel_put3d(t, t->x_count, (t->res3d_h / 2) + y_count, *(unsigned int*)color);
        color = t->we->addr_we + (((t->we->img_height_we / 2) - (int)(text_step * y_count)) * t->we->line_length_we + (int)(r->pos_wall * t->we->img_width_we) *
        (t->we->bits_per_pixel_we / 8));
		my_mlx_pixel_put3d(t, t->x_count, (t->res3d_h / 2) - y_count, *(unsigned int*)color);
        y_count++;
    }
    if (t->res3d_h % 2 == 0)
    {
        color = t->we->addr_we + (((t->we->img_height_we / 2) - (int)(text_step * y_count)) * t->we->line_length_we + (int)(r->pos_wall * t->we->img_width_we) *
        (t->we->bits_per_pixel_we / 8));
		my_mlx_pixel_put3d(t, t->x_count, (t->res3d_h / 2) - y_count, *(unsigned int*)color);
    }
    draw_floor_and_ceiling(t, y_count, t->x_count);
}

