/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 11:44:32 by tim           #+#    #+#                 */
/*   Updated: 2020/04/14 16:12:45 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	hit_sprite_y(t_vars *t, t_ray_data *r, int sign1, int sign2)
{
	t->sp->ray_start = t->sp->pos_wall[t->sp->count];
	t->sp->sp_start = 0.5 + ((0.5 * fabs(tan(t->sp->sp_angle_l))) * sign1);
	t->sp->ray_step = t->sp->step * tan(r->ray_dir) * -1;
	t->sp->sp_step = tan(t->sp->sp_angle_l) * t->sp->step * -1;
	t->sp->i = (t->sp->ray_start - t->sp->sp_start) /
	(t->sp->sp_step - t->sp->ray_step);
	t->sp->ray = t->sp->ray_start + (t->sp->i * t->sp->ray_step);
	t->sp->eucl_dist[t->sp->count] = fabs((t->sp->i * t->sp->step) /
	(cos(r->ray_dir))) + t->sp->eucl_dist[t->sp->count];
	t->sp->eucl_dist[t->sp->count] = t->sp->eucl_dist[t->sp->count]
	* cos(t->mid_ray - r->ray_dir);
	if (t->sp->ray > 0.0 && t->sp->ray < 0.5)
		t->sp->pos_wall[t->sp->count] = 0.5 + ((fabs(t->sp->ray - 0.5))
		/ (sin(t->sp->sp_angle_l)) * sign2);
	else if (t->sp->ray >= 0.5 && t->sp->ray < 1.0)
		t->sp->pos_wall[t->sp->count] = (t->sp->ray - 0.5)
		/ fabs(sin(t->sp->sp_angle_r)) + 0.5;
	if (t->sp->pos_wall[t->sp->count] > 1.0 ||
	t->sp->pos_wall[t->sp->count] < 0.0)
		t->sp->pos_wall[t->sp->count] = -1;
}

void	hit_sprite_x(t_vars *t, t_ray_data *r, float sign1, int sign2)
{
	t->sp->ray_start = t->sp->pos_wall[t->sp->count];
	if (sign1 == -0.5 && (r->ray_dir > 1.5 * M_PI && r->ray_dir <= 2.0 * M_PI))
		t->sp->sp_start = 0.5 + sign1 / fabs(tan(t->sp->sp_angle_r));
	else
		t->sp->sp_start = 0.5 + sign1 / fabs(tan(t->sp->sp_angle_l));
	t->sp->ray_step = t->sp->step / tan(r->ray_dir);
	if (sign1 == 0.5)
		t->sp->sp_step = t->sp->step / tan(t->sp->sp_angle_l);
	else
		t->sp->sp_step = t->sp->step / tan(t->sp->sp_angle_r);
	hit_sprite_x2(t, r);
	if (t->sp->ray > 0.0 && t->sp->ray < 0.5)
		t->sp->pos_wall[t->sp->count] = 0.5 - (fabs(t->sp->ray - 0.5))
		/ cos(t->sp->sp_angle_l);
	else if ((t->sp->ray >= 0.5 && t->sp->ray < 1.0) && sign2 == 0)
		t->sp->pos_wall[t->sp->count] = (t->sp->ray - 0.5)
		/ fabs(cos(t->sp->sp_angle_r)) + 0.5;
	else if ((t->sp->ray >= 0.5 && t->sp->ray < 1.0) && sign2 == 1)
		t->sp->pos_wall[t->sp->count] = 1.0 - ((t->sp->ray - 0.5)
		/ fabs(cos(t->sp->sp_angle_r)) + 0.5);
	if (t->sp->pos_wall[t->sp->count] > 1.0 ||
	t->sp->pos_wall[t->sp->count] < 0.0)
		t->sp->pos_wall[t->sp->count] = -1;
}

void	findwall_sprite_x(t_vars *t, t_ray_data *r)
{
	if (r->pos_wall < 0)
		r->pos_wall += 1.0;
	t->sp->pos_wall[t->sp->count] = r->pos_wall;
	if (r->step_x == -1)
	{
		if (r->ray_dir > 1.5 * M_PI && r->ray_dir <= 2 * M_PI)
		{
			t->sp->pos_wall[t->sp->count] = (1 - r->pos_wall);
			hit_sprite_x(t, r, -0.5, 0);
		}
		else
			hit_sprite_x(t, r, 0.5, 0);
	}
	if (r->step_x == 1)
	{
		if (r->ray_dir < 0.5 * M_PI)
		{
			t->sp->pos_wall[t->sp->count] = (1 - r->pos_wall);
			hit_sprite_x(t, r, -0.5, 1);
		}
		else
			hit_sprite_x(t, r, 0.5, 1);
	}
}

void	findwall_sprite_y(t_vars *t, t_ray_data *r)
{
	if (r->pos_wall < 0)
		r->pos_wall += 1.0;
	t->sp->pos_wall[t->sp->count] = r->pos_wall;
	if (r->step_y == -1)
	{
		if (r->ray_dir > 1 * M_PI)
		{
			t->sp->pos_wall[t->sp->count] = (1 - r->pos_wall);
			hit_sprite_y(t, r, -1, 1);
		}
		else
			hit_sprite_y(t, r, 1, 1);
	}
	if (r->step_y == 1)
	{
		if (r->ray_dir < 0.5 * M_PI)
		{
			t->sp->pos_wall[t->sp->count] = (1 - r->pos_wall);
			hit_sprite_y(t, r, -1, -1);
		}
		else
			hit_sprite_y(t, r, 1, -1);
	}
}

void	get_sprite_pos(t_vars *t, t_ray_data *r)
{
	t->sp->count++;
	if (r->side == 0)
	{
		r->dist = r->dist_y;
		t->sp->eucl_dist[t->sp->count] = r->hit_x;
		init_angles(t, r);
		r->pos_wall = (fabs(cos(r->ray_dir) *
		t->sp->eucl_dist[t->sp->count])) - r->dist;
		r->pos_wall = r->pos_wall - (int)r->pos_wall;
		findwall_sprite_x(t, r);
	}
	else
	{
		r->dist = r->dist_x;
		t->sp->eucl_dist[t->sp->count] = r->hit_y;
		init_angles(t, r);
		r->pos_wall = (fabs(sin(r->ray_dir) *
		t->sp->eucl_dist[t->sp->count])) - r->dist;
		r->pos_wall = r->pos_wall - (int)r->pos_wall;
		findwall_sprite_y(t, r);
	}
}
