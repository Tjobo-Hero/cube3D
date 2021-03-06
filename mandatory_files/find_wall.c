/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_wall.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 13:33:10 by tvan-cit      #+#    #+#                 */
/*   Updated: 2020/04/26 20:14:23 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	find_dist(t_vars *t, t_ray_data *r)
{
	if (r->ray_dir < HALFPI && r->ray_dir >= 0)
	{
		r->dist_x = 1 - (t->x - (int)t->x);
		r->dist_y = 1 - (t->y - (int)t->y);
	}
	else if (r->ray_dir < PI && r->ray_dir >= HALFPI)
	{
		r->dist_x = 1 - (t->x - (int)t->x);
		r->dist_y = t->y - (int)t->y;
	}
	else if (r->ray_dir >= PI && r->ray_dir < ONEPFPI)
	{
		r->dist_x = t->x - (int)t->x;
		r->dist_y = t->y - (int)t->y;
	}
	else if (r->ray_dir >= ONEPFPI && r->ray_dir <= TWOPI)
	{
		r->dist_x = t->x - (int)t->x;
		r->dist_y = 1 - (t->y - (int)t->y);
	}
	r->hit_x = fabs(r->dist_x / sin(r->ray_dir));
	r->hit_y = fabs(r->dist_y / cos(r->ray_dir));
	r->delta_x = fabs(1.0 / sin(r->ray_dir));
	r->delta_y = fabs(1.0 / cos(r->ray_dir));
	find_step(t, r);
}

void	find_eucl_and_perp_dist2(t_vars *t, t_ray_data *r)
{
	r->pos_wall = fabs(cos(r->ray_dir) * r->eucl_dist) - r->dist;
	r->pos_wall = r->pos_wall - (int)r->pos_wall;
	if (r->pos_wall < 0)
		r->pos_wall += 1.0;
	if (r->ray_dir < PI)
	{
		if (r->ray_dir >= HALFPI)
			r->pos_wall = 1 - r->pos_wall;
		texture_east(t, r);
	}
	else if (r->ray_dir >= PI)
	{
		if (r->ray_dir >= ONEPFPI)
			r->pos_wall = 1 - r->pos_wall;
		texture_west(t, r);
	}
}

void	find_eucl_and_perp_dist3(t_vars *t, t_ray_data *r)
{
	r->pos_wall = fabs(sin(r->ray_dir) * r->eucl_dist) - r->dist;
	r->pos_wall = r->pos_wall - (int)r->pos_wall;
	if (r->pos_wall < 0)
		r->pos_wall += 1.0;
	if (r->ray_dir < HALFPI || r->ray_dir >= ONEPFPI)
	{
		if (r->ray_dir < HALFPI)
			r->pos_wall = 1 - r->pos_wall;
		texture_south(t, r);
	}
	else if (r->ray_dir >= HALFPI && r->ray_dir < ONEPFPI)
	{
		if (r->ray_dir < M_PI)
			r->pos_wall = 1 - r->pos_wall;
		texture_north(t, r);
	}
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
		find_eucl_and_perp_dist2(t, r);
	else
		find_eucl_and_perp_dist3(t, r);
	while (t->sp->count >= 0)
	{
		draw_sprites(t);
		t->sp->count--;
	}
}

void	find_wall(t_vars *t, t_ray_data *r)
{
	find_dist(t, r);
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
}
