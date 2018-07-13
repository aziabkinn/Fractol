/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 13:49:03 by aziabkin          #+#    #+#             */
/*   Updated: 2018/07/13 15:14:47 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			hints(t_structs *st)
{
	mlx_string_put(st->wind->mlx, st->wind->window, 10, 10, 0xFFB3B3,\
		"Change of size: + - or mouse: SCROLL_UP, SCROLL_DOWN");
	mlx_string_put(st->wind->mlx, st->wind->window, 10, 35, 0xFFB3B3,\
		"Change of iteration: 1, 2");
	mlx_string_put(st->wind->mlx, st->wind->window, 10, 60, 0xFFB3B3,\
		"Move: A D W S");
	mlx_string_put(st->wind->mlx, st->wind->window, 10, 85, 0xFFB3B3,\
		"Change of color: Q");
	mlx_string_put(st->wind->mlx, st->wind->window, 10, 110, 0xFFB3B3,\
		"Close window: [esc]");
	if (ft_strequ(st->fr->name, "Julia") || ft_strequ(st->fr->name, "Flower"))
	{
		mlx_string_put(st->wind->mlx, st->wind->window, 10, 135, 0xFFB3B3,\
		"Mouse move");
		mlx_string_put(st->wind->mlx, st->wind->window, 10, 160, 0xFFB3B3,\
		"Stop move: [space]");
	}
}

void			error_exit(int a)
{
	if (a == 1)
		ft_putstr("usage: ./fractol [name]\n\n You choose such fractals:\
		\n * Mandelbrot\n * Julia\n * Burning_ship\n * Tricorn\n * Flower\n");
	exit(0);
}

int				valid_name(char *str)
{
	return (ft_strequ(str, "Mandelbrot") || ft_strequ(str, "Julia")\
			|| ft_strequ(str, "Burning_ship") || ft_strequ(str, "Tricorn")\
			|| ft_strequ(str, "Flower"));
}

void			main1(t_structs *strs)
{
	mlx_hook(strs->wind->window, 2, 0, hadle_input_key, strs);
	mlx_hook(strs->wind->window, 17, 0, exit_x, strs);
	mlx_hook(strs->wind->window, 6, 0, julia_mouse, strs);
	mlx_mouse_hook(strs->wind->window, zoom_mouse, strs);
	mlx_loop(strs->wind->mlx);
}

int				main(int argc, char **argv)
{
	t_structs *strs;

	if (argc != 2 || !valid_name(argv[1]))
		error_exit(1);
	if (!(strs = (t_structs *)malloc(sizeof(t_structs))))
		return (0);
	if (!(strs->fr = (t_fractol *)malloc(sizeof(t_fractol))))
		return (0);
	strs->wind = NULL;
	realization(argv[1], strs->fr);
	strs->wind = new_window();
	create_window(&strs->wind);
	strs->wind->image = mlx_new_image(strs->wind->mlx, S_W, S_H);
	strs->wind->adress = (int *)mlx_get_data_addr(strs->wind->image, \
			&strs->wind->endian, &strs->wind->size_line, &strs->wind->bpp);
	mlx_put_image_to_window(strs->wind->mlx, strs->wind->window, \
			strs->wind->image, 0, 0);
	fractol(argv[1], strs);
	hints(strs);
	main1(strs);
	return (0);
}
