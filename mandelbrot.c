/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:28:12 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/04 16:34:41 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

inline static void	init_values(t_mandelbrot *m, t_mlx *x, t_context *c)
{
	m->min_re = -2.0f * c->zoom;
	m->max_re = 1.0f * (c->zoom * 1.25f);
	m->min_im = -1.2f * c->zoom;
	m->max_im = m->min_im + (m->max_re - m->min_re) * x->height / x->width;
	m->re_factor = (m->max_re - m->min_re) / (x->width - 1);
	m->im_factor = (m->max_im - m->min_im) / (x->height - 1);
	printf("re_factor: %f -- im_factor: %f -- zoom: %f\n", m->re_factor,
		m->im_factor, c->zoom);
	m->max_iterations = (unsigned int)(16.0f / c->zoom) + 16;
	if (m->max_iterations > 128)
		m->max_iterations = 128;
	m->max_iterations += c->iterator_offset;
}

/*
** this function is called on each pixel of the window
** so in the case of a 1024x768 it's called 786432 times per draw
** it returns the number of iterations lefts
*/

inline static unsigned int	mandelbrot_core(t_mandelbrot *m, const double c_re)
{
	double			z_re2;
	double			z_im2;
	double			z_re;
	double			z_im;
	unsigned int	n;

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

/*
** this function return the correct corlor for the current mandelbrot point
** it's proceced m->max_iterations times, no more (see mandelbrot_init_colors)
** the color generation uses HSV color
*/

inline static int	mandelbrot_px_color(const unsigned int max_iterations,
	const unsigned int n, const int color_offset)
{
	t_rgb	rgb;

	rgb = draw_color_hsv(180 + color_offset,
		0.8f,
		(float)n / (float)max_iterations);
	return (draw_color_rgb2int(&rgb));
}

/*
** this function pre-calcultate colors
** it's usefull to limit the number of colors calculation to max_iterations
** it malloc and return 0 in case of fail, in case of success return 1
** the function allocate one extra int to avoir -1 in the critical while
** the position 0 should never be used
** colors are in the reverse order
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
		(*colors)[size] = mandelbrot_px_color(m->max_iterations,
			m->max_iterations - size, c->color_offset);
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
	px.y = c->x->height;
	while (px.y--)
	{
		m.c_im = m.max_im - px.y * m.im_factor + c->zoom_offsets.y;
		px.x = c->x->width;
		while (px.x--)
		{
			draw_px(c->x, &px,
				colors[mandelbrot_core(&m, px.x * m.re_factor + m.min_re +
					c->zoom_offsets.x)]);
		}
	}
	free(colors);
}
