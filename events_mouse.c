/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:24:32 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/16 13:36:20 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int			mouse_click(int button, int x, int y, t_context *c)
{
	if (button == SCROLLUP)
	{
		c->zoom *= 0.9f;
		if (!(c->flags & FLAG_HALFMOUSE))
		{
			c->zoom_offsets.x -= ((c->x->width / 2) - x) * c->zoom * 0.003f;
			c->zoom_offsets.y += ((c->x->height / 2) - y) * c->zoom * 0.003f;
		}
	}
	else if (button == SCROLLDOWN)
		c->zoom *= 1.1;
	else if (button == CLICKLEFT)
	{
		c->zoom_offsets.x -= ((c->x->width / 2) - x) * c->zoom * 0.003f;
		c->zoom_offsets.y += ((c->x->height / 2) - y) * c->zoom * 0.003f;
	}
	else
	{
		ft_printf("mouse unsupported click: %d x:%d y:%d\n", button, x, y);
		return (0);
	}
	display(c);
	return (0);
}

int			mouse_move(int x, int y, t_context *c)
{
	if ((x < 0) || (y < 0) || (x >= c->x->width) || (y >= c->x->height))
		return (0);
	//display(c);
/*
	c->zoom = (t_fracval)y / (t_fracval)(c->x->height - 1) / 2;
	if (c->zoom < (t_fracval)0.000001f)
		c->zoom = (t_fracval)0.000001f;
	display(c);
*/
	return (0);
}
