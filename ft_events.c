/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:24:49 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/08 13:33:41 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	reset_all(int kc, t_param *p)
{
	if (kc == 49)
	{
		p->x = p->mid / 4;
		p->y = p->esp * 6;
		p->color1 = 255255255;
		p->color2 = 255255255;
		p->color3 = 255255255;
		if (p->l > p->h)
			p->esp = (p->s) / (p->l * 2);
		else
			p->esp = (p->s) / (p->h * 2);
		if (p->esp <= 0)
			p->esp = 1;
		p->hi = 1;
		p->zoom = 1;
		p->varx = 0;
		p->vary = 0;
	}
}

static void	events2(int kc, t_param *p)
{
	if (kc == 18)
	{
		p->color1 = 165140025;
		p->color2 = 000255000;
		p->color3 = 000050150;
	}
	if (kc == 2)
		p->varx += p->esp / 50;
	if (kc == 0)
		p->varx -= p->esp / 50;
	if (kc == 13)
	{
		p->vary += p->esp / 50;
		p->y -= 9;
	}
	if (kc == 1)
	{
		p->vary -= p->esp / 50;
		p->y += 9;
	}
}

static void	color(int kc, t_param *p)
{
	if (kc == 20)
	{
		p->color1 = 100255050;
		p->color2 = 000000255;
		p->color3 = p->color2;
	}
	if (kc == 21)
	{
		p->color1 = 100050200;
		p->color2 = 250090000;
		p->color3 = p->color2;
	}
	if (kc == 23)
	{
		p->color1 = 255000255;
		p->color2 = 000255255;
		p->color3 = p->color2;
	}
	if (kc == 19)
	{
		p->color1 = 010200050;
		p->color2 = 200030100;
		p->color3 = p->color2;
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
		p->zoom *= 1.05;
	}
	if (kc == 31)
	{
		p->zoom /= 1.05;
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
	events2(kc, p);
	color(kc, p);
	reset_all(kc, p);
	p->espy = ((p->esp / 1.2) + p->vary) * p->zoom;
	p->espx = ((p->esp / 1.2) + p->varx) * p->zoom;
	mlx_destroy_image(p->mlx, p->ptr_img);
	p->ptr_img = mlx_new_image(p->mlx, p->s, p->s);
	fill_cont_h(p);
	fill_cont_v(p);
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_img, 0, 0);
	ft_show_info(p);
	return (0);
}
