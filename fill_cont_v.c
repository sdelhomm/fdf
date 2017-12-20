/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cont_v.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:27:43 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/12/20 11:27:46 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_send(t_param *p, t_draw *b)
{
	b->v = (p->cont[b->c + 1][b->c2]) * p->hi;
	b->x1 = b->x + ((p->esp / 3.3) * b->ov);
	b->y1 = b->y - ((p->esp / 2.3) * b->ov);
	b->x2 = (b->x - p->esp) + ((p->esp / 3.3) * b->v);
	b->y2 = (b->y + p->esp) - ((p->esp / 2.3) * b->v);
	if (b->ov == 0 && b->v == 0)
		p->color = p->color1;
	else
		p->color = p->color2;
	ft_bresenham(b, p);
	b->x = b->x - p->esp;
	b->y = b->y + p->esp;
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
	while (p->cont[b.c][b.c2] != 69696969)
	{
		b.z = 0;
		b.ov = (p->cont[b.c][b.c2] * p->hi);
		while (p->cont[b.c + 1] && p->cont[b.c + 1] != NULL)
		{
			ft_send(p, &b);
		}
		b.x = (b.x + (p->esp * b.z)) + p->esp;
		b.y = (b.y - (p->esp * b.z)) + p->esp;
		b.c2++;
		b.c = 0;
	}
}
