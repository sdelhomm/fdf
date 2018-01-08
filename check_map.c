/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:38:35 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/12/30 15:46:51 by sdelhomm         ###   ########.fr       */
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

int			check_map(t_param *p)
{
	int i;
	int n;

	n = count_word(p->content[0]);
	i = 1;
	while (p->content[i])
	{
		if (count_word(p->content[i]) != n)
			return (0);
		i++;
	}
	return (1);
}
