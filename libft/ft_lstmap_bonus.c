/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:21:13 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/12 14:21:15 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp_origin;
	t_list	*tmp_ret;
	t_list	*tmp_new;

	if (!lst)
		return (NULL);
	tmp_origin = lst;
	if (!(tmp_ret = ft_lstnew(f(tmp_origin->content))))
		return (NULL);
	tmp_new = tmp_ret;
	tmp_origin = tmp_origin->next;
	while (tmp_origin)
	{
		if (!(tmp_new->next = ft_lstnew(f(tmp_origin->content))))
		{
			ft_lstclear(&tmp_ret, del);
			return (NULL);
		}
		tmp_new = tmp_new->next;
		tmp_origin = tmp_origin->next;
	}
	return (tmp_ret);
}
