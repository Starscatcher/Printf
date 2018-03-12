/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:35:53 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/05 11:35:54 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <inttypes.h>
# include "../libft/libft.h"

typedef struct		s_flags
{
	int m;
	int z;
	int p;
	int s;
	int g;
}					t_flags;

typedef struct		s_len
{
	int	hh;
	int	h;
	int	l;
	int	ll;
	int	j;
	int	z;
}					t_len;

typedef struct		s_key
{
	t_flags		*flags;
	int			w;
	int			p;
	t_len		*len;
	char		s;
	char		*res;
	int			fpsize;
	int			wsize;
	int			finsize;
	char		re;
	wchar_t		wre;
	wchar_t		*wres;
	char		*final;
}					t_key;

void				ft_float_size(t_key *key);
void				ft_modifychar(t_key *key);
void				ft_charsize(t_key *key);
void				ft_print_char(t_key *key);
t_key				*ft_make_struct(void);
void				ft_unicharprint(t_key *key);
void				ft_bef_float(long double num, t_key *key);
void				ft_uniprint(t_key *key);
void				ft_unisize(wchar_t i);
void				ft_modifyint(t_key *key);
int					ft_size(t_key *key);
int					ft_modify(t_key *key, va_list args, int ret);
int					ft_findin(char *arr, char elem);
void				ft_readtype(t_key *key, va_list args);
int					ft_printf(const char *format, ...);
char				*ft_itoa_bss(ssize_t val, int b);
char				*ft_itoa_bs(size_t val, int b);
int					ft_is_key(va_list args, t_key *key, const char *fo, int i);

#endif
