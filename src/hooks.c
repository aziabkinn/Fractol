/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 15:21:18 by aziabkin          #+#    #+#             */
/*   Updated: 2018/07/12 21:42:49 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			exit_x(int key, t_structs *strs)
{
	(void)strs;
	(void)key;
	exit(0);
	return (0);
}

int			julia_mouse(int x, int y, t_structs *strs)
{
	if (!strs->fr->set)
	{
		strs->fr->pr = (x - 300) / 128.0;
		strs->fr->pi = (y - 300) / 128.0;
		fractol(strs->fr->name, strs);
	}
	return (0);
}

int			zoom_mouse(int key, int x, int y, t_structs *strs)
{
	if (x >= 0 && y >= 0 && x < S_W && y < S_H)
	{
		if (key == SCROLL_UP)
			strs->fr->zoom *= 1.3;
		else if (key == SCROLL_DOWN)
			strs->fr->zoom /= 1.3;
		fractol(strs->fr->name, strs);
	}
	return (0);
}

void		handle1(int key, t_structs *strs)
{
	if (key == 24)
		strs->fr->zoom *= 1.3;
	else if (key == 27)
		strs->fr->zoom /= 1.3;
	else if (key == 49)
	{
		if (strs->fr->set)
			strs->fr->set = 0;
		else
			strs->fr->set = 1;
	}
	else if (key == 12)
		strs->fr->col_flag++;
}

int			hadle_input_key(int key, t_structs *strs)
{
	if (key == 53)
		exit_x(key, strs);
	else if (key == 18)
		strs->fr->max_iter += 10;
	else if (key == 19)
		strs->fr->max_iter -= 10;
	else if (key == 0)
		strs->fr->move_x += 0.01;
	else if (key == 2)
		strs->fr->move_x -= 0.01;
	else if (key == 13)
		strs->fr->move_y += 0.01;
	else if (key == 1)
		strs->fr->move_y -= 0.01;
	handle1(key, strs);
	fractol(strs->fr->name, strs);
	hints(strs);
	return (0);
}
