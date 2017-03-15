/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 17:08:35 by thou              #+#    #+#             */
/*   Updated: 2017/03/15 17:56:26 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_put_info(t_a *a)
{
	char	*line;

	line = "press I for more information";
	mlx_string_put(a->e.mlx, a->e.win, 20, 5, RAZER, line);
}

int			recover_point(t_a *a, int x, int y, char c)
{
	int		x1;
	int		y1;

	x1 = 1 + x;
	y1 = 1 + y;
	if (x < a->x_max && x1 < a->x_max && c == 'x' && x >= 0)
	{
		a->p1.x = a->map[y][x].x - ((y * a->k) * a->e.iso);
		a->p1.y = a->map[y][x].y - a->map[y][x].z;
		a->p2.x = a->map[y][x1].x - ((y * a->k) * a->e.iso);
		a->p2.y = a->map[y][x1].y - a->map[y][x1].z;
		return (1);
	}
	if (y < a->y_max && y1 < a->y_max && c == 'y' && y >= 0)
	{
		a->p1.x = a->map[y][x].x - ((y * a->k) * a->e.iso);
		a->p1.y = a->map[y][x].y - a->map[y][x].z;
		a->p2.x = a->map[y1][x].x - ((y1 * a->k) * a->e.iso);
		a->p2.y = a->map[y1][x].y - a->map[y1][x].z;
		return (1);
	}
	return (0);
}

void		ft_print_image_x(t_a *a, int x, int y)
{
	if (a->map[y][x].z < a->map[y][x + 1].z)
	{
		if (a->e.touch_z > 0)
			ligne(a, a->map[y][x + 1].color);
		else
			ligne(a, a->map[y][x].color);
	}
	else
	{
		if (a->e.touch_z > 0)
			ligne(a, a->map[y][x].color);
		else
			ligne(a, a->map[y][x + 1].color);
	}
}

static void	ft_print_image_while(t_a *a, int x, int y)
{
	if ((recover_point(a, x, y, 'x')) > 0)
		ft_print_image_x(a, x, y);
	if ((recover_point(a, x, y, 'y')) > 0)
	{
		if (a->map[y][x].z < a->map[y + 1][x].z)
		{
			if (a->e.touch_z > 0)
				ligne(a, a->map[y + 1][x].color);
			else
				ligne(a, a->map[y][x].color);
		}
		else
		{
			if (a->e.touch_z > 0)
				ligne(a, a->map[y][x].color);
			else
				ligne(a, a->map[y + 1][x].color);
		}
	}
}

void		ft_print_image(t_a *a)
{
	int		x;
	int		y;

	y = -1;
	while (++y < a->y_max)
	{
		x = -1;
		while (++x < a->x_max)
			ft_print_image_while(a, x, y);
	}
	mlx_put_image_to_window(a->e.mlx, a->e.win, a->e.img, 0, 0);
	ft_put_info(a);
	mlx_destroy_image(a->e.mlx, a->e.img);
}
