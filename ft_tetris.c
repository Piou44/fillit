/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetris.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:25:04 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/16 21:16:21 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
typedef struct	s_tetris
{
	char	**tab;

}				t_tetris;
*/
void	put_tetris(t_list **list, char **tab)
{
	ft_lstaddend(list, ft_lstnew((char**)*tab, sizeof(tab)));
}
