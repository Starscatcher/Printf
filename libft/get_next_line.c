/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <aryabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:26:56 by aryabenk          #+#    #+#             */
/*   Updated: 2018/01/12 17:04:35 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_get_to_list(t_lst *list, int fd)
{
	t_lst *newlist;

	while (list->fd != fd)
	{
		if (list->next == NULL)
		{
			if (!(newlist = (t_lst*)malloc(sizeof(t_lst))))
				return (NULL);
			list->next = newlist;
			list = list->next;
			list->fd = fd;
			list->next = NULL;
			list->text = ft_strdup("\0");
			return (list);
		}
		list = list->next;
	}
	return (list);
}

int		if_n(char **line, t_lst *list, int ret)
{
	int		i;
	char	*temp;
	int		size;

	i = 0;
	if (list->text && list->text[i] && (ft_strchr(list->text, '\n') || !ret))
	{
		while (list->text[i] && list->text[i] != '\n')
			i++;
		*line = ft_strnew(i + 1);
		*line = ft_strncpy(*line, list->text, i);
		if (list->text[i] == '\n')
			i++;
		size = list->text ? ft_strlen(list->text + i) : 0;
		temp = ft_strnew(size);
		if (list->text + i)
			temp = ft_strcpy(temp, list->text + i);
		ft_strdel(&list->text);
		list->text = temp;
		return (1);
	}
	return (0);
}

t_lst	*ft_new_list(t_lst *head, int fd)
{
	if (!(head))
	{
		if (!(head = (t_lst*)malloc(sizeof(t_lst))))
			return (NULL);
		head->fd = fd;
		head->next = NULL;
		head->text = ft_strdup("\0");
	}
	return (head);
}

int		get_next_line(const int fd, char **line)
{
	static t_lst	*head;
	t_lst			*list;
	int				ret;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE < 0)
		return (-1);
	*line = NULL;
	head = ft_new_list(head, fd);
	list = ft_get_to_list(head, fd);
	if (if_n(line, list, 1) == 1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		list->text = ft_realloc(list->text, ft_strlen(list->text) + ret);
		list->text = ft_strcat(list->text, buf);
		if (if_n(line, list, ret) == 1)
			return (1);
	}
	return ((if_n(line, list, ret) == 1) && line[0] ? 1 : 0);
}
