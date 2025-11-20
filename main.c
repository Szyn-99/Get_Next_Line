/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szyn <szyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 01:17:39 by szyn              #+#    #+#             */
/*   Updated: 2025/11/20 01:19:50 by szyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("test.txt", O_RDONLY);
	s = "A";
	while (s)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		printf("%s", s);
		free(s);
	}
	close(fd);
	return (0);
}
