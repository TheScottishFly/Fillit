/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_three.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 11:16:23 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 11:11:14 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void		ft_backup(t_tetr *t, t_map *m, int x, int y)
{
	int		c;

	c = 0;
	while (c < 4)
	{
		m->res[x + t->x[c] + (t->y[c] + y) * m->w] = '.';
		c++;
	}
}

void		calc_width(t_tetr *t)
{
	int		i;
	int		max;

	while (t)
	{
		i = 0;
		max = 0;
		while (i < 4)
		{
			if (t->x[i] > max)
				max = t->x[i];
			i++;
		}
		t->w = max;
		t->h = t->y[3];
		t = t->next;
	}
}
