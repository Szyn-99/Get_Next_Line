/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:00:05 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/11/18 22:42:11 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 24
#endif
char	*ft_strchr(const char *s, int c);
char *get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);


#endif