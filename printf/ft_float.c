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

void	ft_aft_float(double num, t_key *key, int i)
{
	int	prec;
	int val;
	int diff;
	int ddd;

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
	{
		i = ft_strlen(key->res);
		prec = key->p == -1 ? 6 : key->p;
		key->res = ft_realloc(key->res, i + prec + 1);
		key->res[i++] = '.';
		while (prec-- > 1)
		{
			num *= 10;
			val = (int)num;
			num -= val;
			key->res[i++] = val + '0';
		}
		num *= 10;
		val = (int)num;
		num *= 10;
		diff = (int)num;
		if (diff >= 5)
		{
			if (diff == 9)
			{
				while (key->res[i--] == '9')
				{
					ddd = 0;
					key->res[i] = ddd + '0';
					if (key->res[--i] != 9)
					{
						ddd = key->res[i] - '0';
						ddd--;
						key->res[i] = ddd + '0';
						break ;
					}
				}
				val = 0;
			}
			else
				val++;
		}
		key->res[i] = val + '0';
	}
}

void	ft_float_size(t_key *key)
{
	int size;
	int len;
	int j;

	if (!key->res)
		key->res = ft_strdup("0.0");
	size = 1;
	j = key->res[0] == '-' ? 1 : 0;
	len = ft_strlen(key->res) - j;
	key->fpsize = key->p == -1 ? 6 : key->p;
	size += key->fpsize + len;
	key->wsize = key->w - size > 0 ? key->w - size - len : 0;
	size = key->wsize > 0 ? key->w : size;
	key->wsize = j || key->flags->s ? 1 : 0;
	key->finsize = size + key->wsize;
}

void	ft_bef_float(double num, t_key *key)
{
	double	num1;
	int			count;
	int			elem;
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
	while (count-- > 0)
	{
		num1 *= 10;
		elem = (int)num1;
		num1 -= elem;
		key->res[i++] = elem + '0';
	}
	ft_float_size(key);
	key->final = ft_strnew(key->finsize);
	ft_aft_float(num1, key, i);
	key->p = -1;
	key->fpsize = key->wsize + ft_strlen(key->res);
	ft_modifyint(key);
}
