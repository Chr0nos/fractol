/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 13:39:18 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/18 14:02:03 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

void	mandelthread(t_context *c, void (*init)(t_mandelbrot *, t_context *),
	void *(*start)(void *),
	void (*core)(t_context *, t_mandelbrot *, const int, const int))
{
	t_mandelthread	t[THREADS];
	pthread_t		threads[THREADS];
	int				p;

	init(&t[0].m, c);
	if (!(colors_init(&c->colormap, t[0].m.max_iterations, c)))
		return ;
	t[0].c = c;
	t[0].core = core;
	p = THREADS;
	while (p--)
	{
		if (p)
			t[p] = t[0];
		t[p].id = p + 1;
		pthread_create(&threads[p], NULL, start, &t[p]);
	}
	p = THREADS;
	while (p--)
		pthread_join(threads[p], NULL);
}

void	*generic_start_thread(void *x)
{
	t_mandelthread	*t;
	int				blocksize;

	t = x;
	blocksize = t->c->x->width / THREADS;
	t->core(t->c, &t->m, blocksize * t->id,
		(blocksize * t->id) - blocksize);
	return (0);
}
