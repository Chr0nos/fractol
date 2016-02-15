/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 01:07:30 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/15 23:48:46 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "draw.h"
#include "fractol.h"
#include <stdlib.h>

static int	display(t_context *c)
{
	t_point		px;
	int			h;
	int			color;

	px.y = 600;
	h = 0;
	while (px.y--)
	{
		color = draw_color_hsv(h++, 255, 255);
		px.x = 800;
		while (px.x--)
			draw_px(c->x, &px, color);
	}
	draw_flush_image(c->x, c->x->img);
	ft_putendl("display done");
	return (0);
}

static int	closer(void *userdata)
{
	draw_clear((t_mlx *)userdata);
	exit(0);
}

static void	set_hooks(t_context *c)
{
	draw_sethook_ng(c->x, &closer, c, CLOSE);
	draw_sethook_ng(c->x, &key_down, c, KEYDOWN);
	draw_sethook_ng(c->x, &mouse_move, c, MOUSEMOVE);
	draw_sethook_ng(c->x, &mouse_click, c, MOUSEDOWN);
}

int			main(int ac, char **av)
{
	t_context	c;

	if (!(c.x = draw_init("Fractol", 800, 600)))
	{
		ft_putendl("error: failed to init window");
		return (0);
	}
	set_hooks(&c);
	display(&c);
	draw_loop(c.x);
	(void)ac;
	(void)av;
	return (0);
}
