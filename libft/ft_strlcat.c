/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:08:07 by aryabenk          #+#    #+#             */
/*   Updated: 2017/10/30 14:08:08 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t len;

	len = ft_strlen(dst);
	if (dstsize > len)
		ft_strncat(dst, src, (dstsize - len - 1));
	if (dstsize < len)
		return (ft_strlen(src) + dstsize);
	else
		return (ft_strlen(src) + len);
}
