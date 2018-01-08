/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cont_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:26:40 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/01/08 14:20:38 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_cont_size(char *file)
{
	char	*buf[1];
	int		fd;
	int		bs;

	bs = 0;
	fd = open(file, O_RDONLY);
	if (read(fd, buf, 0) < 0)
	{
		ft_putstr("Can't find map\n");
		exit(0);
	}
	while ((read(fd, buf, 1)))
		bs++;
	close(fd);
	return (bs);
}
