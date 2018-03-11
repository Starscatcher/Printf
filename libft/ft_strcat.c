/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:08:41 by aryabenk          #+#    #+#             */
/*   Updated: 2017/10/30 12:08:42 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int c;
	int g;

	c = 0;
	g = 0;
	while (dest[c])
	{
		c++;
	}
	while (src[g])
	{
		dest[c] = src[g];
		c++;
		g++;
	}
	dest[c] = '\0';
	return (dest);
}
