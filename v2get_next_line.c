/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2get_next_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdevessi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:50:20 by bdevessi          #+#    #+#             */
/*   Updated: 2018/11/16 17:29:36 by bdevessi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

static int	read_buffer(t_buffer *buffer, char **str)
{
	char	*nl;
	char	*tmp;

	if (buffer->length == 0)
		return (1);
	nl = ft_memchr(buffer->payload, '\n', buffer->length);
	//printf("%p\n",nl);
	if (nl)
	{
		*str = ft_strndup(buffer->payload, nl - buffer->payload);
	//	printf("%s|%s|%zu", buffer->payload, *str, BUFF_SIZE - (nl - buffer->payload));
		ft_memcpy(buffer->payload, nl, BUFF_SIZE - (nl - buffer->payload));
	//	printf("%s|%s", buffer->payload, *str);
		buffer->length = nl - buffer->payload;
		return (0);
	}
	else
	{
		tmp = *str;
		*str = *str ? ft_strjoin(*str, buffer->payload) : ft_strdup(buffer->payload);
	//	printf("%s\n", *str);
		free(tmp);
		return (1);
	}
}

int			get_next_line(const int fd, char **line)
{
	static t_buffer		buffer;
	int					result;
	ssize_t				read_bytes;

	*line = NULL;
	while ((result = read_buffer(&buffer, line)))
	{
		read_bytes = read(fd, buffer.payload, BUFF_SIZE);
		buffer.length = read_bytes;
		if (read_bytes < 0)
		{
			free(*line);
			return (-1);
		}
		if (read_bytes == 0)
			return (0);
	}
	return (1);
	while ((read_bytes = read(fd, buffer.payload, BUFF_SIZE)) > 0)
		;
}

/*int			get_next_line(const int fd, char **line)
{
	static t_buffer		buffer;
	ssize_t				read_bytes;
	char				*newline;
	char				*tmp;
	char				*str;

	newline = ft_memchr(buffer.payload, '\n', BUFF_SIZE);
	buffer.length = newline ? BUFF_SIZE - (newline - buffer.payload) : BUFF_SIZE;
	tmp = NULL;
	if (newline)
	{
		tmp = ft_strsub(buffer.payload, 0, buffer.length);
		ft_memcpy(buffer.payload, newline, BUFF_SIZE - buffer.length);
		if (tmp == NULL)
			return (-1);
		*line = tmp;
	}
	if (newline)
		return (1);
	str = NULL;
	read_bytes = 0;
	while ((read_bytes = read(fd, buffer.payload, BUFF_SIZE)) > 0)
	{
		newline = ft_strchr(buffer.payload, '\n');
		buffer.length = newline ? BUFF_SIZE - (newline - buffer.payload) : 0;
		str = ft_strndup(buffer.payload, newline ? newline - buffer.payload : read_bytes);
		if (tmp)
			tmp = ft_strjoin(tmp, str);
		else
			tmp = str;
		if (newline)
		{
			*line = tmp;
			ft_memcpy(buffer.payload, newline + 1, buffer.length);
			return (1);
		}
	}
	return (0);
}*/
