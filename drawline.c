/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 12:35:55 by bfrochot          #+#    #+#             */
/*   Updated: 2017/06/23 23:00:30 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(int x, int y, int color, t_env *ev)
{
	if (x < 0 || y < 0)
		return ;
	if (x > ev->winx || y > ev->winy)
		return ;
	((int *)ev->p_img)[x + y * ev->s_line / 4] = color;
}
