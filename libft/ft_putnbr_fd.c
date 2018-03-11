/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:27:15 by aryabenk          #+#    #+#             */
/*   Updated: 2017/11/04 12:27:16 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long bla;

	bla = n;
	if (bla < 0)
	{
		ft_putchar_fd('-', fd);
		bla = -bla;
	}
	if (bla > 9)
	{
		ft_putnbr_fd((bla / 10), fd);
		ft_putnbr_fd((bla % 10), fd);
	}
	else
		ft_putchar_fd((bla + '0'), fd);
}
