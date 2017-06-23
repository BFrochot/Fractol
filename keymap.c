/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:25:18 by mleclair          #+#    #+#             */
/*   Updated: 2017/06/23 22:31:33 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keymap2(int keycode, t_env *ev)
{
	if (keycode == 86 || keycode == 88)
		ev->rx += keycode == 86 ? 10 : -10;
	else if (keycode == 91)
		ev->ry += 10;
	else if (keycode == 84)
		ev->ry -= 10;
	else if (keycode == 89)
		ev->p -= ev->zoom / 10;
	else if (keycode == 92)
		ev->p += ev->zoom / 10;
	else if (keycode == 87)
		ev->c = ev->c == 2 ? 0 : ev->c + 1;
}

int		keymap(int keycode, t_env *ev)
{

	printf("Keymap : mlx = %p et win = %p\n", ev->mlx, ev->win);
	if (keycode == 53)
		exit(0);
	else if (keycode == 2 || keycode == 124)
		ev->tx -= 100 / ev->zoom > 1 ? 100 / ev->zoom : 1;
	else if (keycode == 0 || keycode == 123)
		ev->tx += 100 / ev->zoom > 1 ? 100 / ev->zoom : 1;
	else if (keycode == 13 || keycode == 126)
		ev->ty += 100 / ev->zoom > 1 ? 100 / ev->zoom : 1;
	else if (keycode == 1 || keycode == 125)
		ev->ty -= 100 / ev->zoom > 1 ? 100 / ev->zoom : 1;
	else if (keycode == 78 && ev->zoom > ev->winx * 0.25 / ev->len)
		ev->zoom -= ev->winx * 0.25 / ev->len;
	else if (keycode == 69)
		ev->zoom += ev->winx * 0.25 / ev->len;
	keymap2(keycode, ev);
	fdfinit(ev);
	printf("Keymap : mlx = %p et win = %p\n", ev->mlx, ev->win);
	return (0);
}
