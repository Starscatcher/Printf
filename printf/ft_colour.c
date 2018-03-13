/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colour.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:56:16 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/13 13:56:16 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_what_colour(char *colour)
{
	int i;

	if ((i = !ft_strcmp("black", colour)))
		write(1, "\033[30m", 5);
	else if ((i = !ft_strcmp("red", colour)))
		write(1, "\033[31m", 5);
	else if ((i = !ft_strcmp("green", colour)))
		write(1, "\033[32m", 5);
	else if ((i = !ft_strcmp("yellow", colour)))
		write(1, "\033[33m", 5);
	else if ((i = !ft_strcmp("blue", colour)))
		write(1, "\033[34m", 5);
	else if ((i = !ft_strcmp("violet", colour)))
		write(1, "\033[35m", 5);
	else if ((i = !ft_strcmp("sea wave", colour)))
		write(1, "\033[36m", 5);
	else if ((i = !ft_strcmp("gray", colour)))
		write(1, "\033[37m", 5);
	return (i);
}

int			ft_is_colour(const char *format, int i)
{
	int		j;
	int		k;
	char	*colour;
	int		count;

	k = 0;
	j = i++;
	count = 0;
	colour = NULL;
	while (format[i] && format[i] != '}')
	{
		i++;
		count++;
	}
	if (format[i] == '}')
	{
		i = j + 1;
		colour = ft_strnew(count);
		while (count-- > 0)
			colour[k++] = format[i++];
	}
	!ft_strcmp("eoc", colour) ? write(1, "\033[0m", 4) : 0;
	i = !ft_what_colour(colour) && ft_strcmp("eoc", colour) ? j : ++i;
	colour ? ft_strdel(&colour) : 0;
	return (i);
}
