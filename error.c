/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 12:36:19 by bfrochot          #+#    #+#             */
/*   Updated: 2017/06/23 23:00:36 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(int i)
{
	if (i == -1)
		ft_putstr("Usage : ./fractol [Julia][Mandelbrot][][][]\n");
	else if (i == -2)
		ft_putstr("You broke mlx\n");
	else if (i == -3)
		ft_putstr("malloc error, please hang yourself\n");
	exit(-1);
}

void	*palloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		error(-3);
	return (ptr);
}
