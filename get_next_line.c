/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:00:08 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/11/19 18:00:07 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// »»-----► Number of lines: 13

static char *process_read(char *storage, int fd)
{

    char *temp = malloc((size_t)BUFFER_SIZE+1);
    ssize_t bytes_read;
    while(!ft_strchr(storage, '\n'))
    {
        bytes_read = read(fd, temp, BUFFER_SIZE);
        if(bytes_read == -1)
        {
            free(storage);
            free(temp);
            return NULL;
        }
        temp[bytes_read] = '\0';
        storage = ft_strjoin(storage, temp);
        if(bytes_read == 0)
            return (free(temp), storage);
    }
    free(temp);
    return storage;
}
// »»-----► Number of lines: 19
static char *process_line_extract(char *storage)
{
    int line_length = 0;
    char *line = NULL;
    if(!storage || !storage[0])
        return free(storage), NULL;
    while(storage[line_length] && storage[line_length] != '\n')
    {
        line_length++;
    }
    
    line = malloc(line_length+1+(storage[line_length] == '\n'));
    line_length = 0;
    while(storage[line_length] && storage[line_length] != '\n')
    {
        line[line_length] = storage[line_length];
        line_length++;
    }
    line[line_length] = '\n';
    line[line_length+1] = '\0';
    return line;
}
// »»-----► Number of lines: 21
static char *process_storage_resize(char *storage)
{
    int i = 0;
    int j = 0;
    if(!storage || !storage[0])
        return free(storage), NULL;
    char *resized_storage = NULL;
    while(storage[i] && storage[i] != '\n')
    {
        i++;
    }
    if(storage[i] == '\n')
        i++;
    resized_storage = malloc(ft_strlen(storage)- i + 1);
    while(storage[i])
    {
        resized_storage[j] = storage[i];
        i++;
        j++;
    }
    resized_storage[j] = '\0';
    free(storage);
    return resized_storage;
}
// »»-----► Number of lines: 6
char *get_next_line(int fd)
{
    static char *storage;
    char *line = NULL;

    if (fd >= OPEN_MAX || BUFFER_SIZE <= 0 || fd <= 0)
        return NULL;
    storage = process_read(storage, fd);
    line = process_line_extract(storage);
    storage = process_storage_resize(storage);
    return line;
}