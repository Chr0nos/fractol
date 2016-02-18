/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:28:12 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/18 01:45:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

inline static void	init_values(t_mandelbrot *m, t_mlx *x, t_context *c)
{
	const double	zoom_factor = c->zoom * c->zoom_step;

	m->min_re = -2.0f + zoom_factor + c->zoom_offsets.x;
	m->max_re = 1.0f - zoom_factor;
	m->min_im = -1.2f + (zoom_factor * 0.75);
	//m->max_im = m->min_im + (m->max_re - m->min_re) * x->height / x->width;
	m->max_im = 1.2f - (zoom_factor * 0.75);
	m->re_factor = (m->max_re - m->min_re) / (x->width - 1);
	m->im_factor = (m->max_im - m->min_im) / (x->height - 1);
	m->max_iterations = 64;
}

/*
** this function is called on each pixel of the window
** so in the case of a 1024x768 it's called 786432 times per draw
*/

inline static void	mandelbrot_core(t_mandelbrot *m, const double c_re)
{
	double			z_re2;
	double			z_im2;

	m->n = 0;
	while (m->n < m->max_iterations)
	{
		z_re2 = m->z_re * m->z_re;
		z_im2 = m->z_im * m->z_im;
		if (z_re2 + z_im2 > 4)
			return ;
		m->z_im = 2 * m->z_re * m->z_im + m->c_im;
		m->z_re = z_re2 - z_im2 + c_re;
		m->n++;
	}
}

inline static int	mandelbrot_px_color(t_mandelbrot *m, const unsigned int n,
	const int color_offset)
{
	t_rgb	rgb;

	rgb = draw_color_hsv(180 + color_offset,
		0.8f, (float)n / (float)m->max_iterations);
	return (draw_color_rgb2int(&rgb));
}

/*
** this function pre-calcultate colors
** it's usefull to limit the number of colors calculation to max_iterations
** it malloc and return 0 in case of fail, in case of success return 1
** the function allocate one extra int to avoir -1 in the critical while
** the position 0 should never be used
*/

inline static int	mandelbrot_init_colors(int **colors, t_mandelbrot *m,
	t_context *c)
{
	unsigned int	size;

	size = m->max_iterations;
	if (!(*colors = malloc(sizeof(int) * (size + 1))))
		return (0);
	(*colors)[size--] = COLOR_BLACK;
	while (size)
	{
		(*colors)[size] = mandelbrot_px_color(m, size, c->color_offset);
		size--;
	}
	(*colors)[0] = COLOR_WHITE;
	return (1);
}

void				mandelbrot(t_context *c)
{
	t_mandelbrot	m;
	t_point			px;
	int				*colors;

	init_values(&m, c->x, c);
	if (!(mandelbrot_init_colors(&colors, &m, c)))
		return ;
	px.y = 0;
	while (px.y < c->x->height)
	{
		m.c_im = m.max_im - px.y * m.im_factor;
		px.x = 0;
		while (px.x < c->x->width)
		{
			m.z_re = 0.0f;
			m.z_im = 0.0f;
			mandelbrot_core(&m, m.min_re + px.x * m.re_factor);
			draw_px(c->x, &px, colors[m.n]);
			px.x++;
		}
		px.y++;
	}
	free(colors);
}
