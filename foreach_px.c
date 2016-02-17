/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach_px.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 14:17:02 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/17 15:22:38 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	foreach_py(t_mlx *x, void (*f)(const t_point *, void *), void *userdata)
{
	t_point	p;

	p.x = 0;
	while (p.x < x->width)
	{
		p.y = 0;
		while (p.y < x->height)
		{
			f(&p, userdata);
			p.y++;
		}
		p.x++;
	}
}

void	foreach_px(t_mlx *x, void (*f)(const t_point *, void *), void *userdata)
{
	t_point	p;

	p.y = 0;
	while (p.y < x->height)
	{
		p.x = 0;
		while (p.x < x->width)
		{
			f(&p, userdata);
			p.x++;
		}
		p.y++;
	}
}
