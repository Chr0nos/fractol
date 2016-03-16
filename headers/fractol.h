/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 01:08:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/16 22:01:46 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define SIZE_X 1024
# define SIZE_Y 768
# define FRACTAL_COUNT 6
# include "draw.h"
# include "fractval.h"
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

typedef struct		s_context
{
	t_mlx			*x;
	void			(*f)(struct s_context *);
	void			(*post_display)(struct s_context *);
	int				*colormap;
	t_fracval		zoom;
	t_vector		zoom_offsets;
	int				color_offset;
	unsigned int	iterator_offset;
	int				keys_press;
	t_vector		mouse;
	t_vector		center;
	size_t			flags;
}					t_context;

int					closer(void *userdata);
int					colors_init(int **colors, unsigned int size, t_context *c);
int					fractal_loader_key(int keycode, t_context *c);
void				fractal_loader(t_context *c, int ac, char **av);
void				set_defaults(t_context *c);
void				rainbow(t_context *c);
void				mandelbrot(t_context *c);
void				mandelbrot2(t_context *c);
void				julia(t_context *c);
void				sierpcarp(t_context *c);
void				sierptriangle(t_context *c);
void				burningship(t_context *c);
void				fractol_stats(t_context *c);
int					mouse_click(int button, int x, int y, t_context *c);
int					key_down(int keycode, t_context *c);
int					mouse_move(int x, int y, t_context *c);
int					display(t_context *c);
int					main(int ac, char **av);

#endif
