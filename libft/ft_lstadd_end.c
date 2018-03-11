/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:07:24 by amazurok          #+#    #+#             */
/*   Updated: 2017/11/07 12:11:25 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **lst, t_list *end)
{
	t_list *new;

	new = *lst;
	if (new)
	{
		while (new->next)
			new = new->next;
		new->next = end;
	}
	else
		*lst = end;
}
