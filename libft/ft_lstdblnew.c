/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 12:53:49 by asalama           #+#    #+#             */
/*   Updated: 2016/01/08 14:42:03 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_maillon	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	if (content == NULL)
	{
		tmp->content_size = 0;
		tmp->content = NULL;
	}
	else
	{
		tmp->content_size = content_size;
		if(!(tmp->content = malloc(content_size))
			return (NULL);
		ft_memcpy(tmp->content, content, content_size);
	}
	tmp->next = NULL;
	return (tmp);
}
