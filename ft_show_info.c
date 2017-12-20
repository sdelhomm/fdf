/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:24:03 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/12/18 11:20:57 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_show_info(t_param *p)
{
	char *scale;
	char *x;
	char *y;

	scale = (char*)malloc((8 + ft_strlen(ft_itoa(p->esp))) * sizeof(*scale));
	scale = ft_strjoin("Scale = ", ft_itoa(p->esp));
	mlx_string_put(p->mlx, p->win, 30, 30, 255255255, scale);
	x = (char*)malloc((4 + ft_strlen(ft_itoa(p->esp))) * sizeof(*scale));
	x = ft_strjoin("x = ", ft_itoa(p->x));
	mlx_string_put(p->mlx, p->win, 30, 45, 255255255, x);
	y = (char*)malloc((4 + ft_strlen(ft_itoa(p->esp))) * sizeof(*scale));
	y = ft_strjoin("y = ", ft_itoa(p->y));
	mlx_string_put(p->mlx, p->win, 30, 60, 255255255, y);
	mlx_string_put(p->mlx, p->win, 30, 75, 255255255, "Arrows to move");
	mlx_string_put(p->mlx, p->win, 30, 90, 255255255, "I/O = zoom in/out");
	mlx_string_put(p->mlx, p->win, 30, 105, 255255255, "ESC to leave");
	free(scale);
	free(x);
	free(y);
}
