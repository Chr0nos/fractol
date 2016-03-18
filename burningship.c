/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 19:26:35 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/18 12:47:03 by snicolet         ###   ########.fr       */
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
	m->x1 = (t_fracval)-2.1f * m->zoom;
	m->y1 = (t_fracval)-1.2f * m->zoom;
	m->x1 -= m->center_x - zox;
	m->y1 -= m->center_y + zoy;
	if (c->flags & FLAG_AUTOITER)
		m->max_iterations += (1.0f / c->zoom / 4.0f);
}

static unsigned int	burningship_core(t_mandelbrot *m)
{
	t_fracval				z_re;
	t_fracval				z_im;
	t_fracval				z_re2;
	t_fracval				z_im2;
	register unsigned int	n;

	z_re = 0.0f;
	z_im = 0.0f;
	n = m->max_iterations;
	while (n--)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4)
			return (n);
		z_im = fabs(2 * z_im * z_re + m->c_im);
		z_re = fabs(z_re2 - z_im2 + m->c_re);
	}
	return (m->max_iterations);
}

static void			burningship_start(t_context *c, t_mandelbrot *m,
	const int startx, const int endx)
{
	t_point			px;
	const int		*colors = c->colormap;

	px.x = startx;
	while (px.x-- > endx)
	{
		m->c_re = (t_fracval)(px.x * m->zoom) + m->x1;
		px.y = c->x->height;
		while (px.y--)
		{
			m->c_im = (t_fracval)(px.y * m->zoom) + m->y1;
			draw_px(c->x, &px, colors[burningship_core(m)]);
		}
	}
}

static void			*burningship_start_thread(void *x)
{
	t_mandelthread	*t;
	int				blocksize;

	t = x;
	blocksize = t->c->x->width / THREADS;
	burningship_start(t->c, &t->m, blocksize * t->id,
		(blocksize * t->id) - blocksize);
	return (0);
}

void				burningship(t_context *c)
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
		pthread_create(&threads[p], NULL, burningship_start_thread, &t[p]);
	}
	p = THREADS;
	while (p--)
		pthread_join(threads[p], NULL);
}
