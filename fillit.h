/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:44:43 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 11:11:39 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "types.h"

# define SUCCESS 0
# define FAILURE 1
# define BUF_SIZE 21

void	ft_putstr(char const *s);
void	usage(void);
int		is_valid(char c);
int		is_newline(char c);
int		is_end(int i);
int		ft_nextsqr(int n);
char	*ft_strdup(const char *s1);
int		ft_list_size(t_tetr *begin_list);
t_tetr	*check_file(int file);
char	*ft_map(t_tetr *t, int *s);
void	ft_showit(char *map, int mapsize);
int		is_alpha(char c);
void	lst_clear(t_tetr *lst);
void	ft_backup(t_tetr *t, t_map *m, int x, int y);
void	calc_width(t_tetr *t);

#endif
