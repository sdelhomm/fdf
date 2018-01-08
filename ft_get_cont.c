/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cont.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:26:29 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/12/30 15:46:56 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_cont(char *file, t_param *p)
{
	char	*tmp;
	int		fd;

	tmp = (char*)malloc((p->bs) * sizeof(*tmp));
	fd = open(file, O_RDONLY);
	read(fd, tmp, p->bs);
	close(fd);
	p->content = ft_strsplit(tmp, '\n');
	free(tmp);
}
