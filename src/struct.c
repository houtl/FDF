/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:30:25 by thou              #+#    #+#             */
/*   Updated: 2017/03/10 17:27:15 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_errorf(char *str, t_a *a)
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

t_map		**ft_newstruct(t_a *a)
{
	int		x;
	int		y;

	if (!(a->map = (t_map **)malloc(sizeof(t_map*) * a->y_max)))
	{
		free(a->map);
		ft_error("Malloc Failed");
	}
	y = -1;
	while (++y < a->y_max)
	{
		if (!(a->map[y] = (t_map*)malloc(sizeof(t_map) * a->x_max)))
			ft_error("Malloc Failed");
		x = -1;
		while (++x < a->x_max)
		{
			a->map[y][x].x = x;
			a->map[y][x].y = y;
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
	int		find;

	i = 0;
	find = 0;
	x = 0;
	caravf(a, str);
	while (str[i] && y < a->y_max)
	{
		while (str[i] && str[i] != '-' && (str[i] < '0' || str[i] > '9'))
			i++;
		while (str[i] && (str[i] == '-' || ft_isdigit(str[i])) && find == 0
				&& x < a->x_max)
		{
			find = 1;
			a->map[y][x].z = ft_atoi(str + i);
			a->map[y][x].zo = a->map[y][x].z;
			x++;
		}
		while (str[i] && (str[i] == '-' || ft_isdigit(str[i]) ||
					(str[i] >= 'A' && str[i] <= 'F') || str[i] == ',' ||
					str[i] == 'x'))
			i++;
		find = 0;
	}
}
