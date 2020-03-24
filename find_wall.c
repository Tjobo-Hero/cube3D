/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_wall.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 13:33:10 by tvan-cit       #+#    #+#                */
/*   Updated: 2020/03/23 16:29:53 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	find_dist(t_vars *t, t_ray_data *r)
{
	if (r->ray_dir < 0.5 * M_PI && r->ray_dir >= 0)
	{
		r->dist_x = 1 - (t->x - (int)t->x);
		r->dist_y = 1 - (t->y - (int)t->y);
	}
	if (r->ray_dir < 1 * M_PI && r->ray_dir >= 0.5 * M_PI)
	{
		r->dist_x = 1 - (t->x - (int)t->x);
		r->dist_y = t->y - (int)t->y;
	}
	if (r->ray_dir >= 1 * M_PI && r->ray_dir < 1.5 * M_PI)
	{
		r->dist_x = t->x - (int)t->x;
		r->dist_y = t->y - (int)t->y;
	}
	if (r->ray_dir >= 1.5 * M_PI && r->ray_dir <= 2 * M_PI)
	{
		r->dist_x = t->x - (int)t->x;
		r->dist_y = 1 - (t->y - (int)t->y);
	}
	r->hit_x = fabs(r->dist_x / sin(r->ray_dir));
	r->hit_y = fabs(r->dist_y / cos(r->ray_dir));
	r->delta_x = fabs(1.0 / sin(r->ray_dir));
	r->delta_y = fabs(1.0 / cos(r->ray_dir));
}

void	find_step(t_vars *t, t_ray_data *r)
{
	r->map_x = t->x;
	r->map_y = t->y;
	if (r->x_dir < 0)
		r->step_x = -1;
	else
		r->step_x = 1;
	if (r->y_dir < 0)
		r->step_y = -1; 
	else
		r->step_y = 1;
}

void	find_eucl_and_perp_dist(t_vars *t, t_ray_data *r)
{
	if (r->side == 0)
	{
		r->dist = r->dist_y;
		r->eucl_dist = r->hit_x;
	}
	else
	{
		r->dist = r->dist_x;
		r->eucl_dist = r->hit_y;
	}
	r->perp_dist = (r->eucl_dist * cos(t->mid_ray - r->ray_dir));
	if (r->side == 0)
	{
		if (r->ray_dir < (1 * M_PI))
			texture_east(t, r);
		if (r->ray_dir >= (1 * M_PI)) // = teken terug gezet
			texture_west(t, r);
	}
	else
	{
		if (r->ray_dir < (0.5 * M_PI) || r->ray_dir >= (1.5 * M_PI))
			texture_south(t, r);
		if (r->ray_dir >= (0.5 * M_PI) && r->ray_dir < (1.5 * M_PI))
			texture_north(t, r);
	}
}

void	find_wall(t_vars *t, t_ray_data *r)
{
	t->sp->count = -1;
	find_dist(t, r);
	find_step(t, r);
	while (1)
	{
		if (r->hit_x < r->hit_y)
		{
			r->map_x += r->step_x;
			r->side = 0;
			if (t->map->map_2d[r->map_y][r->map_x] == '1')
				break ;
			if (t->map->map_2d[r->map_y][r->map_x] == '2')
				get_sprite_pos(t, r);
			r->hit_x += r->delta_x;
		}
		else
		{
			r->map_y += r->step_y;
			r->side = 1;
			if (t->map->map_2d[r->map_y][r->map_x] == '1')
				break ;
			if (t->map->map_2d[r->map_y][r->map_x] == '2')
				get_sprite_pos(t, r);
			r->hit_y += r->delta_y;
		}
	}
	find_eucl_and_perp_dist(t, r);
	draw_sprites(t, r);
}
