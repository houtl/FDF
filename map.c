/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:53:08 by thou              #+#    #+#             */
/*   Updated: 2017/03/08 18:02:36 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_new_image(t_a *a)
{

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
