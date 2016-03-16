/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:48:09 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/16 15:48:50 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "draw.h"

static void	reddot(t_context *c)
{
	t_point		p;
	t_circle	ci;

	p.x = c->x->width / 2;
	p.y = c->x->height / 2;
	draw_px(c->x, &p, COLOR_RED);
	ci = draw_make_circle(p.x, p.y, 12);
	draw_circle(c->x, &ci, COLOR_RED);
}

int			display(t_context *c)
{
	c->f(c);
	if (c->flags & FLAG_AIM)
		reddot(c);
	draw_flush_image(c->x, c->x->img);
	fractol_stats(c);
	if (c->post_display != NULL)
		c->post_display(c);
	return (0);
}
