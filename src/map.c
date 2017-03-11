/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:53:08 by thou              #+#    #+#             */
/*   Updated: 2017/03/11 18:09:15 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_background(t_a *a)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			*(unsigned int*)(a->e.data + (x * a->e.bpp) + (y * a->e.sl)) = BACKGROUND;
	}
}

void	fdf_new_image(t_a *a)
{
	a->e.img = mlx_new_image(a->e.mlx, WIDTH, HEIGHT);
	a->e.data = mlx_get_data_addr(a->e.img, &a->e.bpp, &a->e.sl, &a->e.ed);
	if (a->e.data == NULL)
		ft_errorf("GET_DATA ERROR", a);
	a->e.bpp /= 8;
	if (a->e.background < 0)
		ft_background(a);
}

void	init(t_a *a)
{
	if (!(a->e.mlx = mlx_init()))
		ft_errorf("mlx_init error", a);
	if (!(a->e.win = mlx_new_window(a->e.mlx, WIDTH, HEIGHT, "FDF")))
		ft_errorf("mlx_new_window error", a);
	a->e.background = 1;
	a->e.info = -1;
	a->e.iso = -1;
	fdf_new_image(a);
}
