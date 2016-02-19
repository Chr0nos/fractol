/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:15:48 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/19 01:42:56 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>

static int	zoom_set(int keycode, t_context *c)
{
	if (keycode == 125)
		c->zoom *= 1.05f;
	else if (keycode == 126)
		c->zoom *= 0.95f;
	else
		return (0);
	return (1);
}

int		key_down(int keycode, void *userdata)
{
	t_context	*c;

	c = userdata;
	if ((keycode == 53) || (keycode == 12))
		exit(0);
	else if ((keycode == 24) || ((keycode == 27) && (c->color_offset > 8)))
		c->color_offset += (keycode == 24) ? 8 : -8;
	else if ((keycode == 0) || (keycode == 2))
		c->zoom_offsets.x += (keycode == 0) ? -0.05f : 0.05f;
	else if ((keycode == 13) || (keycode == 1))
		c->zoom_offsets.y += (keycode == 13) ? -0.05f : 0.05f;
	else if (keycode == 83)
		c->f = &sierpcarp;
	else if (keycode == 84)
		c->f = &mandelbrot;
	else if (zoom_set(keycode, c))
		;
	else if (keycode == 34)
		c->iterator_offset *= 2;
	else if (keycode == 15)
		set_defaults(c);
	else
		ft_printf("keydown: %d\n", keycode);
	display(c);
	return (0);
}

int		mouse_click(int x, int y, int button, void *userdata)
{
	(void)userdata;
	if (button == SCROLL)
	{
		ft_printf("scroll requested on x:%d y:%d\n", x, y);
	}
	else
		ft_printf("button %d\n", button);
	return (0);
}

int		mouse_move(int x, int y, void *userdata)
{
	(void)userdata;
	(void)x;
	(void)y;
	return (0);
}
