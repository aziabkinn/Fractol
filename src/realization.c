/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realization.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:43:37 by aziabkin          #+#    #+#             */
/*   Updated: 2018/07/13 09:32:31 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	choose_col(int n, int i)
{
	if (!n)
		return (color(250 - (i % 256),\
			255 - ((i * 30) % 256), 252 - ((i * 51) % 256)));
	else if (n == 1)
		return (color(255 - (i * 232 % 256),\
			255 - ((i * 510) % 256), 255 - ((i * 232) % 256)));
	else if (n == 2)
		return (color(((i * 100) % 256),\
			(5 - (i * 20) % 200), ((i * 175) % 200)));
	else if (n == 3)
		return (color(255 - (i * 30 % 256),\
			255 - ((i * 5) % 256), 255 - ((i * 2) % 256)));
	else if (n == 4)
		return (color((i % 256),\
			((i * 30) % 256), ((i * 5) % 256)));
	else if (n == 5)
		return (color(255 - (i * 252 % 256),\
			255 - ((i * 500) % 256), 255 - ((i * 500) % 256)));
	else if (n == 6)
		return (color(255 - (i * 0),\
			255 - ((i * 80) % 256), 200 - ((i * 450) % 256)));
		return (0);
}

int				color(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void			fractol(char *str, t_structs *strs)
{
	if (ft_strequ(str, "Mandelbrot"))
		mandelbrot(strs->fr, strs->wind);
	else if (ft_strequ(str, "Julia"))
		julia(strs->fr, strs->wind);
	else if (ft_strequ(str, "Burning_ship"))
		burning_ship(strs->fr, strs->wind);
	else if (ft_strequ(str, "Tricorn"))
		tricorn(strs->fr, strs->wind);
	else if (ft_strequ(str, "Flower"))
		flower(strs->fr, strs->wind);
	else
		error_exit(1);
	hints(strs);
}

void			realization(char *str, t_fractol *fr)
{
	fr->name = str;
	fr->move_x = 0;
	fr->move_y = 0;
	fr->zoom = 0.6;
	fr->max_iter = 128;
	fr->color = 0;
	fr->set = 0;
	fr->mouse = 0;
	fr->col_flag = 0;
}
