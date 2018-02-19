/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_two.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:49:21 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 11:11:27 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_nextsqr(int n)
{
	int		i;

	i = 2;
	while (i * i < n)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		length;
	int		i;
	char	*new_str;

	length = 0;
	i = 0;
	while (s1[length])
		length++;
	new_str = malloc((length + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int		ft_list_size(t_tetr *begin_list)
{
	int		i;
	t_tetr	*buf;

	i = 0;
	buf = begin_list;
	if (buf == NULL)
		return (0);
	else
		i = 1;
	while (buf->next)
	{
		i++;
		buf = buf->next;
	}
	return (i);
}

int		is_alpha(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
