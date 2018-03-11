/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:18:23 by aryabenk          #+#    #+#             */
/*   Updated: 2017/11/04 12:18:23 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long long bla;

	bla = n;
	if (bla < 0)
	{
		ft_putchar('-');
		bla = -bla;
	}
	if (bla > 9)
	{
		ft_putnbr(bla / 10);
		ft_putnbr(bla % 10);
	}
	else
		ft_putchar(bla + '0');
}
