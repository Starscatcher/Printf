/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:02:42 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/12 14:02:43 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_float_size(t_key *key)
{
	int size;
	int len;
	int j;

	if (!key->res)
		key->res = ft_strdup("0.0");
	size = key->p != 0 ? 1 : 0;
	j = key->res[0] == '-' ? 1 : 0;
	len = ft_strlen(key->res) - j;
	key->fpsize = key->p == -1 ? 6 : key->p;
	size += key->fpsize + len;
	key->wsize = key->w - size > 0 ? key->w - size - len : 0;
	size = key->wsize > 0 ? key->w : size;
	key->wsize = j || key->flags->s ? 1 : 0;
	key->finsize = size + key->wsize;
}
