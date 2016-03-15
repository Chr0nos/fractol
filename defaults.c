/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 01:40:37 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/15 18:55:19 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_defaults(t_context *c)
{
	c->zoom = 1.0f;
	c->zoom_offsets = draw_make_vector(0.0f, 0.0f, 0.0f);
	c->iterator_offset = 1;
	c->color_offset = 0;
	c->mouse = draw_make_vector(0.0f, 0.0f, 0.0f);
	c->center = draw_make_vector((float)(c->x->width / 2),
		(float)(c->x->height / 2), 0.0f);
}
