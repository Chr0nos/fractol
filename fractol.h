/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 01:08:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/17 21:34:14 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "draw.h"
# include "mandelbrot.h"

enum			e_mousebutton
{
	LEFT = 249,
	RIGHT = 242,
	SCROLL = 361
};

typedef struct	s_complex
{
	float		real;
	float		ima;
}				t_complex;

typedef struct	s_context
{
	t_mlx			*x;
	void			(*f)(struct s_context *);
	double			zoom;
}					t_context;

void			foreach_py(t_mlx *x, void (*f)(const t_point *, void *),
		void *userdata);
void			foreach_px(t_mlx *x, void (*f)(const t_point *, void *),
		void *userdata);
void			rainbow(t_context *c);
void			mandelbrot(t_context *c);
int				mouse_click(int x, int y, int button, void *userdata);
int				key_down(int keycode, void *userdata);
int				mouse_move(int x, int y, void *userdata);
int				display(t_context *c);
int				main(int ac, char **av);

#endif
