/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 10:45:51 by aryabenk          #+#    #+#             */
/*   Updated: 2017/10/29 10:45:51 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int k;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			k = i;
			count++;
		}
		i++;
	}
	if (c == '\0')
		return ((char*)s + ft_strlen(s));
	if (count > 0)
		return ((char*)s + k);
	else
		k = 0;
	return (NULL);
}
