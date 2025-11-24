/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:00:08 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/11/24 17:50:25 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*process_reading_helper(char *storage, char *temp)
{
	char	*concatenated_results;

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
	return (NULL);
}

char	*process_read(char *storage, int fd)
{
	char	*temp;
	ssize_t	bytes_read;

	bytes_read = 1;
	temp = malloc((size_t)BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (bytes_read)
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
		if (ft_strchr(storage, '\n'))
			break ;
	}
	free(temp);
	return (storage);
}

char	*process_line_extract(char *storage)
{
	int		line_length;
	char	*line;

	line_length = 0;
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
		line[line_length++] = '\n';
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
		i++;
	if (storage[i] == '\n')
		i++;
	resized_storage = malloc(ft_strlen(storage) - i + 1);
	if (!resized_storage)
		return (NULL);
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
	static char	*storage[OPEN_MAX];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	line = NULL;
	storage[fd] = process_read(storage[fd], fd);
	line = process_line_extract(storage[fd]);
	storage[fd] = process_storage_resize(storage[fd]);
	return (line);
}
