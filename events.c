/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:15:48 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/11 11:19:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>

static int	linux_to_mac_key(int keycode)
{
	const int	l[3] = { 65307, 65362, 65364 };
	const int	m[3] = { 53, 126, 125 };
	int			n;

	if (ft_isalpha(keycode))
		return (keycode - 'a');
	if (ft_isdigit(keycode))
		return (keycode - '0' + 17);
	n = 3;
	while (n--)
		if (l[n] == keycode)
			return (m[n]);
	return (keycode);
}

static int	zoom_set(int keycode, t_context *c)
{
	if (keycode == 125)
		c->zoom *= 1.05f;
	else if (keycode == 126)
		c->zoom *= 0.95f;
	else if ((keycode == 0) || (keycode == 2))
		c->zoom_offsets.x += ((keycode == 0) ? -0.05f : 0.05f) *
			(c->zoom + (t_fracval)0.000001f);
	else if ((keycode == 1) || (keycode == 13))
		c->zoom_offsets.y += ((keycode == 1) ? -0.05f : 0.05f) *
			(c->zoom + (t_fracval)0.000001f);
	else
		return (0);
	return (1);
}

int			key_down(int keycode, void *userdata)
{
	t_context	*c;

	c = userdata;
	keycode = linux_to_mac_key(keycode);
	if ((keycode == 53) || (keycode == 12))
		exit(0);
	else if ((keycode == 24) || ((keycode == 27) && (c->color_offset >= 8)))
		c->color_offset += (keycode == 24) ? 8 : -8;
	else if (fractal_loader_key(keycode, c))
		;
	else if (zoom_set(keycode, c))
		;
	else if (keycode == 34)
		c->iterator_offset *= 2;
	else if ((keycode == 31) && (c->iterator_offset > 2))
		c->iterator_offset /= 2;
	else if (keycode == 15)
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
	if ((button == SCROLL) || (button == LEFT))
	{
		ft_printf("button %d\n", button);
		c->zoom *= 0.95f;
		//c->zoom_offsets.x = (float)x / (float)(c->x->width);
		//c->zoom_offsets.y = (float)y / (float)(c->x->height);
		//c->zoom_offsets.x *= ((float)x / (float)(c->x->width - 1) * (float)x);
		//c->zoom_offsets.y *= ((float)y / (float)(c->x->height - 1)) * (float)y;
		display(c);

	}
	return (0);
}

int			mouse_move(int x, int y, void *userdata)
{
	t_context	*c;

	c = userdata;

	if ((x < 0) || (y < 0) || (x >= c->x->width) || (y >= c->x->height))
		return (0);

	c->zoom = (t_fracval)y / (t_fracval)(c->x->height - 1) / 2;
	if (c->zoom < (t_fracval)0.000001f)
		c->zoom = (t_fracval)0.000001f;
	display(c);

	return (0);
}
