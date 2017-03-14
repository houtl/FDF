/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:13:41 by thou              #+#    #+#             */
/*   Updated: 2017/03/12 18:20:36 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_p_pixel_image(t_a *a, int y, int x, int color)
{
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
					*(unsigned int*)(a->e.data + (x * (a->e.bpp)) + (y * a->e.sl)) = color;
}

static void		ligne_if(t_a *a, int color)
{
		a->b.cumul = a->b.dx / 2;
			a->b.i = 0;
				while (++a->b.i <= a->b.dx)
						{
									a->b.x += a->b.xinc;
											a->b.cumul += a->b.dy;
													if (a->b.cumul >= a->b.dx)
																{
																				a->b.cumul -= a->b.dx;
																							a->b.y += a->b.yinc;
																									}
															ft_p_pixel_image(a, a->b.y, a->b.x, color);
																}
}

static void		ligne_else(t_a *a, int color)
{
		a->b.cumul = a->b.dy / 2;
			a->b.i = 0;
				while (++a->b.i <= a->b.dy)
						{
									a->b.y += a->b.yinc;
											a->b.cumul += a->b.dx;
													if (a->b.cumul >= a->b.dy)
																{
																				a->b.cumul -= a->b.dy;
																							a->b.x += a->b.xinc;
																									}
															ft_p_pixel_image(a, a->b.y, a->b.x, color);
																}
}

void			ligne(t_a *a, int color)
{
		a->b.x = a->p1.x;
			a->b.y = a->p1.y;
				a->b.dx = a->p2.x - a->p1.x;
					a->b.dy = a->p2.y - a->p1.y;
						a->b.xinc = (a->b.dx > 0) ? 1 : -1;
							a->b.yinc = (a->b.dy > 0) ? 1 : -1;
								a->b.dx = abs(a->b.dx);
									a->b.dy = abs(a->b.dy);
										ft_p_pixel_image(a, a->b.y, a->b.x, color);
											if (a->b.dx > a->b.dy)
														ligne_if(a, color);
												else
															ligne_else(a, color);
}
