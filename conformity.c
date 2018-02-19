/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conformity.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 09:29:15 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 16:17:27 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		check_block(char *block)
{
	int		i;

	i = 0;
	while (block[i])
	{
		if (i % 21 != 0)
		{
			if (is_end(i) && !is_newline(block[i]))
				return (0);
			if (!is_end(i) && !is_valid(block[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

static int		check_tetr(char *block)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (block[i] == '#')
		{
			if (i % 5 != 0 && block[i - 1] == '#')
				count++;
			if (i % 5 != 3 && block[i + 1] == '#')
				count++;
			if (i > 4 && block[i - 5] == '#')
				count++;
			if (i < 14 && block[i + 5] == '#')
				count++;
		}
		i++;
	}
	return (count == 6 || count == 8);
}

static t_tetr	*beautify_tetr(t_tetr *tetr)
{
	int		tmp_x;
	int		tmp_y;
	int		i;

	i = 0;
	tmp_x = 0;
	tmp_y = 0;
	if (tetr->x[i] > 0 || tetr->y[i] > 0)
	{
		tmp_x -= tetr->x[i];
		tmp_y -= tetr->y[i];
		while (i < 4)
		{
			tetr->x[i] += tmp_x;
			tetr->y[i] += tmp_y;
			i++;
		}
	}
	return (tetr);
}

static t_tetr	*make_tetr(char *block, char nb)
{
	t_tetr	*new;
	int		i;
	int		j;

	if (!(new = (t_tetr *)malloc(sizeof(t_tetr))))
		return (NULL);
	i = 0;
	j = 0;
	new->next = NULL;
	new->nb = nb;
	while (i < 20)
	{
		if (block[i] == '#')
		{
			new->x[j] = i % 5;
			new->y[j] = i / 5;
			j++;
		}
		i++;
	}
	return (beautify_tetr(new));
}

t_tetr			*check_file(int file)
{
	char	buf[BUF_SIZE];
	t_tetr	*begin;
	t_tetr	*node;
	int		read_size;
	int		prev_size;

	node = NULL;
	while ((read_size = read(file, buf, BUF_SIZE)) && read_size > 0)
	{
		prev_size = read_size;
		if (!check_block(buf) || !check_tetr(buf))
			return (0);
		if (node != NULL)
		{
			node->next = make_tetr(buf, node->nb + 1);
			node = node->next;
		}
		else
			node = make_tetr(buf, 65);
		if (!begin)
			begin = node;
	}
	if (prev_size != 20)
		return (0);
	return (begin);
}
