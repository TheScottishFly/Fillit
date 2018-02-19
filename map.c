/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 11:49:42 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 11:49:49 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_chkfill(t_tetr *t, t_map *d, int x, int y)
{
	int			tmp;
	int			c;

	tmp = x + y * d->w;
	c = 0;
	while (c < 4)
	{
		if (t->x[c] + x < 0 || t->x[c] + x >= d->w)
			return (0);
		if (t->y[c] + y >= d->w)
			return (0);
		if (d->res[tmp + t->x[c] + t->y[c] * d->w] != '.')
			return (0);
		c++;
	}
	c = 0;
	while (c < 4)
	{
		d->res[tmp + t->x[c] + t->y[c] * d->w] = (char)t->nb;
		c++;
	}
	return (1);
}

static int		ft_recur(t_tetr *t, t_map *m)
{
	int			x;
	int			y;

	if (!t)
		return (1);
	y = 0;
	while (y < m->w - t->h + 1)
	{
		x = 0;
		while (x < m->w - t->w + 1)
		{
			if (ft_chkfill(t, m, x, y))
			{
				if (ft_recur(t->next, m))
					return (1);
				else
					ft_backup(t, m, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static void		ft_filldot(char **s, int w)
{
	int			i;

	i = 0;
	while (i < w * w)
	{
		s[0][i] = '.';
		i++;
	}
	s[0][i] = '\0';
}

static t_map	*prepmap(int size)
{
	t_map		*m;

	m = (t_map *)malloc(sizeof(t_map));
	m->w = ft_nextsqr(size * 4);
	m->res = (char *)malloc(m->w * m->w + 1);
	ft_filldot(&m->res, m->w);
	return (m);
}

char			*ft_map(t_tetr *t, int *s)
{
	t_map		*map_data;
	char		*res;

	calc_width(t);
	map_data = prepmap(ft_list_size(t));
	while (!(ft_recur(t, map_data)))
	{
		map_data->w++;
		free(map_data->res);
		map_data->res = (char *)malloc(map_data->w * map_data->w + 1);
		ft_filldot(&map_data->res, map_data->w);
	}
	*s = map_data->w;
	res = map_data->res;
	free(map_data);
	return (res);
}
