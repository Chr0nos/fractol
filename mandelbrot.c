/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:28:12 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/17 18:55:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline static void	init_values(t_mandelbrot *m, t_mlx *x)
{
	m->min_re = -2.0f;
	m->max_re = 1.0f;
	m->min_im = -1.2f;
	m->max_im = m->min_im + (m->max_re - m->min_re) * x->height / x->width;
	m->re_factor = (m->max_re - m->min_re) / (x->width - 1);
	m->im_factor = (m->max_im - m->min_im) / (x->height - 1);
	m->max_iterations = 30;
}

inline static int	mandelbrot_core(t_mandelbrot *m)
{
	double			z_re2;
	double			z_im2;

	m->n = 0;
	while (m->n < m->max_iterations)
	{
		z_re2 = m->z_re * m->z_re;
		z_im2 = m->z_im * m->z_im;
		if (z_re2 + z_im2 > 4)
			return (0);
		m->z_im = 2 * m->z_re * m->z_im + m->c_im;
		m->z_re = z_re2 - z_im2 + m->c_re;
		m->n++;
	}
	return (1);
}

inline static int		mandelbrot_px_color(t_mandelbrot *m)
{
	t_rgb	rgb;

	rgb.r = 0;
	rgb.g = 0;
	rgb.b = m->n * 255 / m->max_iterations;
	return (draw_color_rgb2int(&rgb));
}

void				mandelbrot(t_context *c)
{
	t_mandelbrot	m;
	t_point			px;

	init_values(&m, c->x);
	px.y = 0;
	while (px.y < c->x->height)
	{
		m.c_im = m.max_im - px.y * m.im_factor;
		px.x = 0;
		while (px.x < c->x->width)
		{
			m.c_re = m.min_re + px.x * m.re_factor;
			m.z_re = m.c_re;
			m.z_im = m.c_im;
			if (!mandelbrot_core(&m))
				draw_px(c->x, &px, mandelbrot_px_color(&m));
			px.x++;
		}
		px.y++;
	}
}
