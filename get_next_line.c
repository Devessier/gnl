/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdevessi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:34:52 by bdevessi          #+#    #+#             */
/*   Updated: 2018/11/23 09:33:05 by bdevessi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	complete_partially(t_buffer *b, char *nl, char **string)
{
	char	*str;
	char	*tmp;

	tmp = *string;
	if ((!(str = ft_strndup(b->payload, nl - b->payload))
		|| !(*string = tmp ? ft_strjoin(*string, str) : str)))
	{
		free(str);
		free(*string);
		return (-1);
	}
	ft_memcpy(b->payload, nl + 1, b->length);
	if (tmp)
	{
		free(tmp);
		free(str);
	}
	b->length -= nl - b->payload + 1;
	return (0);
}

static int	read_buffer(const int fd, t_buffer *b, char **string)
{
	char	*nl;
	char	*tmp;

	if (fd < 0)
		return (-1);
	if (b->length == 0)
		return (1);
	if ((nl = ft_memchr(b->payload, '\n', b->length)))
		return (complete_partially(b, nl, string));
	tmp = *string;
	b->payload[b->length] = '\0';
	if (!(*string = tmp ? ft_strjoin(tmp, b->payload) : ft_strdup(b->payload)))
		return (-1);
	ft_bzero(b->payload, BUFF_SIZE);
	if (tmp)
		free(tmp);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_buffer		buffer[(long)INT_MAX + 1];
	int					result;
	ssize_t				read_bytes;
	char				*string;

	string = NULL;
	while ((result = read_buffer(fd, &buffer[fd], &string)))
	{
		if (result == -1
				|| (read_bytes = read(fd, buffer[fd].payload, BUFF_SIZE)) < 0)
		{
			if (string)
				free(string);
			return (-1);
		}
		if (buffer[fd].length && !read_bytes)
		{
			buffer[fd].length = read_bytes;
			break ;
		}
		else if (!buffer[fd].length && !read_bytes)
			return ((int)(*line = string) & 0);
		buffer[fd].length = read_bytes;
	}
	return ((int)(*line = string) || 1);
}
