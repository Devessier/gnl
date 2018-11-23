/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdevessi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:09:49 by bdevessi          #+#    #+#             */
/*   Updated: 2018/11/23 11:36:49 by bdevessi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096
# include "libft.h"
# include <limits.h>

typedef struct	s_buffer
{
	char	payload[BUFF_SIZE];
	ssize_t	length;
}				t_buffer;

int				get_next_line(const int fd, char **line);

#endif
