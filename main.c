/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:23:52 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/12/28 16:13:26 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	generate(t_param *p)
{
	ft_get_size(p);
	ft_stock_value(p);
	p->mlx = mlx_init();
	p->ptr_img = mlx_new_image(p->mlx, p->s, p->s);
	p->img_str = mlx_get_data_addr(p->ptr_img, &(p->bpp), &(p->sl), &(p->end));
	while (p->mid < (p->sl / 2))
		p->mid = p->mid + 4;
	p->x = p->mid / 4;
	p->y = 100;
	p->color1 = 255255255;
	p->color2 = 255255255;
	fill_cont_h(p);
	fill_cont_v(p);
	p->win = mlx_new_window(p->mlx, p->s, p->s, "fdf");
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_img, 0, 0);
	ft_show_info(p);
	mlx_hook(p->win, 2, 3, ft_events, p);
	mlx_loop(p->mlx);
}

int			main(int ac, char **av)
{
	t_param p;

	if (ac == 2)
	{
		p.hi = 1;
		p.bs = get_cont_size(av[1]);
		ft_get_cont(av[1], &p);
		if (check_map(&p) == 1)
		{
			generate(&p);
		}
		else
			ft_putstr("map error\n");
	}
	else
		ft_putstr("usage : ./fdf [file_path]\n");
	return (0);
}
