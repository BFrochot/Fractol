/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:36:29 by mleclair          #+#    #+#             */
/*   Updated: 2017/06/23 22:41:48 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initev(t_env *ev)
{
	ev->array = NULL;
	ev->rx = -60;
	ev->ry = 60;
	ev->winx = 2560;
	ev->winy = 1440;
	ev->zoom = 1;
	ev->p = ev->zoom / 10;
	ev->tx = 0;
	ev->ty = ev->len / 2;
	ev->px = 0;
	ev->py = 0;
	ev->mx = 0;
	ev->my = 0;
	ev->c = 1;

	ev->rc = -0.7;
	ev->ic = 0.27015;
	ev->z = 1;
	ev->movex = 0;
	ev->movey = 0;
	ev->iter = 150;
	ev->col = 0x0000ef;
	ev->oldx = 200;
	ev->oldy = 200;
}
