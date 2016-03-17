/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpcarp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:39:57 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/17 12:07:12 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "draw.h"

static int			sierpcarp_draw(int x, int y)
{
	while ((x > 0) || (y > 0))
	{
		if ((x % 3 == 1) && (y % 3 == 1))
			return (COLOR_BLACK);
		x /= 3;
		y /= 3;
	}
	return (0x0016b9dd);
}

void				sierpcarp(t_context *c)
{
	t_point		px;
	const int	start_x = (int)(c->zoom_offsets.x * 220.0f);
	const int	start_y = (int)(c->zoom_offsets.y * 220.0f);

	px.y = 0;
	while (px.y < c->x->height)
	{
		px.x = 0;
		while (px.x < c->x->width)
		{
			draw_px(c->x, &px,
				sierpcarp_draw((int)(((float)px.x - (float)start_x) * c->zoom),
				(int)((((float)px.y - (float)start_y) * c->zoom))));
			px.x++;
		}
		px.y++;
	}
}
