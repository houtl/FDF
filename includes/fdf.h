/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:14:03 by thou              #+#    #+#             */
/*   Updated: 2017/03/11 18:04:22 by thou             ###   ########.fr       */
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

# define WIDTH	1920
# define HEIGHT 1080

# define BACKGROUND 0x4C1B1B

typedef struct		s_environ
{
	char			*name;
	void			*mlx;
	void			*win;
	char			*data;
	int				tmp;
	int				fd;
	int				background;
	int				info;
	int				iso;
	void			*img;
	int				bpp;
	int				sl;
	int				ed;
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
int			main(int ac, char **av);

/* struct.c */

t_map		**ft_newstruct(t_a *a);
void		ft_creatmap(t_a *a, char *str, int y);
void		ft_errorf(char *str, t_a *a);

/* map.c */

void		init(t_a *a);
void		fdf_new_image(t_a *a);

#endif
