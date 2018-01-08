/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:24:03 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/08 16:05:37 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_info(char *zoom, char *x, char *y, t_param *p)
{
	mlx_string_put(p->mlx, p->win, 30, 30, 255255255, zoom);
	mlx_string_put(p->mlx, p->win, 30, 45, 255255255, x);
	mlx_string_put(p->mlx, p->win, 30, 60, 255255255, y);
	mlx_string_put(p->mlx, p->win, 30, 75, 255255255, "Arrows to move");
	mlx_string_put(p->mlx, p->win, 30, 90, 255255255, "WASD to move POV");
	mlx_string_put(p->mlx, p->win, 30, 105, 255255255, "I/O = zoom in/out");
	mlx_string_put(p->mlx, p->win, 30, 120, 255255255, "ESC to leave");
}

void		ft_show_info(t_param *p)
{
	char *zoom;
	char *x;
	char *y;
	char *tmp[3];

	tmp[0] = ft_itoa(p->zoom);
	if (!(zoom = (char*)malloc((8 +
		ft_strlen(tmp[0])) * sizeof(*zoom))))
		exit(0);
	ft_strbuild(&zoom, "Zoom = X", tmp[0]);
	tmp[1] = ft_itoa(p->x);
	if (!(x = (char*)malloc((4 + ft_strlen(tmp[1])) * sizeof(*zoom))))
		exit(0);
	ft_strbuild(&x, "x = ", tmp[1]);
	tmp[2] = ft_itoa(p->y);
	if (!(y = (char*)malloc((4 + ft_strlen(tmp[2])) * sizeof(*zoom))))
		exit(0);
	ft_strbuild(&y, "y = ", tmp[2]);
	put_info(zoom, x, y, p);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(zoom);
	free(x);
	free(y);
}
