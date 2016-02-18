/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 01:07:30 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/18 01:36:03 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "draw.h"
#include "fractol.h"
#include <stdlib.h>

int			display(t_context *c)
{
	draw_reset_image(c->x, 0);
	c->f(c);
	draw_flush_image(c->x, c->x->img);
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

static void	init_displayer(int ac, char **av, t_context *c)
{
	int		p;

	p = 1;
	c->zoom = 0.0f;
	c->zoom_step = 0.2f;
	c->f = NULL;
	c->color_offset = 0;
	while (p < ac)
	{
		if ((!ft_strcmp(av[p], "-m")) || (!ft_strcmp(av[p], "mandelbrot")))
			c->f = &mandelbrot;
		else if ((!ft_strcmp(av[p], "-r")) || (!ft_strcmp(av[p], "rainbow")))
			c->f = &rainbow;
		else if ((!ft_strcmp(av[p], "-j")) || (!ft_strcmp(av[p], "julia")))
			c->f = &julia;
		else
			ft_printf("error: unknow parameter: %s\n", av[p]);
		p++;
	}
}

int			main(int ac, char **av)
{
	t_context	c;

	init_displayer(ac, av, &c);
	if (!c.f)
		ft_printf("error: no renderer set : please use: \n\t%s\n\t%s\n\t%s\n",
			"-m for mandelbrot",
			"-j for julia",
			"-r for rainbow");
	else if (!(c.x = draw_init("Fractol", 1024, 768)))
		ft_putendl("error: failed to init window");
	else
	{
		ft_putendl("ready to work");
		draw_reset_image(c.x, 0);
		set_hooks(&c);
		display(&c);
		draw_loop(c.x);
	}
	return (0);
}
