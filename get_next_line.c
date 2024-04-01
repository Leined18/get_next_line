/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:35:47 by danpalac          #+#    #+#             */
/*   Updated: 2024/04/01 18:59:14 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
//#include "get_next_line_utils.c"

static int	get_buffer(int fd, char **store)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*aux;
	size_t	rd;

	rd = 0;
	aux = 0;
	while (rd < BUFFER_SIZE)
		buffer[rd++] = 0;
	rd = 1;
	while (rd > 0 && !ft_strchr(buffer, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (-1);
		if (!rd)
			return (0);
		buffer[rd] = 0;
		aux = *store;
		*store = ft_strjoin(*store, buffer);
		free(aux);
		if (!(*store))
			return (-1);
	}
	return (0);
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
	int			aux;
	char		*res;

	res = 0;
	aux = 0;
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!store || (*store && !ft_strchr(store, '\n')))
		aux = get_buffer(fd, &store);
	if (aux < 0 || !store)
		return (del(&store));
	if ((*store) && (store))
		res = get_line(&store);
	if (!res)
		return (del(&store));
	return (res);
}
/*
int main()
{
	int fd1 = open("file.txt", O_RDONLY);
	char *s;

	s = get_next_line(1);
	printf("%s", s);
	s = get_next_line(fd1);

	printf("%s", s);
	return (0);
}*/
