/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:15:48 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/15 16:22:22 by snicolet         ###   ########.fr       */
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
