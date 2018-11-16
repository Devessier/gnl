/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdevessi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:48:57 by bdevessi          #+#    #+#             */
/*   Updated: 2018/11/16 17:23:51 by bdevessi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main()
{
	int	fd = open("./text.txt", O_RDONLY);
	char	*line = NULL;
	while (get_next_line(fd, &line))
		puts(line);
}
