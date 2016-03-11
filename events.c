/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:15:48 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/11 16:18:59 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>

static int	zoom_set(int keycode, t_context *c)
{
	if (keycode == KEY_UP)
		c->zoom *= 1.05f;
	else if (keycode == KEY_DOWN)
		c->zoom *= 0.95f;
	else if ((keycode == KEY_A) || (keycode == KEY_D))
		c->zoom_offsets.x += ((keycode == KEY_A) ? -0.05f : 0.05f) *
			(c->zoom + (t_fracval)0.000001f);
	else if ((keycode == KEY_W) || (keycode == KEY_S))
		c->zoom_offsets.y += ((keycode == KEY_W) ? -0.05f : 0.05f) *
			(c->zoom + (t_fracval)0.000001f);
	else
		return (0);
	return (1);
}

int			key_down(int keycode, void *userdata)
{
	t_context	*c;

	c = userdata;
	if ((keycode == KEY_ESC) || (keycode == KEY_Q))
		closer(c);
	else if ((keycode == KEY_PLUS) || ((keycode == KEY_LESS) &&
		(c->color_offset >= 8)))
			c->color_offset += (keycode == KEY_PLUS) ? 8 : -8;
	else if (fractal_loader_key(keycode, c))
		;
	else if (zoom_set(keycode, c))
		;
	else if (keycode == KEY_I)
		c->iterator_offset *= 2;
	else if ((keycode == KEY_O) && (c->iterator_offset > 2))
		c->iterator_offset /= 2;
	else if (keycode == KEY_R)
		set_defaults(c);
	ft_printf("keydown: %d\n", keycode);
	display(c);
	return (0);
}

int			mouse_click(int button, int x, int y, void *userdata)
{
	t_context	*c;

	(void)x;
	(void)y;
	c = userdata;
	ft_printf("mouseclick: %d\n", button);
	if (button == SCROLLUP)
		c->zoom *= 0.9f;
	else if (button == SCROLLDOWN)
	{
		c->zoom *= 1.1;
	}
	else
		return (0);
	display(c);
	return (0);
}

int			mouse_move(int x, int y, void *userdata)
{
	t_context	*c;

	c = userdata;

	if ((x < 0) || (y < 0) || (x >= c->x->width) || (y >= c->x->height))
		return (0);

/*
	c->zoom = (t_fracval)y / (t_fracval)(c->x->height - 1) / 2;
	if (c->zoom < (t_fracval)0.000001f)
		c->zoom = (t_fracval)0.000001f;
	display(c);
*/
	return (0);
}
