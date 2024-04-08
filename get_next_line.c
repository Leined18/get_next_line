/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:35:47 by danpalac          #+#    #+#             */
/*   Updated: 2024/04/01 21:47:59 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// #include "get_next_line_utils.c"

static void	*del(char **s)
{
	free((*s));
	(*s) = 0;
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != '\0')
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	if (*ptr == (char)c)
		return (ptr);
	return (0);
}

static char	*get_buffer(int fd, char *store, char *buffer)
{
	char		*aux;
	long int	rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (del(&store), NULL);
		else if (rd == 0)
			break ;
		buffer[rd] = 0;
		if (!store)
			store = ft_strdup("");
		aux = store;
		store = ft_strjoin(aux, buffer);
		free(aux);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (store);
}

static char	*get_line(char *line_buffer)
{
	char	*res;
	size_t	i;

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
	static char	*store;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		buffer = NULL;
		store = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = get_buffer(fd, store, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (del(&store));
	store = get_line(line);
	return (line);
}
/*
int	main(void)
{
	int		fd1;
	char	*s;

	fd1 = open("file.txt", O_RDONLY);
	s = get_next_line(fd1);
	printf("%s", s);
	s = get_next_line(fd1);
	printf("%s", s);
	return (0);
}
*/