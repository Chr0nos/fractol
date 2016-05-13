/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:15:48 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/21 22:47:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>

static int	zoom_set(int keycode, t_context *c)
{
	t_fracval	extra;

	if (sizeof(t_fracval) == sizeof(float))
		extra = 0.0001;
	else
		extra = 0.0000001;
	if (keycode == KEY_UP)
		c->zoom *= 1.05;
	else if (keycode == KEY_DOWN)
		c->zoom *= 0.95;
	else if (keycode == KEY_A)
		c->zoom_offsets.x -= 0.15 * (c->zoom + extra);
	else if (keycode == KEY_D)
		c->zoom_offsets.x += 0.15 * (c->zoom + extra);
	else if (keycode == KEY_W)
		c->zoom_offsets.y -= 0.15 * (c->zoom + extra);
	else if (keycode == KEY_S)
		c->zoom_offsets.y += 0.15 * (c->zoom + extra);
	else if (keycode == KEY_PAGEUP)
		c->zoom_offsets.z += 0.01;
	else if (keycode == KEY_PAGEDOWN)
		c->zoom_offsets.z -= 0.01;
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

static int	key_down_extra(int keycode, t_context *c)
{
	if (keycode == KEY_N)
		trigger_flag(c, FLAG_NOSTATS);
	else
		return (0);
	return (1);
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
	else if (keycode == KEY_K)
		trigger_flag(c, FLAG_AUTOITER);
	else if (keycode == KEY_H)
		trigger_flag(c, FLAG_NOHSCROLL);
	else if (!key_down_extra(keycode, c))
		ft_printf("keydown: %d\n", keycode);
	display(c);
	return (0);
}
