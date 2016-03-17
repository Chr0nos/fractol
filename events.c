/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:15:48 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/17 12:27:06 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>

static int	zoom_set(int keycode, t_context *c)
{
	t_fracval	extra;

	if (sizeof(t_fracval) == sizeof(float))
		extra = 0.0001f;
	else
		extra = 0.0000001f;
	if (keycode == KEY_UP)
		c->zoom *= 1.05f;
	else if (keycode == KEY_DOWN)
		c->zoom *= 0.95f;
	else if (keycode == KEY_A)
		c->zoom_offsets.x -= 0.15f * (c->zoom + extra);
	else if (keycode == KEY_D)
		c->zoom_offsets.x += 0.15f * (c->zoom + extra);
	else if (keycode == KEY_W)
		c->zoom_offsets.y -= 0.15f * (c->zoom + extra);
	else if (keycode == KEY_S)
		c->zoom_offsets.y += 0.15f * (c->zoom + extra);
	else if (keycode == KEY_PAGEUP)
		c->zoom_offsets.z += 0.01f;
	else if (keycode == KEY_PAGEDOWN)
		c->zoom_offsets.z -= 0.01f;
	else
		return (0);
	return (1);
}

void		trigger_flag(t_context *c, const size_t flag)
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
	else if ((fractal_loader_key(keycode, c)) || (zoom_set(keycode, c)))
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
	else if (keycode == KEY_L)
		trigger_flag(c, FLAG_LOCKMOUSE);
	else
		ft_printf("keydown: %d\n", keycode);
	display(c);
	return (0);
}
