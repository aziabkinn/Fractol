/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 13:49:13 by aziabkin          #+#    #+#             */
/*   Updated: 2018/07/12 21:08:02 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_window		*new_window(void)
{
	t_window	*new;

	new = (t_window *)malloc(sizeof(t_window));
	new->image = NULL;
	new->window = NULL;
	new->adress = NULL;
	new->endian = 0;
	new->size_line = 0;
	new->bpp = 0;
	return (new);
}

void			create_window(t_window **wind)
{
	(*wind)->mlx = mlx_init();
	(*wind)->window = mlx_new_window((*wind)->mlx, S_W, S_H,
								"Project FRACTOL aziabkin");
}
