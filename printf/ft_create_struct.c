/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:03:41 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/05 10:03:42 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_make_struct_sec(t_key *key)
{
	key->s = 0;
	key->res = NULL;
	key->re = 0;
	key->fpsize = 0;
	key->wsize = 0;
	key->finsize = 0;
	key->final = NULL;
	key->wre = 0;
	key->wres = NULL;
}

t_key			*ft_make_struct(void)
{
	t_key *key;

	if (!(key = (t_key *)malloc(sizeof(t_key))))
		return (NULL);
	if (!(key->flags = (t_flags *)malloc(sizeof(t_flags))))
		return (NULL);
	if (!(key->len = (t_len *)malloc(sizeof(t_len))))
		return (NULL);
	key->w = 0;
	key->p = -1;
	key->flags->g = 0;
	key->flags->m = 0;
	key->flags->p = 0;
	key->flags->s = 0;
	key->flags->z = 0;
	key->len->h = 0;
	key->len->hh = 0;
	key->len->j = 0;
	key->len->l = 0;
	key->len->ll = 0;
	key->len->z = 0;
	ft_make_struct_sec(key);
	return (key);
}
