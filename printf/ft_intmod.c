/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:31:24 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/05 11:31:25 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_size(t_key *key)
{
	int size;
	int j;
	int len;

	size = 0;
	if (key->res[0] == '0' && ft_findin("Xx", key->s))
	{
		key->flags->s = 0;
		key->flags->g = 0;
	}
	if (key->res[0] == '0' && ft_findin("Oo", key->s) && key->p != 0)
		key->flags->g = 0;
	j = key->res[0] == '-' ? 1 : 0;
	len = ft_strlen(key->res) - j;
	size += (ft_findin("Xxpb", key->s) && key->flags->g) ? 2 : 0;
	size += (ft_findin("Oo", key->s) && key->flags->g) && key->p < len ? 1 : 0;
	if (!ft_findin("XxOoUupb", key->s))
		size += (key->res[0] == '-' || key->flags->p || key->flags->s) ? 1 : 0;
	if (key->p == 0 && key->res[0] == '0')
		len = 0;
	key->fpsize = key->p > len ? size + key->p : size + len;
	key->finsize = key->fpsize;
	key->finsize = key->w - key->finsize > 0 ? key->w : key->finsize;
	return (key->finsize);
}

static	int		ft_flagsint(t_key *key, int i)
{
	int m;

	m = key->res[0] == '-' ? 1 : 0;
	if ((key->flags->p || key->res[0] == '-') && !ft_findin("XxOoUupb", key->s))
		key->final[i++] = key->res[0] == '-' ? '-' : '+';
	if (key->flags->s && !key->flags->p && !m && !ft_findin("XxOoUupb", key->s))
		key->final[i++] = ' ';
	if (ft_findin("XxOopb", key->s) && key->flags->g)
	{
		if (key->p <= (int)ft_strlen(key->res) && ft_findin("oO", key->s))
			key->final[i++] = '0';
		if (ft_findin("Xxpb", key->s))
		{
			key->final[i++] = '0';
			if (key->s == 'b')
			{
				key->final[i++] = 'b';
				return (i);
			}
			key->final[i++] = key->s == 'X' ? 'X' : 'x';
		}
	}
	return (i);
}

static	int		ft_precint(t_key *key, int i)
{
	int j;
	int count;

	j = key->res[0] == '-' ? 1 : 0;
	count = key->p - (ft_strlen(key->res) - j);
	if (count > 0)
	{
		while (count--)
			key->final[i++] = '0';
	}
	if (key->p == 0 && key->res[0] == '0')
		return (i);
	while (key->res[j])
		key->final[i++] = key->res[j++];
	return (i);
}

static	int		ft_widthint(t_key *key, int i, char zero)
{
	int count;

	count = key->finsize - key->fpsize;
	while (count-- > 0)
		key->final[i++] = zero;
	return (i);
}

void			ft_modifyint(t_key *key)
{
	int		i;
	char	zero;

	zero = key->flags->z && !key->flags->m && key->p < 0 ? '0' : ' ';
	i = 0;
	if (key->flags->m)
	{
		i = ft_flagsint(key, i);
		i = ft_precint(key, i);
		ft_widthint(key, i, zero);
	}
	else
	{
		if (zero == '0')
		{
			i = ft_flagsint(key, i);
			i = ft_widthint(key, i, zero);
		}
		else
		{
			i = ft_widthint(key, i, zero);
			i = ft_flagsint(key, i);
		}
		ft_precint(key, i);
	}
}
