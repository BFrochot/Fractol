/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:20:17 by mleclair          #+#    #+#             */
/*   Updated: 2017/06/23 22:52:55 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_is_julia(t_complex *new, t_env *e)
{
	t_complex	old;
	int			i;

	i = 0;
	while (i < e->iter)
	{
		old.r = new->r;
		old.i = new->i;
		new->r = old.r * old.r - old.i * old.i + e->rc;
		new->i = 2 * old.r * old.i + e->ic;
		if ((new->r * new->r + new->i * new->i) > 4)
			break ;
		i++;
	}
	return (i);
}

void	ft_draw_julia(t_env *e)
{
	t_complex	n;
	int			color;
	int			x;
	int			y;

	x = 0;
	while (x < 2560)
	{
		y = 0;
		while (y < 1440)
		{
			n.r = 1.5 * (x - 800 / 2) / (0.5 * e->z * 800) + e->movex;
			n.i = (y - 800 / 2) / (0.5 * e->z * 800) + e->movey;
			color = (e->col * (ft_is_julia(&n, e) % 0xff));
			put_pixel(x, y, color, e);
			y++;
		}
		x++;
	}
}

int		fdfinit(t_env *ev)
{
	printf("Init : mlx = %p et win = %p\n", ev->mlx, ev->win);
	mlx_clear_window(ev->mlx, ev->win);
	mlx_destroy_image(ev->mlx, ev->img);
	ev->img = mlx_new_image(ev->mlx, 1.5 * ev->winx, 1.5 * ev->winy);
	ev->p_img = mlx_get_data_addr(ev->img, &ev->bpp, &(ev->s_line), &(ev->ed));
	ft_draw_julia(ev);
	mlx_put_image_to_window(ev->mlx, ev->win, ev->img, 0, 0);
	printf("Init : mlx = %p et win = %p\n", ev->mlx, ev->win);
	return (printcontrol(ev));
}
