/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:25:49 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/14 00:16:06 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"
#include <string.h>

void						fractol_stats(t_context *c)
{
	char			buffer[128];

	ft_snprintf(buffer, 128, "offset: x: %f y: %f zoom: %f",
			(double)c->zoom_offsets.x,
			(double)c->zoom_offsets.y,
			(double)c->zoom);
	mlx_string_put(c->x->mlxptr, c->x->winptr, 10, 25, COLOR_WHITE, buffer);
}
