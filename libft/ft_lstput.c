/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:09:47 by aryabenk          #+#    #+#             */
/*   Updated: 2017/11/09 13:09:48 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstput(t_list **alst, size_t position)
{
	t_list	*lstnew;
	t_list	*new;

	new = *alst;
	lstnew = (t_list*)malloc(sizeof(t_list));
	lstnew->content = NULL;
	if (alst == NULL || (int)position <= 0 || lstnew == NULL)
		return ;
	if (position == 1)
	{
		ft_lstadd(alst, lstnew);
		return ;
	}
	while (new->next && position > 2)
	{
		new = new->next;
		position--;
	}
	lstnew->next = new->next;
	new->next = lstnew;
}
