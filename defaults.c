/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 01:40:37 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/19 16:39:41 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_defaults(t_context *c)
{
	c->zoom = 1.0;
	c->zoom_offsets = draw_make_vector(0.0f, 0.0f, 0.0f);
	c->iterator_offset = 1;
	c->color_offset = 0;
}
