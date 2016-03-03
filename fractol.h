/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 01:08:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/02 11:40:47 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define FRACTAL_COUNT 5
# include "draw.h"
# include "fractval.h"
# include "mandelbrot.h"


enum				e_mousebutton
{
	LEFT = 249,
	RIGHT = 242,
	SCROLL = 361
};

typedef struct		s_context
{
	t_mlx			*x;
	void			(*f)(struct s_context *);
	void			(*post_display)(struct s_context *);
	t_fracval		zoom;
	t_vector		zoom_offsets;
	int				color_offset;
	unsigned int	iterator_offset;
	int				padding;
}					t_context;

int					fractal_loader_key(int keycode, t_context *c);
void				fractal_loader(t_context *c, int ac, char **av);
void				set_defaults(t_context *c);
void				rainbow(t_context *c);
void				mandelbrot(t_context *c);
void				julia(t_context *c);
void				sierpcarp(t_context *c);
void				sierptriangle(t_context *c);
void				fractol_stats(t_context *c);
int					mouse_click(int x, int y, int button, void *userdata);
int					key_down(int keycode, void *userdata);
int					mouse_move(int x, int y, void *userdata);
int					display(t_context *c);
int					main(int ac, char **av);

#endif
