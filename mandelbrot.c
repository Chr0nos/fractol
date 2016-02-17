/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:28:12 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/17 14:36:21 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			mandelbrot_px(const t_point *px, t_context *c)
{
	int		max_iter;

	max_iter = 50;
	
}

void				mandelbrot(t_context *c)
{
	foreach_px(c->x, &mandelbrot_px, c);
}
