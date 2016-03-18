/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 01:08:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/18 14:06:05 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define SIZE_X 1024
# define SIZE_Y 768
# define FRACTAL_COUNT 7
# define THREADS 8
# include "draw.h"
# include "fractval.h"
# include "context.h"
# include "mandelbrot.h"
# ifdef __APPLE__
#  include "keycodes_mac.h"
# else
#  include "keycodes_linux.h"
# endif
# include "flags.h"

enum				e_mousebutton
{
	CLICKLEFT = 1,
	CLICKRIGHT = 2,
	SCROLLUP = 4,
	SCROLLDOWN = 5
};

void				mandelthread(t_context *c,
	void (*init)(t_mandelbrot *, t_context *), void *(*start)(void *),
	void (*core)(t_context *, t_mandelbrot *, const int, const int));
void				*generic_start_thread(void *x);
int					closer(void *userdata);
int					colors_init(int **colors, unsigned int size, t_context *c);
int					fractal_loader_key(int keycode, t_context *c);
void				fractal_loader(t_context *c, int ac, char **av);
void				show_help(void);
void				set_defaults(t_context *c);
void				rainbow(t_context *c);
void				mandelbrot(t_context *c);
void				mandelbrot_threads(t_context *c);
void				julia(t_context *c);
void				burningjulia(t_context *c);
void				sierpcarp(t_context *c);
void				sierptriangle(t_context *c);
void				burningship(t_context *c);
void				fractol_stats(t_context *c);
void				trigger_flag(t_context *c, const size_t flag);
int					mouse_click(int button, int x, int y, t_context *c);
int					key_down(int keycode, t_context *c);
int					mouse_move(int x, int y, t_context *c);
int					display(t_context *c);
int					main(int ac, char **av);

#endif
