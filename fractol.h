/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 01:08:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/15 16:58:43 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "draw.h"

typedef struct	s_complex
{
	float		real;
	float		ima;
}				t_complex;

typedef struct	s_contect
{
	t_mlx		*x;
}				t_context;

void			mandelbrot(t_context *c);
int				key_down(int keycode, void *userdata);
int				main(int ac, char **av);

#endif
