/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cont_v.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:27:43 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/11 13:12:15 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_send(t_param *p, t_draw *b)
{
	b->v = (p->cont[b->c + 1][b->c2]) * p->hi;
	b->x1 = b->x + ((p->espy / 3.3) * b->ov);
	b->y1 = b->y - ((p->espx / 2.3) * b->ov);
	b->x2 = (b->x - p->espx) + ((p->espy / 3.3) * b->v);
	b->y2 = (b->y + p->espy) - ((p->espx / 2.3) * b->v);
	if ((b->ov > -0.5 && b->ov < 0.5) && (b->v > -0.5 && b->v < 0.5))
		p->color = p->color1;
	else if ((b->ov > 30 && b->v > 30) || (b->ov < -30 && b->v < -30))
		p->color = p->color3;
	else
		p->color = p->color2;
	ft_bresenham(b, p);
	b->x = b->x - p->espx;
	b->y = b->y + p->espy;
	b->c++;
	b->z++;
	b->ov = b->v;
}

void		fill_cont_v(t_param *p)
{
	t_draw b;

	b.x = p->x;
	b.y = p->y;
	b.c2 = 0;
	b.c = 0;
	b.ov = 0;
	b.v = 0;
	while (b.c2 < p->tend)
	{
		b.z = 0;
		b.ov = (p->cont[b.c][b.c2] * p->hi);
		while (p->cont[b.c + 1] && p->cont[b.c + 1] != NULL)
		{
			ft_send(p, &b);
		}
		b.x = (b.x + (p->espx * b.z)) + p->espx;
		b.y = (b.y - (p->espy * b.z)) + p->espy;
		b.c2++;
		b.c = 0;
	}
}
