/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 09:29:41 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 09:29:42 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstr(char const *s)
{
	while (*s)
		write(1, s++, 1);
}

void	usage(void)
{
	ft_putstr("usage: ./fillit file\n");
	exit(FAILURE);
}

int		is_valid(char c)
{
	if (c == '.' || c == '#')
		return (1);
	return (0);
}

int		is_newline(char c)
{
	if (c == '\0' || c == '\n')
		return (1);
	return (0);
}

int		is_end(int i)
{
	if (i == 4 || i == 9 || i == 14 || i == 19 || i == 20)
		return (1);
	return (0);
}
