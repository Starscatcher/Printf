/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charmod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 09:42:32 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/06 09:42:35 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_charsize(t_key *key)
{
	int len;

	if (!key->res)
		key->res = "(null)";
	len = (int)ft_strlen(key->res);
	key->finsize += len > key->p && key->p >= 0 ? key->p : len;
	key->fpsize = key->finsize;
	key->finsize = key->w > key->finsize ? key->w : key->finsize;
}

void	ft_modifychar(t_key *key)
{
	int		i;
	int		j;
	char	zero;
	int		size;

	size = key->finsize;
	i = 0;
	j = 0;
	zero = key->flags->z ? '0' : ' ';
	if (key->flags->m)
	{
		while (key->res[j] && j < key->fpsize)
			key->final[i++] = key->res[j++];
		while (i < key->finsize)
			key->final[i++] = ' ';
	}
	else
	{
		while (size-- > key->fpsize)
			key->final[i++] = zero;
		while (j < key->fpsize)
			key->final[i++] = key->res[j++];
	}
}

void	ft_print_char(t_key *key)
{
	int		i;
	char	zero;

	i = 0;
	zero = key->flags->z ? '0' : ' ';
	key->finsize = key->w > 1 ? key->w : 1;
	key->final = ft_strnew(key->finsize);
	if (key->flags->m)
	{
		key->final[i++] = key->re;
		while (i < key->finsize)
			key->final[i++] = ' ';
	}
	else
	{
		while (i < key->finsize - 1)
			key->final[i++] = zero;
		key->final[i] = key->re;
	}
}
