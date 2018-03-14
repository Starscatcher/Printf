/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:42:00 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/05 11:42:01 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_is_flag(t_key *key, const char *format, int i)
{
	int r;

	if ((r = (format[i] == '+')))
		key->flags->p = 1;
	else if ((r = (format[i] == '-')))
		key->flags->m = 1;
	else if ((r = (format[i] == '0')))
		key->flags->z = 1;
	else if ((r = (format[i] == ' ')))
		key->flags->s = 1;
	else if ((r = (format[i] == '#')))
		key->flags->g = 1;
	else if ((r = (format[i] == 'L')))
		key->flags->l = 1;
	else if ((r = (format[i] == 't')))
		key->flags->t = 1;
	return (r);
}

static	int	ft_is_width(t_key *key, const char *format, int i, va_list args)
{
	if (format[i] == '*')
	{
		key->w = va_arg(args, int);
		if (key->w < 0)
		{
			key->flags->m = 1;
			key->w = -key->w;
		}
		return (++i);
	}
	key->w = ft_atoi(format + i);
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

static	int	ft_is_precision(t_key *key, const char *format, int i, va_list args)
{
	if (format[i] == '*')
	{
		key->p = va_arg(args, int);
		if (key->p < 0)
			key->p = -1;
		return (++i);
	}
	key->p = ft_atoi(format + i);
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

static	int	ft_is_length(t_key *key, const char *format, int i)
{
	int r;

	if ((r = (format[i] == 'h')))
	{
		key->len->hh = key->len->h ? 1 : 0;
		if ((r += (format[i + 1] == 'h')) == 2)
			key->len->hh = 1;
		else if (key->len->h)
			key->len->h = 0;
		else
			key->len->h = 1;
	}
	else if ((r = (format[i] == 'l')))
	{
		if ((r += (format[i + 1] == 'l')) == 2)
			key->len->ll = 1;
		else
			key->len->l = 1;
	}
	else if ((r = (format[i] == 'j')))
		key->len->j = 1;
	else if ((r = (format[i] == 'z')))
		key->len->z = 1;
	return (i + r);
}

int			ft_is_key(va_list args, t_key *key, const char *format, int i)
{
	while (!key->s && format[i])
	{
		if (ft_is_flag(key, format, i))
			i++;
		else if (ft_isdigit(format[i]) || format[i] == '*')
			i = ft_is_width(key, format, i, args);
		else if (format[i] == '.')
			i = ft_is_precision(key, format, ++i, args);
		else if (ft_findin("hljz", format[i]))
			i = ft_is_length(key, format, i);
		else
			key->s = format[i];
	}
	return (key->s);
}
