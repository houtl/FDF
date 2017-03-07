/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:14:03 by thou              #+#    #+#             */
/*   Updated: 2017/03/07 18:02:27 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124

typedef struct		s_environ
{
	char			*name;
	void			*mlx;
	void			*win;
	int				tmp;
	int				fd;
}					t_env;

typedef struct		s_fdfmap
{
	int				x;
	int				y;
	int				z;
	int				zo;
	int				color;
}					t_map;

typedef struct		s_all
{
	t_map			**map;
	t_env			e;
	int				x;
	int				y;
	int				x_max;
	int				y_max;

}					t_a;

/* fdf.c */

int			caralen(char *str);
void		ft_error(char *str);
static void	gnlvf(t_a *a, char *line);
static void	readfile(t_a *a, char *str);
int			main(int ac, char **av);

/* struct.c */

t_map		ft_newstruct(t_a *a);
void		ft_creatmap(t_a *a, char *str, int y);


#endif
