/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 10:34:58 by aryabenk          #+#    #+#             */
/*   Updated: 2017/10/27 10:34:59 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*arr;
	size_t			i;
	unsigned char	sign;

	arr = (unsigned char *)s;
	sign = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (arr[i] == sign)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
