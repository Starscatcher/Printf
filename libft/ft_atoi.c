/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:20:06 by aryabenk          #+#    #+#             */
/*   Updated: 2017/10/29 17:20:07 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					a;
	unsigned long int	end;

	i = 0;
	a = 1;
	end = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		a = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		end = (end * 10) + (str[i++] - '0');
		if (end >= 9223372036854775807 && a == 1)
			return (-1);
		else if (end > 9223372036854775807 && a == -1)
			return (0);
	}
	return (end * a);
}
