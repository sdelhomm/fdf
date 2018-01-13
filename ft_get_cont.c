/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cont.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:26:29 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/11 10:36:21 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_cont(char *file, t_param *p)
{
	char	*tmp;
	int		fd;

	tmp = ft_strnew((p->bs));
	fd = open(file, O_RDONLY);
	read(fd, tmp, p->bs);
	close(fd);
	p->content = ft_strsplit(tmp, '\n');
	free(tmp);
}
