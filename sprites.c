/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 11:44:32 by tim            #+#    #+#                */
/*   Updated: 2020/03/23 16:51:05 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void    hit_sprite_x(t_vars *t, t_ray_data *r, float eucl,  float pos_wall)
{
    
}

void    hit_sprite_y(t_vars *t, t_ray_data *r, float eucl,  float pos_wall)
{
    
}

void   findwall_sprite_x(t_vars *t, t_ray_data *r)
{
    r->pos_wall = fabs(cos(r->ray_dir) * r->eucl_dist);
    r->pos_wall = r->pos_wall - r->dist;
    r->pos_wall = r->pos_wall - (int)r->pos_wall;
    if (r->pos_wall < 0)
        r->pos_wall += 1.0;
    if ((r->ray_dir > 0.5 * M_PI && r->ray_dir <= M_PI) || (r->ray_dir > 1.5 * M_PI)) // smaller than 2
        r->pos_wall = 1 - r->pos_wall;
    t->sp->pos_wall[t->sp->count] = r->pos_wall;
    hit_sprite_x(t, r, t->sp->eucl_dist[t->sp->count],  t->sp->pos_wall[t->sp->count]);
}

void    findwall_sprite_y(t_vars *t, t_ray_data *r)
{
    r->pos_wall = fabs(sin(r->ray_dir) * r->eucl_dist);
    r->pos_wall = r->pos_wall - r->dist;
    r->pos_wall = r->pos_wall - (int)r->pos_wall;
    if (r->pos_wall < 0)
        r->pos_wall += 1.0;
    if (r->ray_dir < M_PI) // interessant nog bekijken later maller than 2
        r->pos_wall = 1 - r->pos_wall;
    t->sp->pos_wall[t->sp->count] = r->pos_wall;
    hit_sprite_y(t, r, t->sp->eucl_dist[t->sp->count],  t->sp->pos_wall[t->sp->count]);
    
}


void    get_sprite_pos(t_vars *t, t_ray_data *r)
{
    t->sp->count++;
    if (r->side == 0)
	{
		r->dist = r->dist_y;
		t->sp->eucl_dist[t->sp->count] = r->hit_x;
        findwall_sprite_x(t, r);
	}
	else
	{
		r->dist = r->dist_x;
		t->sp->eucl_dist[t->sp->count] = r->hit_y;
        findwall_sprite_y(t, r);
	}
}

void    draw_sprites(t_vars *t, t_ray_data *r)
{
    while (t->sp->count >= 0)
    {
        draw_north_sprite(t, r, t->sp->eucl_dist[t->sp->count],  t->sp->pos_wall[t->sp->count]);
        t->sp->count--;
    }
}