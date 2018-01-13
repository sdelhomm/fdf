/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:24:49 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/11 13:21:11 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	reset_all(int kc, t_param *p)
{
	if (kc == ESP)
	{
		p->x = p->mid / 4;
		p->y = p->esp * 1.5;
		p->color1 = WHITE;
		p->color2 = WHITE;
		p->color3 = WHITE;
		p->hi = 0.5;
		p->zoom = 1;
		p->varx = 0;
		p->vary = 0;
	}
}

static void	events2(int kc, t_param *p)
{
	if (kc == K1)
	{
		p->color1 = DBLUE;
		p->color2 = DGREEN;
		p->color3 = BROWN;
	}
	if (kc == KD)
		p->varx += p->esp / 50;
	if (kc == KA)
		p->varx -= p->esp / 50;
	if (kc == KW)
	{
		p->vary += p->esp / 50;
		p->y -= 9;
	}
	if (kc == KS)
	{
		p->vary -= p->esp / 50;
		p->y += 9;
	}
}

static void	color(int kc, t_param *p)
{
	if (kc == K2)
	{
		p->color1 = YELLOW;
		p->color2 = PURPLE;
		p->color3 = p->color2;
	}
	if (kc == K3)
	{
		p->color1 = LGREEN;
		p->color2 = LRED;
		p->color3 = p->color2;
	}
	if (kc == K4)
	{
		p->color1 = DRED;
		p->color2 = LBLUE;
		p->color3 = p->color2;
	}
	if (kc == K5)
	{
		p->color1 = PINK;
		p->color2 = ORANGE;
		p->color3 = p->color2;
	}
}

static void	events(int kc, t_param *p)
{
	if (kc == ESC)
		exit(0);
	if (kc == PLUS)
		p->hi = p->hi + 0.1;
	if (kc == MINUS)
		p->hi = p->hi - 0.1;
	if (kc == KI)
		p->zoom *= 1.05;
	if (kc == KO)
		p->zoom /= 1.05;
	if (kc == UP)
		p->y = p->y - 5;
	if (kc == LEFT)
		p->x = p->x - 5;
	if (kc == RIGHT)
		p->x = p->x + 5;
	if (kc == DOWN)
		p->y = p->y + 5;
}

int			ft_events(int kc, t_param *p)
{
	events(kc, p);
	events2(kc, p);
	color(kc, p);
	reset_all(kc, p);
	p->espy = (p->esp + p->vary) * p->zoom;
	p->espx = (p->esp + p->varx) * p->zoom;
	mlx_destroy_image(p->mlx, p->ptr_img);
	p->ptr_img = mlx_new_image(p->mlx, p->s, p->s);
	fill_cont_h(p);
	fill_cont_v(p);
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_img, 0, 0);
	ft_show_info(p);
	return (0);
}
