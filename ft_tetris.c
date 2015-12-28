/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetris.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:25:04 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/28 18:49:28 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	put_tetris(t_list **list, char **tab)//t_fillit *adeter)
{
	ft_lstaddend(list, ft_lstnew(tab, sizeof(tab)));//ft_lstnew(adeter, sizeof(adeter)));
}
