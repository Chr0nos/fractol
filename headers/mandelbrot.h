/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 15:09:02 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/18 13:58:33 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H
# include "fractol.h"

typedef struct		s_mandelbrot
{
	t_fracval		x1;
	t_fracval		y1;
	t_fracval		min_re;
	t_fracval		max_re;
	t_fracval		min_im;
	t_fracval		max_im;
	t_fracval		re_factor;
	t_fracval		im_factor;
	t_fracval		c_im;
	t_fracval		c_re;
	t_fracval		zoom;
	t_fracval		center_x;
	t_fracval		center_y;
	t_fracval		wx;
	t_fracval		wy;
	t_fracval		z_re;
	t_fracval		z_im;
	unsigned int	max_iterations;
	unsigned int	n;
}					t_mandelbrot;

typedef struct		s_mandelthread
{
	t_mandelbrot	m;
	t_context		*c;
	void			(*core)(t_context *, t_mandelbrot *, const int, const int);
	int				id;
	int				padding;
}					t_mandelthread;

#endif
