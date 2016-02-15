/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 01:07:30 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/15 16:19:43 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "draw.h"
#include "fractol.h"
#include <stdlib.h>


static int	display(t_context *c)
{
	(void)c;
	return (0);
}

static int	closer(void *userdata)
{
	draw_clear((t_mlx *)userdata);
	exit(0);
}

int		main(int ac, char **av)
{
	t_context	c;

	if (!(c.x = draw_init("Fractol", 800, 600)))
	{
		ft_putendl("error: failed to init window");
		return (0);
	}
	draw_sethook_ng(c.x, &closer, c.x, CLOSE);
	draw_sethook_ng(c.x, &key_down, c.x, KEYDOWN);
	display(&c);
	draw_loop(c.x);
	(void)ac;
	(void)av;
	return (0);
}
