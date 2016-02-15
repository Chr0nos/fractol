/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:15:48 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/15 23:18:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>

int		key_down(int keycode, void *userdata)
{
	t_context	*c;

	c = userdata;
	if (keycode == 53)
		exit(0);
	ft_printf("keydown: %d\n", keycode);
	return (0);
}

int		mouse_click(int x, int y, int button, void *userdata)
{
	(void)userdata;
	if (button == SCROLL)
	{
		ft_printf("scroll requested on x:%d y:%d\n", x, y);
	}
	return (0);
}

int		mouse_move(int x, int y, void *userdata)
{
	(void)userdata;
	(void) x;
	(void) y;
	return (0);
}
