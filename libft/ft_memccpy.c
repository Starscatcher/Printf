/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 09:48:03 by aryabenk          #+#    #+#             */
/*   Updated: 2017/10/27 09:48:04 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*arr1;
	unsigned char	*arr2;
	size_t			i;

	arr1 = (unsigned char*)dst;
	arr2 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		arr1[i] = arr2[i];
		if (arr2[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
