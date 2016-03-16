/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 01:46:21 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/16 19:31:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

inline static void	fractal_loader_init(void **fptrs)
{
	fptrs[0] = (void*)&rainbow;
	fptrs[1] = (void*)&mandelbrot;
	fptrs[2] = (void*)&mandelbrot2;
	fptrs[3] = (void*)&julia;
	fptrs[4] = (void*)&sierpcarp;
	fptrs[5] = (void*)&sierptriangle;
	fptrs[6] = (void*)&burningship;
}

inline static void	fractal_loader_loadidx(const unsigned int idx, void **fptrs,
	t_context *c)
{
	c->post_display = NULL;
	c->f = (void(*)(t_context *))fptrs[idx];
}

int					fractal_loader_key(int keycode, t_context *c)
{
	void			*fptrs[FRACTAL_COUNT];
	int				idx;
	const int		tab[] = { KEY_PAD0, KEY_PAD1, KEY_PAD2, KEY_PAD3, KEY_PAD4,
		KEY_PAD5, KEY_PAD6, KEY_PAD7, KEY_PAD8, KEY_PAD9 };

	idx = 10;
	while ((idx--) && (tab[idx] != keycode))
		;
	if ((idx < 0) || (idx >= FRACTAL_COUNT))
		return (0);
	fractal_loader_init(fptrs);
	fractal_loader_loadidx((unsigned int)idx, fptrs, c);
	return (1);
}

void				fractal_loader(t_context *c, int ac, char **av)
{
	const char		*params = "rmbjsth";
	void			*fptrs[FRACTAL_COUNT];
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
				fractal_loader_loadidx((unsigned int)ppos, fptrs, c);
			else
				ft_printf("error: unknow option: %s\n", av[p]);
		}
		else
			ft_printf("error: unknow option: %s\n", av[p]);
		p++;
	}
}
