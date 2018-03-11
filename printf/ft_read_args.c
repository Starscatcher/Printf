/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:07:15 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/05 10:07:16 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_di(t_key *key, va_list args)
{
	if (key->len->z)
		key->res = ft_itoa_bss(va_arg(args, ssize_t), 10);
	else if (key->len->j)
		key->res = ft_itoa_bss(va_arg(args, intmax_t), 10);
	else if (key->len->ll)
		key->res = ft_itoa_bss(va_arg(args, long long int), 10);
	else if (key->len->l)
		key->res = ft_itoa_bss(va_arg(args, long int), 10);
	else if (key->len->h)
		key->res = ft_itoa_bss((short int)va_arg(args, int), 10);
	else if (key->len->hh)
		key->res = ft_itoa_bss((char)va_arg(args, int), 10);
	else
		key->res = ft_itoa_bss(va_arg(args, int), 10);
}

void	ft_uox(t_key *key, va_list args)
{
	int s;

	if (ft_findin("xX", key->s))
		s = 16;
	else if (ft_findin("oO", key->s))
		s = 8;
	else
		s = 10;
	if (key->len->z == 1)
		key->res = ft_itoa_bs(va_arg(args, size_t), s);
	else if (key->len->j == 1)
		key->res = ft_itoa_bs(va_arg(args, uintmax_t), s);
	else if (key->len->ll == 1)
		key->res = ft_itoa_bs(va_arg(args, unsigned long long int), s);
	else if (key->len->l == 1)
		key->res = ft_itoa_bs(va_arg(args, unsigned long int), s);
	else if (key->len->h == 1)
		key->res = ft_itoa_bs((unsigned short int)va_arg(args, int), s);
	else if (key->len->hh == 1)
		key->res = ft_itoa_bs((unsigned char)va_arg(args, unsigned int), s);
	else
		key->res = ft_itoa_bs(va_arg(args, unsigned int), s);
}

void	ft_readtype(t_key *key, va_list args)
{
	if (ft_findin("DOU", key->s))
		key->len->l = 1;
	if (ft_findin("Ddi", key->s))
		ft_di(key, args);
	else if (ft_findin("oOuUxX", key->s))
		ft_uox(key, args);
	else if (key->s == 'c' && !key->len->l)
		key->re = (char)va_arg(args, int);
	else if (key->s == 's' && !key->len->l)
		key->res = va_arg(args, char*);
	else if (key->s == 'p')
		key->res = ft_itoa_bs((size_t)va_arg(args, void*), 16);
	else if (key->s == 'C' || key->s == 'c')
		key->wre = va_arg(args, wchar_t);
	else if (key->s == 'S' || key->s == 's')
		key->wres = va_arg(args, wchar_t*);
	else if (key->s == 'f' || key->s == 'F')
		ft_bef_float(va_arg(args, double), key);
}
