/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 01:46:21 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/19 02:16:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

inline static void	fractal_loader_init(void **fptrs)
{
	fptrs[0] = (void*)&rainbow;
	fptrs[1] = (void*)&mandelbrot;
	fptrs[2] = (void*)&julia;
	fptrs[3] = (void*)&sierpcarp;
}

void				fractal_loader(t_context *c, int ac, char **av)
{
	const char		*params = "rmjs";
	void			*fptrs[4];
	int				ppos;
	int				p;

	fractal_loader_init(fptrs);
	p = 1;
	c->f = NULL;
	while (p < ac)
	{
		if ((av[p][0] == '-') && (av[p][1]) && (!av[p][2]))
		{
			ppos = ft_strchrpos(params, av[p][1]);
			if (ppos >= 0)
				c->f = (void(*)(t_context *))fptrs[ppos];
			else
				ft_printf("error: unknow option: %s\n", av[p]);
		}
		else
			ft_printf("error: unknow option: %s\n", av[p]);
		p++;
	}
}
