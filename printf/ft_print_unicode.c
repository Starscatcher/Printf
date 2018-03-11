/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unicode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:37:07 by aryabenk          #+#    #+#             */
/*   Updated: 2018/02/21 16:37:08 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ret_size(int ret, int size)
{
	ret = size <= 7 ? 1 : ret;
	ret = size > 7 && size <= 11 ? 2 : ret;
	ret = size > 11 && size <= 16 ? 3 : ret;
	ret = size > 16 ? 4 : ret;
	return (ret);
}

int		ft_unicharsize(t_key *key)
{
	int		i;
	int		ret;
	char	*base;
	int		size;

	i = 0;
	while (key->wres[i])
	{
		ret = 0;
		base = ft_itoa_bss(key->wres[i], 2);
		size = (int)ft_strlen(base);
		ft_strdel(&base);
		ret = ft_ret_size(ret, size);
		ret += key->fpsize;
		if (ret <= key->p || key->p == -1)
		{
			key->fpsize = ret;
			i++;
		}
		else
			break ;
	}
	return (i);
}

void	ft_unicharprint(t_key *key)
{
	int		ret;
	char	*base;
	int		size;
	char	zero;

	base = ft_itoa_bss(key->wre, 2);
	size = (int)ft_strlen(base);
	ret = 0;
	ret = ft_ret_size(ret, size);
	zero = key->flags->z ? '0' : ' ';
	key->finsize = ret > key->w ? ret : key->w;
	if (key->flags->m)
	{
		ft_unisize(key->wre);
		while (ret++ < key->w)
			write(1, " ", 1);
	}
	else
	{
		while (ret++ < key->w)
			write(1, &zero, 1);
		ft_unisize(key->wre);
	}
	ft_strdel(&base);
}

void	ft_uniprint(t_key *key)
{
	int		i;
	int		count;
	char	zero;
	int		size;

	i = 0;
	count = ft_unicharsize(key);
	zero = key->flags->z ? '0' : ' ';
	key->finsize = key->fpsize < key->w ? key->w : key->fpsize;
	size = key->finsize;
	if (key->flags->m)
	{
		while (count-- > 0)
			ft_unisize(key->wres[i++]);
		while (key->fpsize++ < key->w)
			write(1, " ", 1);
	}
	else
	{
		while (size-- > key->fpsize)
			write(1, &zero, 1);
		while (count-- > 0)
			ft_unisize(key->wres[i++]);
	}
}
