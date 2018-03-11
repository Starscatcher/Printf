/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:13:45 by aryabenk          #+#    #+#             */
/*   Updated: 2017/10/26 11:13:46 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*bla1;
	char	*bla2;
	size_t	j;

	j = 0;
	if (n == 0 || dst == src)
		return (dst);
	bla1 = (char*)dst;
	bla2 = (char*)src;
	while (n > 0)
	{
		bla1[j] = bla2[j];
		j++;
		n--;
	}
	return (dst);
}
