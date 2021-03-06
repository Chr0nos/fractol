/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:09:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/28 19:24:55 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

inline static void	init_values(t_mandelbrot *m, t_context *c)
{
	const t_fracval	zox = c->zoom_offsets.x;
	const t_fracval	zoy = c->zoom_offsets.y;

	m->max_iterations = 64 + c->iterator_offset;
	m->zoom = (t_fracval)0.003 * c->zoom;
	m->center_x = (t_fracval)(c->center.x) * m->zoom;
	m->center_y = (t_fracval)(c->center.y) * m->zoom;
	m->x1 = (t_fracval)-2.1 * m->zoom;
	m->y1 = (t_fracval)-1.2 * m->zoom;
	m->x1 -= m->center_x - zox;
	m->y1 -= m->center_y + zoy;
	if (c->flags & FLAG_AUTOITER)
		m->max_iterations += (1.0 / c->zoom / 4.0);
}

static unsigned int	mandelbrot_core(t_mandelbrot *m)
{
	t_fracval				z_re;
	t_fracval				z_im;
	t_fracval				z_re2;
	t_fracval				z_im2;
	register unsigned int	n;

	z_re = 0.0;
	z_im = 0.0;
	n = m->max_iterations;
	while (n--)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4)
			return (n);
		z_im = 2 * z_im * z_re + m->c_im;
		z_re = z_re2 - z_im2 + m->c_re;
	}
	return (m->max_iterations);
}

static void			mandelbrot_start(t_context *c, t_mandelbrot *m,
	const int startx, const int endx)
{
	int				*pixels;
	t_point			px;
	const int		*colors = c->colormap;

	pixels = (int*)(unsigned long)c->x->img->data;
	px.x = startx;
	while (px.x-- > endx)
	{
		m->c_re = (t_fracval)(px.x * m->zoom) + m->x1;
		px.y = c->x->height;
		while (px.y--)
		{
			m->c_im = (t_fracval)(px.y * m->zoom) + m->y1;
			pixels[px.y * c->x->width + px.x] = colors[mandelbrot_core(m)];
		}
	}
}

void				mandelbrot(t_context *c)
{
	mandelthread(c, &init_values, &generic_start_thread, &mandelbrot_start);
}
