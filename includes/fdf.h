/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:14:03 by thou              #+#    #+#             */
/*   Updated: 2017/03/16 16:14:46 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

# define WHITE		0xFFFFFF
# define BLUE		0x0901F7
# define BLUE_C		0x015BF7
# define SKY		0x01B5F7
# define LAGON		0x33AB9B
# define WGREEN		0x01F79D
# define RAZER		0x01F74B
# define LIMON		0xADF701
# define YELLOW		0xEFF701
# define ORANGE		0xF78C01
# define RED		0xFE4D01
# define BACKGROUND	0x4C1B1B

# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124
# define EXIT	53
# define ISO_Z	6
# define HELP	4
# define BG		11
# define ISO	34
# define HIGH	13
# define LOW	1
# define GRAND	69
# define PETIT	78
# define ORIGIN	15
# define ORIGIN_Z 0

# define WIDTH	1920
# define HEIGHT 1080

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
	double			z_len;
}					t_env;

typedef struct		s_point
{
	int				x;
	int				y;
	int				c;
}					t_p;

typedef struct		s_fdfmap
{
	double			x;
	double			y;
	double			z;
	double			zo;
	int				color;
	int				fc;
}					t_map;

typedef struct		s_bresenham
{
	int				dx;
	int				dy;
	int				i;
	int				xinc;
	int				yinc;
	int				cumul;
	int				x;
	int				y;
}					t_b;

typedef struct		s_all
{
	t_map			**map;
	t_env			e;
	t_p				p1;
	t_p				p2;
	t_b				b;
	int				x;
	int				y;
	int				x_max;
	int				y_max;
	double			z_max;
	double			z_min;
	double			x_mid;
	double			y_mid;
	double			k;
}					t_a;

/* fdf.c */

void		clamp_z(t_a *a);
int			caralen(char *str);
void		ft_error(char *str);
int			main(int ac, char **av);

/* map.c */

t_map		**ft_newmap(t_a *a);
void		ft_creatmap(t_a *a, char *str, int y);
void		ft_errorf(char *str, t_a *a);

/* image.c */

void		init(t_a *a);
void		fdf_new_image(t_a *a);

/* color.c */

void		put_color(t_a *a);
int			loca_color(t_a *a, int z);

/* print.c */

int			recover_point(t_a *a, int x, int y, char c);
void		ft_print_image_x(t_a *a, int x, int y);
void		ft_print_image(t_a *a);

/* ligne.c */

void		ligne(t_a *a, int color);

/* key.c */

int			my_fonct_key(int keycode, t_a *a);

#endif
