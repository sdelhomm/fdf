/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:27:53 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/08 14:20:10 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fill_pixel(int x, int y, t_param *p)
{
	int i;
	int color;

	color = p->color;
	i = (x * 4) + (y * p->sl);
	if (x < (p->sl / 4) && y < (p->sl / 4) && x > 0 && y > 0)
	{
		p->img_str[i + 2] = color % 1000;
		color = color / 1000;
		p->img_str[i + 1] = color % 1000;
		color = color / 1000;
		p->img_str[i] = color % 1000;
	}
}

static void		draw_line_pta(int x, int y, t_draw *b, t_param *p)
{
	x = b->x1;
	while (x < b->x2)
	{
		y = b->y1 + ((b->y2 - b->y1) * (x - b->x1)) / (b->x2 - b->x1);
		fill_pixel(x, y, p);
		++x;
	}
}

static void		draw_line_ptb(int x, int y, t_draw *b, t_param *p)
{
	y = b->y1;
	while (y < b->y2)
	{
		x = b->x1 + ((b->x2 - b->x1) * (y - b->y1)) / (b->y2 - b->y1);
		fill_pixel(x, y, p);
		++y;
	}
}

void			ft_bresenham(t_draw *b, t_param *p)
{
	int x;
	int y;

	x = b->x1 - b->x2;
	y = b->y1 - b->y2;
	x = ABS(x);
	y = ABS(y);
	if (x > y)
	{
		if (b->x1 > b->x2)
		{
			ft_swap(&b->x1, &b->x2);
			ft_swap(&b->y1, &b->y2);
		}
		draw_line_pta(x, y, b, p);
	}
	else
	{
		if (b->y1 >= b->y2)
		{
			ft_swap(&b->x1, &b->x2);
			ft_swap(&b->y1, &b->y2);
		}
		draw_line_ptb(x, y, b, p);
	}
}
