/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpcarp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:39:57 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/18 19:20:33 by snicolet         ###   ########.fr       */
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
	const int	zoom = (int)(c->zoom * 40.0f) + 1;
	const int	start_x = 0;
	const int	start_y = 0;

	px.y = 0;
	while (px.y < c->x->height)
	{
		px.x = 0;
		while (px.x < c->x->width)
		{
			draw_px(c->x, &px, sierpcarp_draw((px.x - start_x) % zoom,
				(px.y - start_y) % zoom));
			px.x++;
		}
		px.y++;
	}
}
