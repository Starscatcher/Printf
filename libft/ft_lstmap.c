/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:11:40 by aryabenk          #+#    #+#             */
/*   Updated: 2017/11/04 16:11:41 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*new;

	new = f(lst);
	new = ft_lstnew(new->content, new->content_size);
	if (lst == NULL || f == NULL || new == NULL)
		return (NULL);
	first = new;
	while (lst->next)
	{
		new->next = ft_lstnew(new->content, new->content_size);
		if (new->next == NULL)
		{
			free(new);
			new = NULL;
			return (NULL);
		}
		new->next = f(lst->next);
		new = new->next;
		lst = lst->next;
	}
	return (first);
}
