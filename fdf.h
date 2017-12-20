/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:14:32 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/12/14 19:23:18 by sdelhomm         ###   ########.fr       */
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
	int		esp;
	int		x;
	int		y;
	int		mid;
	int		h;
	int		l;
	float	hi;
	int		color;
	int		color1;
	int		color2;
}				t_param;

typedef struct	s_draw
{
	int x1;
	int y1;
	int x2;
	int y2;
	int c;
	int c2;
	int z;
	int v;
	int ov;
	int x;
	int y;
}				t_draw;

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

#endif