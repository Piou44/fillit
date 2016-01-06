/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:53:44 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/06 15:55:41 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <stdio.h>
#include <string.h>

# define BUF_SIZE 21
/*
typedef struct	s_limit
{
	int			ver;
	int			hor;
	char		**tetris;
}				t_limit;
*/
typedef struct	s_maillon
{
	int			ver;
	int			hor;
	int			nb_tetris;
	char		**tab;
}				t_maillon;

typedef struct	s_map
{
	int			x;
	int			y;
	int			cote;
}				t_map;

int				check_tetris(char **tab);
char			ft_alphabet(char alpha);
void			put_tetris(t_list **list, t_maillon tetris, char **tab);
int				do_everything(t_list **lst, t_maillon adeter, int fd);
int				check_diese(char **tab);
int				free_everything(char **tab, char *line);
unsigned int	ft_sqrt(unsigned int nb);
unsigned int	ft_squared(unsigned int nb);
int				fill_square(t_list *lst);
int				square_size(size_t nb_tetris);
char			**fresh_map(t_list **lst, int cote);
char			**backtracking(char **map, t_list *lst, int x, int y, int cote);
void			print_map(char **map, int cote);
void			fill_with_dots(char **tab, int cote);
//char			**smallest_sqr(t_list *lst);

#endif
