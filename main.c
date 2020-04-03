/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:28 by tvan-cit      #+#    #+#                 */
/*   Updated: 2020/04/03 15:08:00 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int		main(int argc, char **argv)
{
	t_list	map;
	t_vars	t;

	t.map = &map;	
	write(1, ">>>CHECKING MAP<<<\n", 20);
	if (all_map_functions(&map, argc, argv))
	{
		write(1, ">>>CHECK INPUT<<<\n", 19);
		return (-1);
	}
	draw_map(&t);
	maze(&map, &t);
	return (0);
}
