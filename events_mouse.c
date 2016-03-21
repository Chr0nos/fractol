/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:24:32 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/21 19:21:44 by snicolet         ###   ########.fr       */
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
	else if (button == CLICKRIGHT)
		trigger_flag(c, FLAG_LOCKMOUSE);
	else if (button == CLICKLEFT)
	{
		c->zoom_offsets.x -= ((c->x->width / 2) - x) * c->zoom * 0.003f;
		c->zoom_offsets.y += ((c->x->height / 2) - y) * c->zoom * 0.003f;
	}
	else if (button == SCROLLLEFT)
		c->iterator_offset *= 2;
	else if (button == SCROLLRIGHT)
		c->iterator_offset /= (c->iterator_offset > 2) ? 2 : 1;
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
	if (!(c->flags & FLAG_LOCKMOUSE))
		return (0);
	if ((x < 0) || (y < 0) || (x >= c->x->width) || (y >= c->x->height))
		return (0);
	c->mouse.x = x;
	c->mouse.y = y;
	display(c);
	return (0);
}
