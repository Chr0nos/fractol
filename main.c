/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 01:07:30 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/16 16:04:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "draw.h"
#include "fractol.h"

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

	ft_putendl("Hello, i'm fractol !");
	fractal_loader(&c, ac, av);
	if (!c.f)
		ft_printf("error: no renderer set : please use: \n\t%s\n\t%s\n\t%s\n",
			"-m for mandelbrot",
			"-j for julia",
			"-r for rainbow");
	else if (!(c.x = draw_init("Fractol", SIZE_X, SIZE_Y)))
		ft_putendl("error: failed to init window");
	else
	{
		c.flags = FLAG_NONE | FLAG_LOCKMOUSE | FLAG_HALFMOUSE;
		c.colormap = NULL;
		set_defaults(&c);
		ft_putendl("ready to work");
		draw_reset_image(c.x, 0);
		set_hooks(&c);
		display(&c);
		draw_loop(c.x);
	}
	return (0);
}
