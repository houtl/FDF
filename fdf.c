/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:13:57 by thou              #+#    #+#             */
/*   Updated: 2017/03/02 18:02:55 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static void	vf_gnl(t_a *a, char *line)
{
	if (a->e.tmp == -1)
		ft_error("Not a good file");
	if (a->x_max == 0 || a->y_max == 0)
		ft_error("Empty File");
	close(a->e.fd);
}


static int	readfile(t_a *a, char *str)
{
	char	*line;

	while ((a->e.tmp = get_next_line(a->e.fd, &line)))
	{
		if (a->y_max == 0)
			a->x_max = caralen(line);
		if (a->y_max != 0)
			if(a->x_max != caralen(line))
				ft_error("Found wrong line length. Exiting.");
		a->y_max++;
		free(line);
	}
	vf_gnl(a, line);
}

int			main(int ac, char **av)
{
	t_a		a;

	if (ac < 2)
		ft_error("usage: fdf fdf_file");
	if (!(a.e.fd = open(av[1], O_RDONLY)))
		ft_error("File can not be opened");
	readfile(&a, av[1]);
}
