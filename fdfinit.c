/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 12:20:17 by bfrochot          #+#    #+#             */
/*   Updated: 2017/07/03 11:13:15 by bfrochot         ###   ########.fr       */
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
	while (x < 1000)
	{
		y = 0;
		while (y < 1000)
		{
			n.r = 1.5 * (x - 1000 / 2) / (0.5 * e->z * 1000) + e->movex;
			n.i = (y - 1000 / 2) / (0.5 * e->z * 1000) + e->movey;
			color = (e->col * (ft_is_julia(&n, e) % 0xff));
			put_pixel(x, y, color, e);
			y++;
		}
		x++;
	}
}

int		ft_is_mandel(t_complex *new, t_env *e)
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

void	ft_mandel(t_env *e)
{
	t_complex	n;
	int			color;
	int			x;
	int			y;

	x = 0;
	while (x < 1000)
	{
		y = 0;
		while (y < 1000)
		{
			n.r = 1.5 * (x - 1000 / 2) / (0.5 * e->z * 1000) + e->movex;
			n.i = (y - 1000 / 2) / (0.5 * e->z * 1000) + e->movey;
			n.r = x;
			n.i = y;
			color = (e->col * (ft_is_mandel(&n, e) % 0xff));
			put_pixel(x, y, color, e);
			y++;
		}
		x++;
	}
}

int		fdfinit(t_env *ev)
{
	if (ev->c == 1)
		ft_draw_julia(ev);
	if (ev->c == 2)
		ft_mandel(ev);
	mlx_put_image_to_window(ev->mlx, ev->win, ev->img, 0, 0);
	return (printcontrol(ev));
}
