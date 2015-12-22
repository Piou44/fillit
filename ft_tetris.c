/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetris.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:25:04 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/22 18:14:30 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
/*
typedef struct	s_tetris
{
	char	**tab;

}				t_tetris;
*/
void	put_tetris(t_list **list, t_fillit *adeter)
{
	ft_lstaddend(list, ft_lstnew(adeter, sizeof(adeter)));
}
