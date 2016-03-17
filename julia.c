/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 22:35:44 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/17 11:53:22 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include <math.h>

inline static void	init_values(t_mandelbrot *m, t_context *c)
{
	const t_fracval	zox = c->zoom_offsets.x;
	const t_fracval	zoy = c->zoom_offsets.y;

	m->max_iterations = 64 + c->iterator_offset;
	m->zoom = (t_fracval)0.003f * c->zoom;
	m->center_x = (t_fracval)(c->center.x) * m->zoom;
	m->center_y = (t_fracval)(c->center.y) * m->zoom;
	m->x1 = (t_fracval)-2.0f * m->zoom;
	m->y1 = (t_fracval)0.7f * m->zoom;
	m->x1 -= m->center_x - zox;
	m->y1 -= m->center_y + zoy;
	m->wx = (t_fracval)c->x->width;
	m->wy = (t_fracval)c->x->height;
	m->c_re = -0.7f + (c->mouse.y / m->wy) + c->zoom_offsets.z;
	m->c_im = 0.27015f + (c->mouse.x / m->wx + c->zoom_offsets.z);
}

static unsigned int	julia_core(t_mandelbrot *m)
{
	t_fracval				z_re;
	t_fracval				z_im;
	t_fracval				z_re2;
	t_fracval				z_im2;
	register unsigned int	n;

	z_re = m->z_re;
	z_im = m->z_im;
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

void				julia(t_context *c)
{
	t_mandelbrot	m;
	t_point			px;
	const int		*colors;

	init_values(&m, c);
	if (!(colors_init(&c->colormap, m.max_iterations, c)))
		return ;
	colors = c->colormap;
	px.x = c->x->width;
	while (px.x--)
	{
		m.z_re = (t_fracval)(px.x * m.zoom) + m.x1;
		px.y = c->x->height;
		while (px.y--)
		{
			m.z_im = (t_fracval)(px.y * m.zoom) + m.y1;
			draw_px(c->x, &px, colors[julia_core(&m)]);
		}
	}
}
