/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:28:12 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/17 23:32:02 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

inline static void	init_values(t_mandelbrot *m, t_mlx *x, t_context *c)
{
	m->min_re = -2.0f + c->zoom;
	m->max_re = 1.0f;
	m->min_im = -1.2f + c->zoom;
	m->max_im = m->min_im + (m->max_re - m->min_re) * x->height / x->width;
	m->re_factor = (m->max_re - m->min_re) / (x->width - 1);
	m->im_factor = (m->max_im - m->min_im) / (x->height - 1);
	m->max_iterations = 64;
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

inline static int	mandelbrot_px_color(t_mandelbrot *m, const unsigned int n)
{
	t_rgb	rgb;

	rgb.r = 0;
	rgb.g = n * 150 / m->max_iterations;
	rgb.b = n * 255 / m->max_iterations;
	return (draw_color_rgb2int(&rgb));
}

/*
** this function pre-calcultate colors
** it's usefull to limit the number of colors calculation to max_iterations
** it malloc and return NULL in case of fail, in case of success return a
** pointer to the area and modify **colors value
*/

inline static void 	*mandelbrot_init_colors(int **colors, t_mandelbrot *m)
{
	unsigned int	size;

	size = m->max_iterations;
	if (!(*colors = malloc(sizeof(int) * size)))
		return (NULL);
	while (size--)
		(*colors)[size] = mandelbrot_px_color(m, size);
	return (*colors);
}

void				mandelbrot(t_context *c)
{
	t_mandelbrot	m;
	t_point			px;
	int				*colors;

	init_values(&m, c->x, c);
	if (!(mandelbrot_init_colors(&colors, &m)))
		return ;
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
				draw_px(c->x, &px, colors[m.n]);
			px.x++;
		}
		px.y++;
	}
	free(colors);
}
