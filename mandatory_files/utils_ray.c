/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_ray.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vancitters <vancitters@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 12:36:43 by vancitters    #+#    #+#                 */
/*   Updated: 2020/04/21 13:17:23 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
	t->sp->count = -1;
}

void	draw_ray(float ray_angle, t_vars *t)
{
	t_ray_data	r;

	r.ray_dir = ray_angle;
	r.x_dir = sin(r.ray_dir);
	r.y_dir = cos(r.ray_dir);
	find_wall(t, &r);
}

void	shoot_rays(t_vars *t)
{
	float	start;
	float	ray;
	float	increment;

	increment = 2.0 / t->res3d_w;
	start = -1;
	t->x_count = 0;
	while (start <= 1)
	{
		ray = t->mid_ray - atan(start / t->mid_line);
		if (ray >= TWOPI)
			ray -= TWOPI;
		else if (ray < 0)
			ray += TWOPI;
		draw_ray(ray, t);
		start += increment;
		t->x_count++;
	}
}
