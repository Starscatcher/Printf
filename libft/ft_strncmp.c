/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:36:50 by aryabenk          #+#    #+#             */
/*   Updated: 2017/10/30 15:36:51 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n && s1[i] && s2[i])
	{
		i++;
		if (i >= n)
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
