/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:00:39 by thou              #+#    #+#             */
/*   Updated: 2017/03/14 18:06:08 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        put_color(t_a *a)
{
	int     x;
	int     y;

	y = -1;
	while (++y < a->y_max)
	{
		x = -1;
		while (++x < a->x_max)
			a->map[y][x].color = (loca_color(a, a->map[y][x].z));
	}
}

int			loca_color(t_a *a, int z)
{
	int		i;

	i = a->e.z_len / 10;
	if (z >= a->z_min && z < (a->z_min + (i * 1)))
		return (RED);
	else if (z >= (a->z_min + (i * 1)) && z < (a->z_min + (i * 2)))
		return (ORANGE);
	else if (z >= (a->z_min + (i * 2)) && z < (a->z_min + (i * 3)))
		return (YELLOW);
	else if (z >= (a->z_min + (i * 3)) && z < (a->z_min + (i * 4)))
		return (LIMON);
	else if (z >= (a->z_min + (i * 4)) && z < (a->z_min + (i * 5)))
		return (RAZER);
	else if (z >= (a->z_min + (i * 5)) && z < (a->z_min + (i * 6)))
		return (WGREEN);
	else if (z >= (a->z_min + (i * 6)) && z < (a->z_min + (i * 7)))
		return (LAGON);
	else if (z >= (a->z_min + (i * 7)) && z < (a->z_min + (i * 8)))
		return (SKY);
	else if (z >= (a->z_min + (i * 8)) && z < (a->z_min + (i * 9)))
		return (BLUE_C);
	else if (z >= (a->z_min + (i * 9)) && z < a->z_max)
		return (BLUE);
	return (0xFFFFFF);
}
