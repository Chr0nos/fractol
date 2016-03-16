/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:15:48 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/16 13:35:02 by snicolet         ###   ########.fr       */
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
		c->zoom_offsets.x += ((keycode == KEY_A) ? -0.15f : 0.15f) *
			(c->zoom + (t_fracval)0.0000001f);
	else if ((keycode == KEY_W) || (keycode == KEY_S))
		c->zoom_offsets.y += ((keycode == KEY_W) ? -0.15f : 0.15f) *
			(c->zoom + (t_fracval)0.000001f);
	else
		return (0);
	return (1);
}

static void	trigger_flag(t_context *c, const size_t flag)
{
	if (!(c->flags & flag))
		c->flags |= flag;
	else
		c->flags = c->flags & ~flag;
}

int			key_down(int keycode, t_context *c)
{
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
	else if (keycode == KEY_T)
		trigger_flag(c, FLAG_AIM);
	else if (keycode == KEY_G)
		trigger_flag(c, FLAG_HALFMOUSE);
	else
		ft_printf("keydown: %d\n", keycode);
	display(c);
	return (0);
}
