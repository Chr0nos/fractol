/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 22:11:09 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/16 22:15:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	show_help(void)
{
	unsigned int	p;
	const char		*lines[6] = { "-m for mandelbrot",
		"-j for julia",
		"-r for rainbow",
		"-b for burningship",
		"-s for sierpcarp square",
		"-t for sierpcarp triangle"
	};

	p = 6;
	ft_putendl("error: no renderer set: please use:");
	while (p--)
		ft_putendl(lines[p]);
}
