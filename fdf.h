/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 12:37:45 by bfrochot          #+#    #+#             */
/*   Updated: 2017/06/25 17:40:46 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "./libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

# define BUFF_SIZE 32
# define LEN_LINE 20

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		fd;
	int		tx;
	int		ty;
	int		rx;
	int		ry;
	float	p;
	int		len;
	double	zoom;
	int		winx;
	int		winy;
	int		max;
	int		min;
	void	*img;
	char	*p_img;
	int		bpp;
	int		s_line;
	int		ed;
	double	px;
	double	py;
	double	mx;
	double	my;
	char	c;

	double rc;
	double ic;
	double z;
	double movex;
	double movey;
	int iter;
	int col;
	int oldx;
	int oldy;
}				t_env;

typedef struct	s_complex
{
	double	r;
	double	i;
}				t_complex;

void			error(int i);
void			*palloc(size_t size);
int				get_next_line(const int fd, char **line);
int				keymap(int keycode, t_env *ev);
char			**ft_strsplitquote(char const *s, char c, char tab);
int				fdfinit(t_env *ev);
int				colorline(double i, t_env *ev);
int				colorline2(double i, t_env *ev);
int				printcontrol(t_env *ev);
void			draw_line(double *pts1, double *pts2, t_env *ev);
void			initev(t_env *ev);
int				printcontrol(t_env *ev);
void			put_pixel(int x, int y, int color, t_env *ev);

#endif
