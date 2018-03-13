/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:11:32 by aryabenk          #+#    #+#             */
/*   Updated: 2018/02/21 14:11:33 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_undersev(unsigned int v, unsigned char octet)
{
	octet = v;
	write(1, &octet, 1);
}

static	void	ft_underele(unsigned int v, unsigned char octet)
{
	unsigned int	mask1;
	unsigned char	o2;
	unsigned char	o1;

	mask1 = 49280;
	o2 = (v << 26) >> 26;
	o1 = ((v >> 6) << 27) >> 27;
	octet = (mask1 >> 8) | o1;
	write(1, &octet, 1);
	octet = ((mask1 << 24) >> 24) | o2;
	write(1, &octet, 1);
}

static	void	ft_undersix(unsigned int v, unsigned char octet)
{
	unsigned int	mask2;
	unsigned char	o3;
	unsigned char	o2;
	unsigned char	o1;

	mask2 = 14712960;
	o3 = (v << 26) >> 26;
	o2 = ((v >> 6) << 26) >> 26;
	o1 = ((v >> 12) << 28) >> 28;
	octet = (mask2 >> 16) | o1;
	write(1, &octet, 1);
	octet = ((mask2 << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask2 << 24) >> 24) | o3;
	write(1, &octet, 1);
}

static	void	ft_moresix(unsigned int v, unsigned char octet)
{
	unsigned int	mask3;
	unsigned char	o4;
	unsigned char	o3;
	unsigned char	o2;
	unsigned char	o1;

	mask3 = 4034953344;
	o4 = (v << 26) >> 26;
	o3 = ((v >> 6) << 26) >> 26;
	o2 = ((v >> 12) << 26) >> 26;
	o1 = ((v >> 18) << 29) >> 29;
	octet = (mask3 >> 24) | o1;
	write(1, &octet, 1);
	octet = ((mask3 << 8) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask3 << 16) >> 24) | o3;
	write(1, &octet, 1);
	octet = ((mask3 << 24) >> 24) | o4;
	write(1, &octet, 1);
}

void			ft_unisize(wchar_t i)
{
	size_t			size;
	unsigned int	v;
	char			*base;
	unsigned char	octet;

	octet = 0;
	v = i;
	base = ft_itoa_bss(i, 2);
	size = ft_strlen(base);
	ft_strdel(&base);
	if (MB_CUR_MAX <= 1)
		write(1, &i, 1);
	else if (size <= 7)
		ft_undersev(v, octet);
	else if (size <= 11)
		ft_underele(v, octet);
	else if (size <= 16)
		ft_undersix(v, octet);
	else
		ft_moresix(v, octet);
}
