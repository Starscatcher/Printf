/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:15:59 by aryabenk          #+#    #+#             */
/*   Updated: 2018/02/23 13:16:00 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void		ft_around(t_key *key, int *i, int *diff)
{
	char	*zero;

	while (key->res[*i] == '9' || key->res[*i] == '.')
	{
		if (key->res[*i] == '.')
			--*i;
		if (key->res[*i] == '9' || key->res[*i] == '.')
		{
			key->res[*i] = '0';
			if (*i != 0)
				--*i;
		}
		if (*i == 0 && key->res[*i] != '9')
		{
			zero = ft_strjoin("0", key->res);
			ft_strdel(&key->res);
			key->res = zero;
			key->finsize++;
		}
	}
	*diff = key->res[*i] - '0';
	++*diff;
}

static	void		ft_prec_float(t_key *key, int i, long double num)
{
	int	prec;
	int val;
	int diff;

	i = ft_strlen(key->res);
	prec = key->p == -1 ? 6 : key->p;
	key->res = ft_realloc(key->res, i + prec + 1);
	key->res[i++] = '.';
	while (prec-- > 0)
	{
		num *= 10;
		val = (int)num;
		num -= val;
		key->res[i++] = val + '0';
	}
	i--;
	num *= 10;
	diff = (int)num;
	if (diff >= 5)
	{
		ft_around(key, &i, &diff);
		key->res[i] = diff + '0';
	}
}

static	void		ft_aft_float(long double num, t_key *key, int i)
{
	int	prec;
	int val;

	if (key->p == 0)
	{
		while (key->res[i + 1])
			i++;
		prec = key->res[i] - '0';
		num *= 10;
		val = (int)num;
		if (val >= 5)
			prec++;
		key->res[i] = prec + '0';
	}
	else
		ft_prec_float(key, i, num);
}

static	long double	ft_fmake(int count, long double num1, t_key *key, int i)
{
	int			elem;

	while (count-- > 0)
	{
		num1 *= 10;
		elem = (int)num1;
		num1 -= elem;
		key->res[i++] = elem + '0';
	}
	return (num1);
}

void				ft_bef_float(long double num, t_key *key)
{
	long double	num1;
	int			count;
	int			i;

	count = num > 0 ? 0 : 1;
	num1 = count != 1 ? num : -num;
	i = 0;
	while (num1 >= 1)
	{
		num1 /= 10;
		count++;
	}
	key->res = ft_strnew(count);
	if (num < 0)
	{
		key->res[i++] = '-';
		count--;
	}
	num1 = ft_fmake(count, num1, key, i);
	ft_float_size(key);
	key->final = ft_strnew(key->finsize);
	ft_aft_float(num1, key, 0);
	key->p = -1;
	key->fpsize = key->wsize + ft_strlen(key->res);
	ft_modifyint(key);
}
