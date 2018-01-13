/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:14:32 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/11 13:21:13 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define ABS(Value) (Value < 0 ? -Value : Value)

typedef struct	s_param
{
	void	*mlx;
	void	*win;
	void	*ptr_img;
	char	*img_str;
	int		bpp;
	int		sl;
	int		end;
	int		**cont;
	char	**content;
	int		s;
	int		bs;
	double	varx;
	double	vary;
	double	esp;
	double	espx;
	double	espy;
	double	zoom;
	int		x;
	int		y;
	int		mid;
	int		h;
	int		l;
	double	hi;
	int		color;
	int		color1;
	int		color2;
	int		color3;
	int		tend;
}				t_param;

typedef struct	s_draw
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		c;
	int		c2;
	int		z;
	double	v;
	double	ov;
	double	x;
	double	y;
}				t_draw;

# define WHITE 255255255
# define BLACK 000000000
# define LBLUE 000255255
# define DBLUE 165140025
# define LGREEN 100050200
# define DGREEN 000255000
# define YELLOW 100255050
# define PURPLE 000000255
# define LRED 250090000
# define DRED 255000255
# define ORANGE 200030100
# define PINK 010200050
# define BROWN 000050150

# define ESC 53
# define K1 18
# define K2 20
# define K3 21
# define K4 23
# define K5 19
# define PLUS 69
# define MINUS 78
# define KI 34
# define KO 31
# define KW 13
# define KA 0
# define KS 1
# define KD 2
# define ESP 49
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

void			fill_cont_h(t_param *p);

void			fill_cont_v(t_param *p);

void			ft_bresenham(t_draw *b, t_param *p);

int				ft_events(int kc, t_param *p);

void			ft_get_size(t_param *p);

void			ft_stock_value(t_param *p);

int				get_cont_size(char *file);

int				check_map(t_param *p);

void			ft_get_cont(char *file, t_param *p);

void			ft_show_info(t_param *p);

void			mem_error();

#endif
