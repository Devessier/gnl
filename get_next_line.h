/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdevessi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:09:49 by bdevessi          #+#    #+#             */
/*   Updated: 2018/11/16 17:09:57 by bdevessi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 9
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_buffer
{
	char	payload[BUFF_SIZE];
	size_t	length;
}				t_buffer;

int		get_next_line(const int fd, char **line);

#endif
