/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:27:12 by aryabenk          #+#    #+#             */
/*   Updated: 2017/11/09 17:27:13 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_help(t_list **t_where, t_list **t_from, t_list **head)
{
	(*t_where) = (*head)->next;
	(*t_from)->next = (*head)->next->next;
	(*head)->next = *t_from;
}

static	void	ft_lstswapp(t_list **alst, int from, int where)
{
	t_list	*head;
	t_list	*t_from;
	t_list	*t_where;
	int		fr;

	fr = from;
	head = (*alst);
	while (from > 0 || where > 1)
	{
		if ((--from == 1))
		{
			t_from = head->next;
			head->next = head->next->next;
		}
		if ((--where == 2))
			ft_help(&t_where, &t_from, &head);
		head = head->next;
	}
	head = (*alst);
	while (fr-- > 2)
		head = head->next;
	t_where->next = head->next;
	head->next = t_where;
}

void			ft_lstswap(t_list **alst, int from, int where)
{
	t_list	*new;
	int		swap;

	if (alst == NULL || from <= 0 || where <= 0)
		return ;
	new = ft_lstnew(NULL, 0);
	if (where < from)
	{
		swap = from;
		from = where;
		where = swap;
	}
	if (from == 1 || where == 1)
	{
		ft_lstadd(alst, new);
		ft_lstswapp(alst, from + 1, where + 1);
		(*alst) = (*alst)->next;
	}
	else
		ft_lstswapp(alst, from, where);
}
