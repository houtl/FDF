/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:35:35 by thou              #+#    #+#             */
/*   Updated: 2017/03/15 17:56:54 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	origin(t_a *a)
{
	int	x;
	int	y;

	y = -1;
	while (++y < a->y_max)
	{
		x = -1;
		while (++x < a->x_max)
		{
			a->map[y][x].x = x * 10 + (WIDTH - a->x_max * 10) / 2 + (a->y_max * 5);
			a->map[y][x].y = y * 10 + (HEIGHT - a->y_max * 10) / 2;
			a->map[y][x].z = a->map[y][x].zo;
		}
	}
}

static void	hauter(t_a *a, int keycode)
{
	int x;
	int y;

	y = -1;
	while (++y < a->y_max)
	{
		x = -1;
		while (++x < a->x_max)
		{
			if (keycode == HIGH)
			{
				a->map[y][x].z *= 1.1;
				a->k *= 1.1;
			}
			else if (keycode == LOW)
			{
				a->map[y][x].z /= 1.1;
				a->k /= 1.1;
			}
		}
	}
}

static void	change(t_a *a, int keycode)
{
	int x;
	int y;

	y = -1;
	a->x_mid = a->map[a->y_max - 1][a->x_max - 1].x - a->map[0][0].x;
	a->y_mid = a->map[a->y_max - 1][a->x_max - 1].y - a->map[0][0].y;
	while (++y < a->y_max)
	{
		x = -1;
		while (++x < a->x_max)
		{
			if (keycode == GRAND)
			{
				a->map[y][x].x = a->x_mid + (a->map[y][x].x - a->x_mid) * 1.1;
				a->map[y][x].y = a->y_mid + (a->map[y][x].y - a->y_mid) * 1.1;
			}
			if (keycode == PETIT)
			{
				a->map[y][x].x = a->x_mid + (a->map[y][x].x - a->x_mid) / 1.1;
				a->map[y][x].y = a->y_mid + (a->map[y][x].y - a->y_mid) / 1.1;
			}
		}
	}
}

static void	move(t_a *a, int keycode)
{
	int x;
	int y;

	y = -1;
	while (++y < a->y_max)
	{
		x = -1;
		while (++x < a->x_max)
		{
			if (keycode == LEFT)
				a->map[y][x].x -= 20;
			else if (keycode == RIGHT)
				a->map[y][x].x += 20;
			else if (keycode == UP)
				a->map[y][x].y -= 20;
			else if (keycode == DOWN)
				a->map[y][x].y +=20;
		}
	}
}

int		my_fonct_key(int keycode, t_a *a)
{
	if (keycode == EXIT)
		ft_errorf("EXIT FDF", a);
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		move(a, keycode);
	if (keycode == GRAND || keycode == PETIT)
		change(a, keycode);
	if (keycode == HIGH || keycode == LOW)
		hauter(a, keycode);
	if (keycode == ISO)
		a->e.iso *= -1;
	if (keycode == BG)
		a->e.background *= -1;
	if (keycode == HELP)
		a->e.info *= -1;
	if (keycode == ISO_Z)
		a->e.iso *= -1;
	if (keycode == ORIGIN)
		origin(a);
	if (keycode == ORIGIN_Z)
		a->e.iso = -1;
	fdf_new_image(a);
	ft_print_image(a);
	return (0);
}
