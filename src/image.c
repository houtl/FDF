/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:48:32 by thou              #+#    #+#             */
/*   Updated: 2017/03/16 17:56:40 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_background(t_a *a)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_p_pixel_image(a, y, x, BACKGROUND);
	}
}

void		fdf_new_image(t_a *a)
{
	a->e.img = mlx_new_image(a->e.mlx, WIDTH, HEIGHT);
	a->e.data = mlx_get_data_addr(a->e.img, &a->e.bpp, &a->e.sl, &a->e.ed);
	if (a->e.data == NULL)
		ft_errorf("GET_DATA ERROR", a);
	a->e.bpp /= 8;
	if (a->e.background < 0)
		ft_background(a);
}

void		init(t_a *a)
{
	if (!(a->e.mlx = mlx_init()))
		ft_errorf("mlx_init error", a);
	if (!(a->e.win = mlx_new_window(a->e.mlx, WIDTH, HEIGHT, "FDF")))
		ft_errorf("mlx_new_window error", a);
	a->e.background = 1;
	a->e.info = -1;
	fdf_new_image(a);
}
