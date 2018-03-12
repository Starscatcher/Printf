/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 09:54:25 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/05 09:54:26 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_i(const char *format, int i, t_key *key)
{
	if (key->res && key->s != 's' && key->s != 'S')
		ft_strdel(&key->res);
	if (key->final)
		ft_strdel(&key->final);
	free(key->flags);
	free(key->len);
	free(key);
	while (format[i] != key->s)
		i++;
	return (++i);
}

int		ft_print_else(const char *format, int i, int *ret)
{
	write(1, &format[i++], 1);
	*ret += 1;
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	t_key	*key;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			key = ft_make_struct();
			if (!ft_is_key(args, key, format, ++i))
				break ;
			ret += ft_modify(key, args, ret);
			if (key->final)
				write(1, key->final, key->finsize);
			i = ft_find_i(format, i, key);
		}
		else
			i = ft_print_else(format, i, &ret);
	}
	va_end(args);
	return (ret);
}

int		ft_findin(char *arr, char elem)
{
	int j;

	j = 0;
	while (arr && arr[j])
	{
		if (arr[j] == elem)
			return (1);
		j++;
	}
	return (0);
}
