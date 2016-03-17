/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:40:29 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/17 18:12:59 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H
# include "fractol.h"

typedef struct		s_context
{
	t_mlx			*x;
	void			(*f)(struct s_context *);
	void			(*post_display)(struct s_context *);
	int				*colormap;
	t_fracval		zoom;
	t_vector		zoom_offsets;
	int				color_offset;
	unsigned int	iterator_offset;
	int				keys_press;
	t_vector		mouse;
	t_vector		center;
	size_t			flags;
}					t_context;

#endif
