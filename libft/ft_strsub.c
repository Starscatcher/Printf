/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:00:20 by aryabenk          #+#    #+#             */
/*   Updated: 2017/11/03 17:00:21 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*bla;
	size_t	i;

	if (s == NULL)
		return (NULL);
	bla = (char*)malloc(sizeof(char) * len + 1);
	if (bla == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		bla[i] = s[start];
		i++;
		start++;
	}
	bla[i] = '\0';
	return (bla);
}
