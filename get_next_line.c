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

char *process_reading_helper(char *storage, char *temp)
{
    char *concatenated_results = NULL;
    if (!storage && !temp)
		return (NULL);
	else if (!storage)
		return (ft_strdup(temp));
	else if (!temp)
	{
		concatenated_results = ft_strdup(storage);
        free(storage);
        return (concatenated_results);
    }
    else
    {
        concatenated_results = ft_strjoin(storage, temp);
        return (concatenated_results);
    }
    return NULL;
}

char	*process_read(char *storage, int fd)
{
	char	*temp;
	ssize_t	bytes_read;

	temp = malloc((size_t)BUFFER_SIZE + 1);
	while (!ft_strchr(storage, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(storage);
			free(temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		storage = process_reading_helper(storage, temp);
		if (bytes_read == 0)
			return (free(temp), storage);
	}
	free(temp);
	return (storage);
}

char	*process_line_extract(char *storage)
{
	int		line_length;
	char	*line;

	line_length = 0;
	line = NULL;
	if (!storage || !storage[0])
		return (NULL);
	while (storage[line_length] && storage[line_length] != '\n')
		line_length++;
	line = malloc(line_length + 1 + (storage[line_length] == '\n'));
	if (!line)
		return (NULL);
	line_length = 0;
	while (storage[line_length] && storage[line_length] != '\n')
	{
		line[line_length] = storage[line_length];
		line_length++;
	}
	if (storage[line_length] == '\n')
	{
		line[line_length] = '\n';
		line[line_length + 1] = '\0';
	}
	else
		line[line_length] = '\0';
	return (line);
}

char	*process_storage_resize(char *storage)
{
	int		i;
	int		j;
	char	*resized_storage;

	i = 0;
	j = 0;
	if (!storage || !storage[0])
		return (free(storage), NULL);
	resized_storage = NULL;
	while (storage[i] && storage[i] != '\n')
	{
		i++;
	}
	if (storage[i] == '\n')
		i++;
	resized_storage = malloc(ft_strlen(storage) - i + 1);
	while (storage[i])
	{
		resized_storage[j] = storage[i];
		i++;
		j++;
	}
	resized_storage[j] = '\0';
	free(storage);
	return (resized_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	line = NULL;
	if (fd >= OPEN_MAX || BUFFER_SIZE <= 0 || fd <= 0)
		return (NULL);
	storage = process_read(storage, fd);
	line = process_line_extract(storage);
	storage = process_storage_resize(storage);
	return (line);
}
