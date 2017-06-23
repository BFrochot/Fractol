/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:08:24 by mleclair          #+#    #+#             */
/*   Updated: 2017/06/23 22:47:36 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		hook(int x, int y, t_env *e)
{
	e->mlx = e->save;
	printf("hook : mlx = %p et win = %p\n", e->mlx, e->win);
	printf("x = %d et y = %d\n", x, y);
	// if (x > e->oldx)
	// 	e->rc += 0.005 / e->z;
	// else
	// 	e->rc -= 0.005 / e->z;
	// if (y > e->oldy)
	// 	e->ic += 0.005 / e->z;
	// else
	// 	e->ic -= 0.005 / e->z;
	// e->oldx = x;
	// e->oldy = y;
	// if (e->img)
	// 	mlx_destroy_image(e->mlx, e->img);
	// e->img = mlx_new_image(e->mlx, 1.5 * e->winx, 1.5 * e->winy);
	// e->p_img = mlx_get_data_addr(e->img, &e->bpp, &(e->s_line), &(e->ed));
	fdfinit(e);
	return (0);
}

int	mouse(int button, int x, int y, t_env *ev)
{
	(void)x;
	(void)y;

	printf("MOUSE : mlx = %p et win = %p\n", ev->mlx, ev->win);
	if (button == 4)
	{
		ev->z *= 1.1;
		if ((int)ev->z % 10 == 0)
			ev->iter *= 1.1;
	}
	else if (button == 5)
	{
		ev->z /= 1.1;
		if ((int)ev->z % 10 == 0)
			ev->iter /= 1.1;
	}
	else if (button == 1)
	{
		ev->rc = -0.7;
		ev->ic = 0.27015;
	}
	if (ev->img)
		mlx_destroy_image(ev->mlx, ev->img);
	ev->img = mlx_new_image(ev->mlx, ev->winx, ev->winy);
	ev->p_img = mlx_get_data_addr(ev->img, &ev->bpp, &(ev->s_line), &(ev->ed));
	fdfinit(ev);
	return (0);
}

void	trace(char i)
{
	t_env	*ev;

	ev = palloc(sizeof(t_env));
	initev(ev);
	ev->c = i;
	if (!(ev->mlx = mlx_init()) || !(ev->win = mlx_new_window(ev->mlx,
	ev->winx, ev->winy, "Fractol")) || !(ev->img = mlx_new_image(ev->mlx,
	1.5 * ev->winx, 1.5 * ev->winy)) || !(ev->p_img = mlx_get_data_addr(ev->img,
	&ev->bpp, &(ev->s_line), &(ev->ed))))
		error(-2);
	ev->save = ev->mlx;
	printf("Trace : mlx = %p et win = %p\n", ev->mlx, ev->win);
	mlx_key_hook(ev->win, keymap, ev);
	// mlx_mouse_hook(ev->win, mouse, ev);
	mlx_expose_hook(ev->win, fdfinit, ev);
	mlx_hook(ev->win, 6, (1L << 6), hook, &ev);
	mlx_loop(ev->mlx);
	printf("Trace : mlx = %p et win = %p\n", ev->mlx, ev->win);
}

char	isfractal(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	if (!ft_strcmp(str, "julia"))
		return (1);
	if (!ft_strcmp(str, "mandelbrot"))
		return (2);
	return (0);
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 1)
		error(-1);
	else
	{
		while (++i < ac)
		{
			if (!isfractal(av[i]))
				error(-1);
		}
		while (--ac)
			trace(isfractal(av[ac]));
	}
	return (0);
}
