/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_player_move.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: vancitters <vancitters@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 19:41:12 by vancitters    #+#    #+#                 */
/*   Updated: 2020/04/14 21:31:15 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate_player(float rot, t_vars *t)
{
	t->mid_ray += rot;
	t->mid_ray_x = sin(t->mid_ray);
	t->mid_ray_y = cos(t->mid_ray);
	if (t->mid_ray > TWOPI)
		t->mid_ray -= TWOPI;
	else if (t->mid_ray < 0)
		t->mid_ray += TWOPI;
}
