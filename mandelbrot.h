/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 15:09:02 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/18 19:32:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H

typedef struct		s_mandelbrot
{
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double			re_factor;
	double			im_factor;
	double			c_im;
	double			c_re;
	unsigned int	max_iterations;
	unsigned int	n;
}					t_mandelbrot;

#endif
