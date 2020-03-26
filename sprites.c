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

void    hit_sprite_x(t_vars *t, t_ray_data *r, float eucl,  float pos_wall)
{   
    
}

void    hit_sprite_y(t_vars *t, t_ray_data *r, float eucl,  float pos_wall)
{
     float ray_start;
    float sp_start;
    float sp_step;
    float ray_step;
    float i;
    float ray;
    float lengte a;
    float lengte b;
    float lengte c;

    t->sp->step = 0.0001;
    ray_start = pos_wall;
    sp_start = (tan(r->ray_dir) * 0.5) + 0.5;
    ray_step = (step / tan(r->ray_dir));
    sp_step = tan(r->ray_dir - 0.5 * M_PI) * step;
    i = (ray_start - sp_start) / (sp_step - ray_step);
    t->sp->eucl_dist[t->sp->count] = (i * ray_step) + eucl;
    ray = fabs((ray_start + (i * ray_step)) - 0.5)
    lengte a = fabs(i - 0.5);
    lengte b = 0.5 - (ray_star + (i * ray_step));
    lengte c = sqrt(pow(lengte a, 2) + pow(lengte b, 2));  
    if (ray > 0 && ray < 0.5)
        t->sp->pos_wall[t->sp->count] = c;
    else if(ray >= 0.5 && ray < 1.0)
        

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
    if (r->ray_dir < M_PI) // interessant nog bekijken later smaller than 2
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

// void    draw_sprites(t_vars *t, t_ray_data *r)
// {
//     while (t->sp->count >= 0)
//     {
//         draw_north_sprite(t, r, t->sp->eucl_dist[t->sp->count],  t->sp->pos_wall[t->sp->count]);
//         t->sp->count--;
//     }
// }