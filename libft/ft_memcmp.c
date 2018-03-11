/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:16:29 by aryabenk          #+#    #+#             */
/*   Updated: 2017/10/27 11:16:29 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*arr1;
	unsigned char	*arr2;
	size_t			i;
	int				res;

	i = 0;
	arr1 = (unsigned char*)s1;
	arr2 = (unsigned char*)s2;
	while (n > 0)
	{
		if (arr1[i] > arr2[i])
		{
			res = arr1[i] - arr2[i];
			return (res);
		}
		else if (arr1[i] < arr2[i])
		{
			res = arr1[i] - arr2[i];
			return (res);
		}
		i++;
		n--;
	}
	return (0);
}
