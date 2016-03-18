/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 22:35:44 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/18 12:22:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

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
	if (c->flags & FLAG_AUTOITER)
		m->max_iterations += (1.0f / c->zoom / 4.0f);
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

static void			julia_start(t_context *c, t_mandelbrot *m,
	const int startx, const int endx)
{
	t_point			px;
	const int		*colors = c->colormap;

	px.x = startx;
	while (px.x-- > endx)
	{
		m->z_re = (t_fracval)(px.x * m->zoom) + m->x1;
		px.y = c->x->height;
		while (px.y--)
		{
			m->z_im = (t_fracval)(px.y * m->zoom) + m->y1;
			draw_px(c->x, &px, colors[julia_core(m)]);
		}
	}
}

static void			*julia_start_thread(void *x)
{
	t_mandelthread	*t;
	int				blocksize;

	t = x;
	blocksize = t->c->x->width / THREADS;
	julia_start(t->c, &t->m, blocksize * t->id,
		(blocksize * t->id) - blocksize);
	return (0);
}

void				julia(t_context *c)
{
	t_mandelthread	t[THREADS];
	pthread_t		threads[THREADS];
	int				p;

	init_values(&t[0].m, c);
	if (!(colors_init(&c->colormap, t[0].m.max_iterations, c)))
		return ;
	t[0].c = c;
	p = THREADS;
	while (p--)
	{
		if (p)
			t[p] = t[0];
		t[p].id = p + 1;
		pthread_create(&threads[p], NULL, julia_start_thread, &t[p]);
	}
	p = THREADS;
	while (p--)
		pthread_join(threads[p], NULL);
}
