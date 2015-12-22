/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:53:44 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/22 16:32:19 by asalama          ###   ########.fr       */
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

#include <string.h>


# define BUF_SIZE 21

typedef struct 	s_tetris
{
	int			max_elem;
	int			nb_tetris;
	char 		*tetris;

}				t_tetris;

typedef struct	s_square
{

}				t_square;

//char		*ft_error(int fd);
int		check_tetris(char **tab);
char		ft_alphabet(char alpha);
void	put_tetris(t_list **list, char **tab);
int		do_everything(t_list *lst, int fd);
int		check_diese(char **tab);
#include <stdio.h>


#endif
