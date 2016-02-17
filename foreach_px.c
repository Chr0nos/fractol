/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach_px.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 14:17:02 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/17 14:36:24 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	foreach_px(t_mlx *x, void (*f)(const t_point *px, void *),
		void *userdata)
{
	t_point	p;

	p.y = 0;
	while (p.y < x->height)
	{
		p.x = 0;
		while (p.x < x->width)
		{
			f(&px, userdata);
			p.x++;
		}
		p.y++;
	}
}
