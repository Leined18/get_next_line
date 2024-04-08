/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:36:23 by danpalac          #+#    #+#             */
/*   Updated: 2024/04/01 16:36:25 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
//#include "get_next_line_utils_bonus.c"

static char	*get_buffer(int fd, char *store, char *buffer)
{
	char	*aux;
	ssize_t	rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(store);
			return (NULL);
		}
		else if (rd == 0)
			break ;
		buffer[rd] = 0;
		if (!store)
			store = ft_strdup("");
		aux = store;
		store = ft_strjoin(aux, buffer);
		free(aux);
		aux = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (store);
}

static char	*get_line(char *line_buffer)
{
	char	*res;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	res = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*res == 0)
	{
		free(res);
		res = NULL;
	}
	line_buffer[i + 1] = 0;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*store[MAX_FD];
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(store[fd]);
		free(buffer);
		buffer = NULL;
		store[fd] = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = get_buffer(fd, store[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (store[fd] = NULL, NULL);
	store[fd] = get_line(line);
	return (line);
}
/*
int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	line = get_next_line(fd1);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd1);
	}
	printf("\n");
	line = get_next_line(fd2);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
	}
	close(fd1);
	close(fd2);
	return (0);
}*/
