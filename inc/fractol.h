/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 13:48:54 by aziabkin          #+#    #+#             */
/*   Updated: 2018/07/12 20:31:34 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include <math.h>

# define S_W 1000
# define S_H 800

# define SCROLL_UP 5
# define SCROLL_DOWN 4

typedef struct				s_fractol
{
	char					*name;
	double					pr;
	double					pi;
	double					new_re;
	double					new_im;
	double					old_re;
	double					old_im;
	double					move_x;
	double					move_y;
	double					zoom;
	double					max_iter;
	double					color;
	double					set;
	double					mouse;
	int						col_flag;

}							t_fractol;

typedef struct				s_window
{
	void					*mlx;
	void					*image;
	void					*window;
	int						*adress;
	int						endian;
	int						size_line;
	int						bpp;
}							t_window;

typedef struct				s_structs
{
	t_fractol				*fr;
	t_window				*wind;
}							t_structs;

int							hadle_input_key(int key, t_structs *strs);
int							exit_x(int key, t_structs *strs);
t_window					*new_window(void);
void						create_window(t_window **wind);
void						error_exit(int a);
void						realization(char *str, t_fractol *fr);
void						fractol(char *str, t_structs *strs);
void						mandelbrot(t_fractol *fr, t_window *wind);
void						julia(t_fractol *fr, t_window *wind);
void						mandelbrot(t_fractol *fr, t_window *wind);
void						burning_ship(t_fractol *fr, t_window *wind);
int							color(int r, int g, int b);
int							zoom_mouse(int key, int x, int y, t_structs *strs);
void						hints(t_structs *st);
int							valid_name(char *str);
int							julia_mouse(int x, int y, t_structs *strs);
void						tricorn(t_fractol *fr, t_window *wind);
void						flower(t_fractol *fr, t_window *wind);
unsigned int				choose_col(int n, int i);
void						tricorn1(t_fractol *fr, t_window *wind,\
								int x, int y);
void						burning_ship1(t_fractol *fr, t_window *wind,\
								int x, int y);
void						flower1(t_fractol *fr, t_window *wind,\
								int x, int y);
void						julia1(t_fractol *fr, t_window *wind,\
								int x, int y);
void						mandelbrot1(t_fractol *fr, t_window *wind,\
								int x, int y);
void						main1(t_structs *strs);
void						hadle1(int key, t_structs *strs);

#endif
