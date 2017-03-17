/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:10:28 by thou              #+#    #+#             */
/*   Updated: 2017/03/17 11:10:31 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_palette_color(char *str, int x, int y, t_a *a)
{
	char	*c;

	c = str;
	if (*c == '0' && c[1] == 'x')
	{
		a->map[y][x].color = ft_atoi_base((c + 2), 16);
		a->map[y][x].fc = 1;
	}
}

void		ft_errorf(char *str, t_a *a)
{
	a->e.tmp = 0;
	if (a->map != NULL)
	{
		mlx_clear_window(a->e.mlx, a->e.win);
		mlx_destroy_window(a->e.mlx, a->e.win);
		free(a->e.mlx);
		free(a->map);
	}
	ft_error(str);
}

t_map		**ft_newmap(t_a *a)
{
	int		x;
	int		y;

	a->e.iso = -1;
	if (!(a->map = (t_map **)malloc(sizeof(t_map*) * a->y_max)))
	{
		free(a->map);
		ft_error("Malloc Failed");
	}
	y = -1;
	while (++y < a->y_max)
	{
		if (!(a->map[y] = (t_map*)malloc(sizeof(t_map) * a->x_max)))
			ft_errorf("Malloc Failed", a);
		x = -1;
		while (++x < a->x_max)
		{
			a->map[y][x].x = x * 10 + WIDTH / 2 - a->x_max * 5 - a->y_max * 5;
			a->map[y][x].y = y * 10 + (HEIGHT - a->y_max * 10) / 2;
			a->map[y][x].z = 0;
			a->map[y][x].color = 0;
		}
	}
	return (a->map);
}

static void	caravf(t_a *a, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] == '-' && str[i + 1] == '-') ||
				(str[i] == '+' && str[i + 1] == '+') ||
				(str[i] != '-' && str[i] != '+' && str[i] != ' ' &&
				!(str[i] >= '0' && str[i] <= '9') &&
				!(str[i] >= 'A' && str[i] <= 'F') &&
				str[i] != ',' && str[i] != 'x'))
			ft_errorf("Unknown Character", a);
	}
}

void		ft_creatmap(t_a *a, char *str, int y)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	caravf(a, str);
	while (str[i] && y < a->y_max)
	{
		while (str[i] && str[i] != '-' && (str[i] < '0' || str[i] > '9'))
			i++;
		if (str[i])
		{
			a->map[y][x].z = ft_atoi((str + i));
			a->map[y][x].zo = a->map[y][x].z;
			x++;
		}
		while (str[i] && (str[i] == '-' || ft_isdigit(str[i]) ||
					(str[i] >= 'A' && str[i] <= 'F') || str[i] == ',' ||
					str[i] == 'x'))
			if (str[i++] == ',')
				ft_palette_color((str + i), (x - 1), y, a);
	}
}
