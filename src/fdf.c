/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:13:57 by thou              #+#    #+#             */
/*   Updated: 2017/03/16 16:21:37 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		clamp_z(t_a *a)
{
	int x;
	int y;

	y = -1;
	a->z_max = 0;
	a->z_min = 0;
	while (++y < a->y_max)
	{
		x = -1;
		while (++x < a->x_max)
		{
			if (a->map[y][x].z > a->z_max)
				a->z_max = a->map[y][x].z;
			else if (a->map[y][x].z < a->z_min)
				a->z_min = a->map[y][x].z;
		}
	}
	a->e.z_len = a->z_max - a->z_min;
	put_color(a);
}

int			caralen(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
		{
			len++;
			while (str[i] && str[i] != ' ')
				i++;
		}
		else
			i++;
	}
	return (len);
}

void		ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

static void	readfile(t_a *a, char *str)
{
	char	*line;

	while ((a->e.tmp = get_next_line(a->e.fd, &line)) > 0)
	{
		if (a->y_max++ == 0)
			a->x_max = caralen(line);
		else if (a->x_max != caralen(line))
				ft_error("Found wrong line length. Exiting.");
		free(line);
	}
	close(a->e.fd);
	if (a->e.tmp == -1)
		ft_error("File can not be readed");
	if (a->x_max == 0)
		ft_error("No data found.");
	a->map = ft_newmap(a);
	a->e.fd = open(str, O_RDONLY);
	while ((get_next_line(a->e.fd, &line)) > 0 && a->e.tmp++ < a->y_max)
	{
		ft_creatmap(a, line, (a->e.tmp - 1));
		free(line);
	}
	close(a->e.fd);
}

int			main(int ac, char **av)
{
	t_a		a;

	a.x_max = 0;
	a.y_max = 0;
	a.k = 10;
	if (ac < 2)
		ft_error("usage: fdf fdf_file");
	if ((a.e.fd = open(av[1], O_RDONLY)) == -1)
		ft_error("File can not be opened");
	readfile(&a, av[1]);
	init(&a);
	clamp_z(&a);
	ft_print_image(&a);
	mlx_hook(a.e.win, 2, (1L << 01), my_fonct_key, &a);
	mlx_loop(a.e.mlx);
	return (0);
}
