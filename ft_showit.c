/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_showit.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 09:28:55 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 11:12:10 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void		ft_showit(char *map, int mapsize)
{
	int		i;

	i = 0;
	while (i < mapsize * mapsize)
	{
		if (i % mapsize == 0 && i > 0)
			write(1, "\n", 1);
		write(1, &map[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
