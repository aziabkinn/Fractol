/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flower.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 11:34:54 by aziabkin          #+#    #+#             */
/*   Updated: 2018/07/12 21:03:09 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	flower1(t_fractol *fr, t_window *wind, int x, int y)
{
	int i;

	fr->new_re = 1.5 * (x - S_W / 2) / (0.5 * fr->zoom * S_W) + fr->move_x;
	fr->new_im = (y - S_H / 2) / (0.5 * fr->zoom * S_H) + fr->move_y;
	i = -1;
	while (++i < fr->max_iter)
	{
		fr->old_re = fr->new_re;
		fr->old_im = fr->new_im;
		fr->new_re = log(fr->old_re * fr->old_re)
			- log(fr->old_im * fr->old_im) + fr->pr;
		fr->new_im = 2 * -(fr->old_re * fr->old_im) + fr->pi;
		if ((fr->new_re * fr->new_re + fr->new_im * fr->new_im) > 4)
			break ;
	}
	if (x >= 0 && y >= 0 && x < S_W && y < S_H)
	{
		if (i < fr->max_iter)
			wind->adress[y * S_W + x] = choose_col(fr->col_flag % 7, i);
		else
			wind->adress[y * S_W + x] = 0;
	}
}

void	flower(t_fractol *fr, t_window *wind)
{
	int x;
	int y;

	y = -1;
	while (++y < S_H)
	{
		x = -1;
		while (++x < S_W)
			flower1(fr, wind, x, y);
	}
	mlx_put_image_to_window(wind->mlx, wind->window, wind->image, 0, 0);
}
