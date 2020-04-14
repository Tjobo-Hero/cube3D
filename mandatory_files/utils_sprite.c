/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_sprite.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vancitters <vancitters@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 16:09:41 by vancitters    #+#    #+#                 */
/*   Updated: 2020/04/14 16:09:58 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	hit_sprite_x2(t_vars *t, t_ray_data *r)
{
	t->sp->i = (t->sp->ray_start - t->sp->sp_start) /
	(t->sp->sp_step - t->sp->ray_step);
	t->sp->ray = t->sp->ray_start + (t->sp->i * t->sp->ray_step);
	t->sp->eucl_dist[t->sp->count] = fabs((t->sp->pos_wall[t->sp->count] -
	t->sp->ray) / cos(r->ray_dir)) + t->sp->eucl_dist[t->sp->count];
	t->sp->eucl_dist[t->sp->count] = t->sp->eucl_dist[t->sp->count]
	* cos(t->mid_ray - r->ray_dir);
}
