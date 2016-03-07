/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:12:31 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/04 16:15:42 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rainbow(t_context *c)
{
	t_point		px;
	int			h;
	int			color;
	t_rgb		rgb;

	px.y = 0;
	h = 0;
	while (px.y < c->x->height)
	{
		px.x = 0;
		rgb = draw_color_hsv(h++ / 2, 1.0f, 1.0f);
		color = draw_color_rgb2int(&rgb);
		while (px.x < c->x->width)
		{
			draw_px(c->x, &px, color);
			px.x++;
		}
		px.y++;
	}
}
