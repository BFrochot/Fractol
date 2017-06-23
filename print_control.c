/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:37:23 by mleclair          #+#    #+#             */
/*   Updated: 2017/06/23 22:28:40 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		printcontrol(t_env *ev)
{
	mlx_string_put(ev->mlx, ev->win, 0, 0, 0xFF0000,
		"ROTATION: (PAV NUM) 4 / 6 / 8 / 2");
	mlx_string_put(ev->mlx, ev->win, 0, 20, 0xFF0000,
		"TRANSLATION: ARROW (OR W / A / S / D)");
	mlx_string_put(ev->mlx, ev->win, 0, 60, 0xFF0000,
		"DEEPNESS : (PAV NUM) 7 / 9");
	return (1);
}
