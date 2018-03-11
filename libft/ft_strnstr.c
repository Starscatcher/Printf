/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:48 by aryabenk          #+#    #+#             */
/*   Updated: 2017/10/30 15:22:49 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	if (needle[0] == '\0')
		return (char *)(&haystack[i]);
	while (haystack[i] && i < len)
	{
		j = i;
		k = 0;
		while (haystack[j] == needle[k] && j < len)
		{
			if (needle[k + 1] == '\0')
			{
				return (char *)(&haystack[i]);
			}
			j++;
			k++;
		}
		i++;
	}
	return (0);
}
