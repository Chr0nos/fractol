/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:12:31 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/17 12:15:22 by snicolet         ###   ########.fr       */
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
	while (px.y < 600)
	{
		px.x = 0;
		rgb = draw_color_hsv(h++, 1.0f, 1.0f);
		color = draw_color_rgb2int(&rgb);
		while (px.x <= 800)
		{
			draw_px(c->x, &px, color);
			px.x++;
		}
		px.y++;
	}
}
