/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 22:11:09 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/17 13:46:56 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#define HELP_LINES 18

void	show_help(void)
{
	unsigned int	p;
	const char		*lines[HELP_LINES] = { "-m for mandelbrot",
		"-j for julia",
		"-r for rainbow",
		"-b for burningship",
		"-s for Sierpinski carpet",
		"-t for Sierpinski triangle",
		"\n---FRACTALS---",
		"PAGEUP & PAGEDOWN : julia factor offsets\nq : quit",
		"UP & DOWN : incrase/decrase zoom",
		"W A S D : move to -Y -X +Y +X",
		"l : lock the mouse\nk : use inteligent iterations mode",
		"r : reset to default\nt : toggle target\ng : toggle positional zoom",
		"i : incrase iterations",
		"o : decrase iterations",
		"+ - : change colors",
		"numeric pad: switch to an other fractal",
		"---CONTROLS---",
		"Welcome to fractol\n"
	};

	p = HELP_LINES;
	while (p--)
		ft_putendl(lines[p]);
}
