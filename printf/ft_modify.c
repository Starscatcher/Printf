/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:50:17 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/05 11:50:17 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_modify_else(t_key *key)
{
	if (key->s == 'C' || key->s == 'c')
	{
		ft_unicharprint(key);
		ft_strdel((char**)&key->wres);
	}
	else if (key->s == 'S' || key->s == 's')
	{
		if (!key->wres)
		{
			ft_charsize(key);
			key->final = ft_strnew(key->finsize);
			ft_modifychar(key); 
		}
		else
			ft_uniprint(key);
	}
	else
	{
		key->re = key->s;
		ft_print_char(key);
	}
}

void	ft_upper(t_key *key)
{
	int i;

	i = 0;
	if (key->s == 'X')
	{
		while (key->res[i])
		{
			key->res[i] = (char)ft_toupper(key->res[i]);
			i++;
		}
	}
}

void	ft_is_n(va_list args, int ret)
{
	int *n;

	n = va_arg(args, void*);
	*n = ret;
}

int		ft_modify(t_key *key, va_list args, int ret)
{
	ft_readtype(key, args);
	ft_upper(key);
	if (key->s == 'n')
		ft_is_n(args, ret);
	else if (ft_findin("DdioOuUxXp", key->s))
	{
		if (key->s == 'p')
			key->flags->g = 1;
		key->final = ft_strnew(ft_size(key));
		ft_modifyint(key);
	}
	else if (key->s == 's' && !key->len->l)
	{
		key->s = 's';
		ft_charsize(key);
		key->final = ft_strnew(key->finsize);
		ft_modifychar(key);
	}
	else if (key->s == 'c' && !key->len->l)
		ft_print_char(key);
	else if (key->s == 'f' || key->s == 'F')
		return (key->finsize);
	else
		ft_modify_else(key);
	return (key->finsize);
}
