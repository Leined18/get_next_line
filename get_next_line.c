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

//#include "get_next_line_utils.c"

static char	get_buffer(int fd, char **store, char *buffer)
{
	char	*aux;
	size_t	rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (del(&store), NULL);
		else if (rd == 0)
			break ;
		buffer[rd] = 0;
		if (!*store)
			*store = ft_strdup("");
		aux = *store;
		*store = ft_strjoin(aux, buffer);
		free(aux);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (*store);
}

static char	*get_line(char **store)
{
	char	*res;
	char	*aux;
	size_t	len;
	size_t	i;

	len = 0;
	i = -1;
	res = 0;
	if (!(*store)[len])
		return (NULL);
	while ((*store)[len] && (*store)[len] != '\n')
		len++;
	if ((*store)[len] == '\n')
		len++;
	res = ft_calloc(sizeof(char), len + 1);
	while ((*store)[++i] && i < len)
		res[i] = (*store)[i];
	aux = (*store);
	(*store) = ft_strdup((*store) + len);
	if (!(*store))
		return (free(res), free(aux), NULL);
	return (free(aux), res);
}

static void	*del(char **s)
{
	free((*s));
	(*s) = 0;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;
	char		*buffer;

	buffer = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (free(buffer), buffer = NULL, del(&store));
	if (!buffer)
		return (NULL);
	if (!store || (*store && !ft_strchr(store, '\n')))
		line = get_buffer(fd, &store, buffer);
	free(buffer);
	if (!line || !store)
		return (del(&store));
	if ((*store) && (store))
		res = get_line(&store);
	if (!res)
		return (del(&store));
	return (res);
}

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
