/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 11:28:18 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/11 16:29:41 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

/*
** this function return the correct corlor for the current point
** the color generation uses HSV color
*/

inline static int	color_px(const unsigned int max_iterations,
	const unsigned int n, const int color_offset)
{
	t_rgb	rgb;

	rgb = draw_color_hsv(180 + color_offset,
		1.0f,
		(float)n / (float)max_iterations);
	return (draw_color_rgb2int(&rgb));
}

/*
** this function pre-calcultate colors
** if the current color tab dosent need to be re-calculated: we dont
** it's usefull to limit the number of colors calculation to max_iterations
** it malloc and return 0 in case of fail, in case of success return 1
** the function allocate one extra int to avoir -1 in the critical while
** the position 0 should never be used, it store the max number of iterations
** colors are in the reverse order
** ---
** the way to know if the color tabs need to be done again:
** - colors tab is not NULL
** - colors tab size is equal to size
** - colors[size + 1] is equal to c->color_offset
** if thoses 3 conditions are true: then we dont redo the tab
*/

int					colors_init(int **colors, unsigned int size, t_context *c)
{
	const unsigned int	fsize = size;

	if ((*colors) && ((*colors)[0] == (int)size) &&
		((*colors)[size + 1] == c->color_offset))
		return (1);
	if (*colors)
		free(*colors);
	if (!(*colors = malloc(sizeof(int) * (size + 2))))
		return (0);
	(*colors)[size--] = COLOR_BLACK;
	while (size)
	{
		(*colors)[size] = color_px(fsize, fsize - size, c->color_offset);
		size--;
	}
	(*colors)[0] = (int)fsize;
	(*colors)[fsize + 1] = c->color_offset;
	return (1);
}
