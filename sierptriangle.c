/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierptriangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 15:23:33 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/19 16:25:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "draw.h"

inline static int	sierptriangle_core(int x, int y)
{
	if (x & y)
		return (COLOR_BLACK);
	return (COLOR_YELLOW);
}

inline static int	sierptriangle_zoom(int x, double zoom)
{
	return ((int)((double)x * zoom));
}

void				sierptriangle(t_context *c)
{
	t_point		px;
	const int	start_x = (int)(c->zoom_offsets.x * 220.0f);
	const int	start_y = (int)(c->zoom_offsets.y * 220.0f);

	px.y = c->x->height;
	while (px.y--)
	{
		px.x = c->x->width;
		while (px.x--)
			draw_px(c->x, &px, sierptriangle_core(
				sierptriangle_zoom(px.x + start_x, c->zoom),
				sierptriangle_zoom(px.y + start_y, c->zoom)));
	}
}
