/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdevessi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:48:57 by bdevessi          #+#    #+#             */
/*   Updated: 2018/11/23 11:34:08 by bdevessi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main()
{
	char	*line = NULL;
	int	fd = open("./text.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		printf("%s", line);
}
