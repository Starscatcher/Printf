/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:31:22 by aryabenk          #+#    #+#             */
/*   Updated: 2017/11/03 11:31:23 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*newdest;
	unsigned char	*newsrc;

	newdest = (unsigned char *)dst;
	newsrc = (unsigned char *)src;
	if (newsrc < newdest)
	{
		while (len--)
			newdest[len] = newsrc[len];
	}
	else
		ft_memcpy(newdest, newsrc, len);
	return (dst);
}
