/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:15:48 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/18 21:13:14 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>

int		key_down(int keycode, void *userdata)
{
	t_context	*c;

	c = userdata;
	if ((keycode == 53) || (keycode == 12))
		exit(0);
	else if (keycode == 123)
		c->zoom += c->zoom_step;
	else if (keycode == 124)
		c->zoom -= c->zoom_step;
	else if ((keycode == 24) || ((keycode == 27) && (c->color_offset > 8)))
		c->color_offset += (keycode == 24) ? 8 : -8;
	else if ((keycode == 0) || (keycode == 2))
		c->zoom_offsets.x += (keycode == 0) ? -0.1f : 0.1f;
	else if ((keycode == 13) || (keycode == 1))
		c->zoom_offsets.y += (keycode == 13) ? -0.1f : 0.1f;
	else if (keycode == 83)
		c->f = &sierpcarp;
	else if (keycode == 84)
		c->f = &mandelbrot;
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
