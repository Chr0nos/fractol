/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:09:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/11 20:10:33 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>

inline static void	init_values(t_mandelbrot *m, t_context *c)
{
	m->x1 = (t_fracval)-2.1f + c->zoom_offsets.x;
	m->x2 = (t_fracval)0.6f;
	m->y1 = (t_fracval)-1.2f - c->zoom_offsets.y;
	m->y2 = (t_fracval)1.2f;
/*
	m->x1 = c->zoom_offsets.x;
	m->y1 = -c->zoom_offsets.y;
	m->x2 = (t_fracval)2.7f;
	m->y2 = (t_fracval)2.4f;
*/
	m->max_iterations = 64 + c->iterator_offset;
}

static unsigned int	mandelbrot_core2(t_mandelbrot *m)
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
		z_im = 2 * z_im * z_re + m->c_im;
		z_re = z_re2 - z_im2 + m->c_re;
	}
	return (m->max_iterations);
}

void				mandelbrot2(t_context *c)
{
	t_mandelbrot	m;
	t_point			px;
	const int		*colors;
	int				image_x;
	int				image_y;
	t_fracval		zoom;

	zoom = (t_fracval)100.0f / c->zoom;
	init_values(&m, c);
	if (!(colors_init(&c->colormap, m.max_iterations, c)))
		return ;
	draw_reset_image(c->x, 0);
	colors = c->colormap;
	image_x = (int)((m.x2 - m.x1) * zoom);
	image_y = (int)((m.y2 - m.y1) * zoom);
	px.x = 0;
	while (px.x < image_x)
	{
		m.c_re = (t_fracval)px.x / zoom + m.x1;
		px.y = 0;
		while (px.y < image_y)
		{
			m.c_im = (t_fracval)px.y / zoom + m.y1;
			draw_px(c->x, &px, colors[mandelbrot_core2(&m)]);
			px.y++;
		}
		px.x++;
	}
}
