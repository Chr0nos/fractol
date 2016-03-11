/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 15:09:02 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/11 16:32:52 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H
# include "fractol.h"

typedef struct		s_mandelbrot
{
	t_fracval		min_re;
	t_fracval		max_re;
	t_fracval		min_im;
	t_fracval		max_im;
	t_fracval		re_factor;
	t_fracval		im_factor;
	t_fracval		c_im;
	t_fracval		c_re;
	unsigned int	max_iterations;
	unsigned int	n;
}					t_mandelbrot;

#endif
