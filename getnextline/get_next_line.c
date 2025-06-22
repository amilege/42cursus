/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:46:37 by amile-ge          #+#    #+#             */
/*   Updated: 2023/12/07 18:53:07 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*be_free(char **to_free)
{
	free(*to_free);
	*to_free = NULL;
	return (NULL);
}

char	*fill_storage(int fd, char *storage)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (be_free (&storage));
	bytes_read = 1;
	buffer[0] = '\0';
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (be_free (&storage));
		}
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			storage = ft_strjoin(storage, buffer);
		}
	}
	free (buffer);
	return (storage);
}

char	*only_line(char	*storage)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!storage || !*storage)
		return (NULL);
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	i++;
	if (!ft_strchr(storage, '\n'))
		line = (char *)malloc(sizeof(char) * i);
	else
		line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	if (!ft_strchr(storage, '\n'))
		line[i - 1] = '\0';
	else
		line[i] = '\0';
	while (j < i)
		line[j++] = *storage++;
	return (line);
}

char	*update_storage(char *storage)
{
	char	*new_storage;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!storage || !*storage)
		return (NULL);
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	i++;
	new_storage = ft_substr(storage, i, ft_strlen(storage));
	free (storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!storage || (storage && !ft_strchr(storage, '\n')))
		storage = fill_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = only_line(storage);
	if (!line)
		return (be_free(&storage));
	storage = update_storage(storage);
	return (line);
}
/*
int main() {
    int file;
    char *readfile;

    file = open("variable_nls.txt", O_RDONLY);

    if (file == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }
    while ((readfile = get_next_line(file)) != NULL) {
		printf("Línea leída:%s\n", readfile);
        free(readfile);
   }
    close(file);

    return 0;
}
*/
