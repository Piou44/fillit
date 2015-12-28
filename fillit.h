/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:53:44 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/28 17:02:38 by asalama          ###   ########.fr       */
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

typedef struct	s_fillit
{
	int			nb_tetris;
	char		**tab;
}				t_fillit;

int				check_tetris(char **tab);
char			ft_alphabet(char alpha);
void			put_tetris(t_list **list, t_fillit *adeter);
int				do_everything(t_list *lst, int fd);
int				check_diese(char **tab);
int				free_everything(char **tab, char *line);
unsigned int	ft_sqrt(unsigned int nb);
unsigned int	ft_squared(unsigned int nb);
int				fill_square(t_list *lst);
//char			**smallest_sqr(t_list *lst);

#endif
