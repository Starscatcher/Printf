/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:37:57 by aryabenk          #+#    #+#             */
/*   Updated: 2017/11/01 12:37:57 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_cou(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static	int		ft_len(char const *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static void		*ft_free(char **res)
{
	ft_memdel((void**)res);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		f;

	i = 0;
	f = 0;
	if (!s || !(result = (char**)malloc(sizeof(char*) * ft_cou(s, c) + 1)))
		return (NULL);
	while (s[f])
	{
		j = 0;
		while (s[f] == c && s[f])
			f++;
		if (s[f] == '\0')
			break ;
		if (!(result[i] = (char*)malloc(sizeof(char) * ft_len(s + f, c) + 1)))
			return (ft_free(result));
		while (s[f] != c && s[f])
			result[i][j++] = s[f++];
		result[i][j] = '\0';
		i++;
	}
	result[i] = NULL;
	return (result);
}
