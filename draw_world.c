/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_world.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 11:55:21 by tvan-cit      #+#    #+#                 */
/*   Updated: 2020/04/03 13:42:01 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void		my_mlx_pixel_put3d(t_vars *t, int x, int y, int color)
{
	char	*dst;

	if (t->addr_count % 2 == 0)
	{
		dst = t->addr1 + (y * t->line_length2 + x *
		(t->bits_per_pixel2 / 8));
		*(unsigned int*)dst = color;
	}
	else
	{
		dst = t->addr2 + (y * t->line_length2 + x *
		(t->bits_per_pixel2 / 8));
		*(unsigned int*)dst = color;
	}
}

