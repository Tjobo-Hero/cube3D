/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 11:44:32 by tim            #+#    #+#                */
/*   Updated: 2020/03/26 14:47:47 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

// void    hit_sprite_x(t_vars *t, t_ray_data *r, float eucl,  float pos_wall)
// {   
    
// }

void    hit_sprite_y(t_vars *t, t_ray_data *r, float eucl,  float pos_wall)
{
    float ray_start;
    float sp_start;
    float sp_step;
    float ray_step;
    float i;
    float ray;

    r->temp_x = 0;
    t->sp->step = 0.001;
    ray_start = pos_wall;
    sp_start = (tan(r->ray_dir - 0.5 * M_PI) * 0.5) + 0.5;
    ray_step = t->sp->step * tan(r->ray_dir) * -1;

    sp_step = tan(r->ray_dir - 0.5 * M_PI) * t->sp->step * -1;
    i = (ray_start - sp_start) / (sp_step - ray_step);
    t->sp->eucl_dist[t->sp->count] = fabs((i * t->sp->step) / (cos(r->ray_dir))) + eucl;
    ray = ray_start + (i * ray_step); //+ 0.5);
    if (ray >= 0.0 && ray < 0.5)
    {
        t->sp->pos_wall[t->sp->count] = 0.5 - ((fabs(ray - 0.5)) / (sin(r->ray_dir - 0.5 * M_PI)));
    }
    else if(ray >= 0.5 && ray < 1.0)
    {
        t->sp->pos_wall[t->sp->count] = (ray - 0.5) / fabs(sin(r->ray_dir + 0.5 * M_PI)) + 0.5;
    }
    if (t->sp->pos_wall[t->sp->count] > 1.0 || t->sp->pos_wall[t->sp->count] < 0.0) // checken of dit klopt
    {
        t->sp->pos_wall[t->sp->count] = -1;
    }
    // printf("2: on_wall:%f\n", t->sp->pos_wall[t->sp->count]);
}

void   findwall_sprite_x(t_vars *t, t_ray_data *r)
{
    r->pos_wall = fabs(cos(r->ray_dir) * t->sp->eucl_dist[t->sp->count]);
    r->pos_wall = r->pos_wall - r->dist;
    r->pos_wall = r->pos_wall - (int)r->pos_wall;
    if (r->pos_wall < 0)
        r->pos_wall += 1.0;
    if ((r->ray_dir > 0.5 * M_PI && r->ray_dir <= M_PI) || (r->ray_dir > 1.5 * M_PI)) // smaller than 2
        r->pos_wall = 1 - r->pos_wall;
    t->sp->pos_wall[t->sp->count] = r->pos_wall;
    // hit_sprite_x(t, r, t->sp->eucl_dist[t->sp->count],  t->sp->pos_wall[t->sp->count]);
}

void    findwall_sprite_y(t_vars *t, t_ray_data *r)
{
    r->pos_wall = fabs(sin(r->ray_dir) * t->sp->eucl_dist[t->sp->count]);
    r->pos_wall = r->pos_wall - r->dist;
    r->pos_wall = r->pos_wall - (int)r->pos_wall;
    if (r->pos_wall < 0)
        r->pos_wall += 1.0;
    if (r->ray_dir > M_PI) // interessant nog bekijken later smaller than 2
        r->pos_wall = 1 - r->pos_wall;
    t->sp->pos_wall[t->sp->count] = r->pos_wall;
    // printf("EUCL: %F -- POS_WALL IN: %f\n", t->sp->eucl_dist[t->sp->count], r->pos_wall);
    hit_sprite_y(t, r, t->sp->eucl_dist[t->sp->count],  t->sp->pos_wall[t->sp->count]);
}

void    get_sprite_pos(t_vars *t, t_ray_data *r)
{
    t->sp->count++;
    if (r->side == 0)
	{
		r->dist = r->dist_y;
		t->sp->eucl_dist[t->sp->count] = r->hit_x;
        // findwall_sprite_x(t, r);
	}
	else
	{
		r->dist = r->dist_x;
		t->sp->eucl_dist[t->sp->count] = r->hit_y;
        findwall_sprite_y(t, r);
	}
}