/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:24:10 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/11 10:48:39 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	stocking(t_param *p, int c, int c2, int i2)
{
	int i;

	i = 0;
	while (p->content[c] && p->content[c] != NULL)
	{
		i2 = 0;
		c2 = 0;
		while (p->content[c][c2] != '\0')
		{
			if (p->content[c][c2] == ' ')
				c2++;
			else
			{
				p->cont[i][i2] = (ft_atoi(p->content[c] + c2));
				i2++;
				while (p->content[c][c2] != ' ' && p->content[c][c2] != '\0')
					c2++;
			}
		}
		p->tend = i2;
		c++;
		i++;
	}
}

void		ft_stock_value(t_param *p)
{
	int i;

	i = 0;
	if (!(p->cont = (int**)malloc((p->h + 1) * sizeof(int**))))
		mem_error();
	while (i < p->h)
	{
		if (!(p->cont[i] = (int*)malloc((p->l + 1) * sizeof(int*))))
			mem_error();
		i++;
	}
	stocking(p, 0, 0, 0);
	p->cont[p->h] = NULL;
}
