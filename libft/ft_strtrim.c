/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:17:40 by aryabenk          #+#    #+#             */
/*   Updated: 2017/11/01 11:17:41 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*bla;
	int		i;
	int		l;

	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	i = 0;
	while (s[l - 1] == ' ' || s[l - 1] == '\t' || s[l - 1] == '\n')
		l--;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i++])
		l--;
	if (l <= 0)
		return (ft_strdup(""));
	bla = (char*)malloc(sizeof(char) * (l + 1));
	if (bla == NULL)
		return (NULL);
	s = s + i;
	i = -1;
	while (++i < l)
		bla[i] = s[i];
	bla[i] = '\0';
	return (bla);
}
