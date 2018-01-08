/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:25:15 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/08 13:50:08 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_word(char *str)
{
	int i;
	int mot;

	mot = 0;
	i = 0;
	if (str[i] != ' ' && str[i] != '\t')
		mot++;
	while (str[i + 1])
	{
		if ((str[i] == ' ' || str[i] == '\t')
				&& str[i + 1] != ' ' && str[i + 1] != '\t')
			mot++;
		i++;
	}
	return (mot);
}

void		ft_get_size(t_param *p)
{
	int i;

	p->h = 0;
	p->s = 1000;
	i = 0;
	while (p->content[p->h])
		p->h++;
	p->l = count_word(p->content[0]);
	if (p->l > p->h)
		p->esp = (p->s) / (p->l * 2);
	else
		p->esp = (p->s) / (p->h * 2);
	if (p->esp <= 0)
		p->esp = 1;
}
