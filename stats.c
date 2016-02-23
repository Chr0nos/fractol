/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:25:49 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/23 18:48:33 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"
#include <string.h>

inline static unsigned int	strxcat(char *dest, const char *src)
{
	size_t	sp;

	sp = ft_strlen(src);
	ft_memcpy(dest, src, sp);
	dest[sp] = '\0';
	return ((unsigned int)sp);
}

void						fractol_stats(t_context *c)
{
	char			buffer[128];
	char			xoffset[12];
	char			yoffset[12];
	char			zoomstr[12];
	unsigned int	p;

	ft_itobuff(xoffset, (int)(c->zoom_offsets.x * 100000), 10, "0123456789");
	ft_itobuff(yoffset, (int)(c->zoom_offsets.y * 100000), 10, "0123456789");
	ft_itobuff(zoomstr, (int)(c->zoom * 1000000), 10, "0123456789");

	p = strxcat(buffer, "offsets: x: ");
	p += strxcat(buffer + p, xoffset);
	p += strxcat(buffer + p, " y: ");
	p += strxcat(buffer + p, yoffset);
	mlx_string_put(c->x->mlxptr, c->x->winptr, 10, 10, COLOR_WHITE, buffer);
	p = strxcat(buffer, "zoom: ");
	strxcat(buffer + p, zoomstr);
	mlx_string_put(c->x->mlxptr, c->x->winptr, 10, 25, COLOR_WHITE, buffer);
}
