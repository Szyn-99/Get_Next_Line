/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:00:05 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/11/19 17:38:58 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 24
#endif


#ifndef OPEN_MAX
#define OPEN_MAX 1024
#endif

char	*ft_strchr(const char *s, int c);
char *get_next_line(int fd);
char	*ft_strjoin(char  *s1, char  *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup( char *s);


#endif