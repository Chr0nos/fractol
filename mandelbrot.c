/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:28:12 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/11 16:44:33 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

inline static void	init_values(t_mandelbrot *m, t_mlx *x, t_context *c)
{
	m->min_re = (t_fracval)-2.0f * c->zoom;
	m->max_re = (t_fracval)1.0f * (t_fracval)(c->zoom * 1.0f);
	m->min_im = (t_fracval)-1.2f * c->zoom;
	m->max_im = m->min_im + (m->max_re - m->min_re) * x->height / x->width;
	m->re_factor = (m->max_re - m->min_re) / (x->width - 1);
	m->im_factor = (m->max_im - m->min_im) / (x->height - 1);
	m->max_iterations = 64;
	m->max_iterations += c->iterator_offset;
}

/*
** this function is called on each pixel of the window
** so in the case of a 1024x768 it's called 786432 times per draw
** it returns the number of iterations done
*/

static unsigned int	mandelbrot_core(t_mandelbrot *m, const t_fracval c_re)
{
	register t_fracval		z_re2;
	register t_fracval		z_im2;
	t_fracval				z_re;
	t_fracval				z_im;
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
		z_im = 2 * z_re * z_im + m->c_im;
		z_re = z_re2 - z_im2 + c_re;
	}
	return (m->max_iterations);
}

void				mandelbrot(t_context *c)
{
	t_mandelbrot	m;
	t_point			px;
	const int		*colors;

	init_values(&m, c->x, c);
	if (!(colors_init(&c->colormap, m.max_iterations, c)))
		return ;
	colors = c->colormap;
	px.y = c->x->height;
	while (px.y--)
	{
		m.c_im = (t_fracval)(m.max_im - px.y * m.im_factor + c->zoom_offsets.y);
		px.x = c->x->width;
		while (px.x--)
			draw_px(c->x, &px,
					colors[mandelbrot_core(&m, (t_fracval)(px.x * m.re_factor +
						m.min_re + c->zoom_offsets.x))]);
	}
}
