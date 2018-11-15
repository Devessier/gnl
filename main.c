/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdevessi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:48:57 by bdevessi          #+#    #+#             */
/*   Updated: 2018/11/15 16:50:41 by bdevessi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main()
{
	int	fd = open("./text.txt", O_RDONLY);
	char	*line = NULL;
	int i =0;
	while (i++ < 10 && get_next_line(fd, &line))
		printf("print : =%s=", line);
}
