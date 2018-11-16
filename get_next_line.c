/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdevessi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:10:43 by bdevessi          #+#    #+#             */
/*   Updated: 2018/11/16 09:51:19 by bdevessi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

int				get_next_line(const int fd, char **line)
{
	static char		buffer[BUFF_SIZE];
	static char		*p;
	ssize_t			read_bytes;
	ssize_t			total_read_bytes;
	char			*tmp;
	char			*other_occurence;

	read_bytes = 0;
	total_read_bytes = read_bytes;
	tmp = NULL;
	if ((p = p ? p : ft_strchr(buffer, '\n')))
	{
		other_occurence = ft_strchr(p + 1, '\n');
		if (other_occurence != NULL)
		{
			// On a localise une autre occurence du retour chariot, on peut 
			tmp = ft_strsub(buffer, p - buffer + 1, other_occurence - p - 1);
			p = other_occurence;
			*line = tmp;
			return (1);
		}
	}
	while ((read_bytes = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		p = ft_memchr(buffer, '\n', read_bytes);
		tmp = ft_strnew(p - buffer);
		int	i = 0;
		char	*str = tmp;
		while (buffer[i] != '\n' && i < BUFF_SIZE)
			*tmp++ = buffer[i++];
		*tmp = '\0';
		printf("%s string\n", str);
		*line = ft_strjoin(*line, str);
	}
	return 1;
}
