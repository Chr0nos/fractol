/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 01:40:37 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/21 11:28:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_defaults(t_context *c)
{
	c->zoom = 1.0f;
	c->zoom_offsets.x = 0.0f;
	c->zoom_offsets.y = 0.0f;
	c->zoom_offsets.z = 0.0f;
	c->iterator_offset = 1;
	c->color_offset = 0;
	c->mouse.x = 0.0f;
	c->mouse.y = 0.0f;
	c->mouse.z = 0.0f;
	c->center.x = (float)c->x->width / 2;
	c->center.y = (float)c->x->height / 2;
	c->center.z = 0.0f;
}
