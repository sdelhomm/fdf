/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:24:49 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/12/20 12:31:01 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	color(int kc, t_param *p)
{
	if (kc == 18)
	{
		p->color1 = 165140025;
		p->color2 = 000255000;
	}
	if (kc == 19)
	{
		p->color1 = 010200050;
		p->color2 = 200030100;
	}
	if (kc == 20)
	{
		p->color1 = 102122214;
		p->color2 = 140040190;
	}
	if (kc == 21)
	{
		p->color1 = 255000050;
		p->color2 = 000255000;
	}
	if (kc == 23)
	{
		p->color1 = 145177011;
		p->color2 = 169104116;
	}
}

static void	events(int kc, t_param *p)
{
	if (kc == 53)
		exit(0);
	if (kc == 69)
		p->hi = p->hi + 0.1;
	if (kc == 78)
		p->hi = p->hi - 0.1;
	if (kc == 34)
	{
		p->esp = p->esp + 1;
		p->y = p->y - 20;
	}
	if (kc == 31 && p->esp > 1)
	{
		p->esp = p->esp - 1;
		p->y = p->y + 20;
	}
	if (kc == 126)
		p->y = p->y - 5;
	if (kc == 123)
		p->x = p->x - 5;
	if (kc == 124)
		p->x = p->x + 5;
	if (kc == 125)
		p->y = p->y + 5;
}

int			ft_events(int kc, t_param *p)
{
	events(kc, p);
	color(kc, p);
	mlx_destroy_image(p->mlx, p->ptr_img);
	p->ptr_img = mlx_new_image(p->mlx, p->s, p->s);
	fill_cont_h(p);
	fill_cont_v(p);
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_img, 0, 0);
	ft_show_info(p);
	return (0);
}
