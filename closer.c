/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:17:00 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/11 16:26:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "draw.h"
#include "libft.h"
#include <stdlib.h>

int		closer(void *userdata)
{
	t_context	*c;

	ft_putendl("exit requested, i'l make some cleans before...");
	c = userdata;
	draw_clear(c->x);
	if (c->colormap)
		free(c->colormap);
	ft_putendl("clean ok, bye.");
	exit(0);
}
