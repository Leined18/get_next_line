#include "get_next_line.h"

static int  get_buffer(int fd,char **store)
{
    char    buffer[BUFFER_SIZE + 1];
    char    *aux;
    int     rd;

    rd = 0;
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
        aux = (*store);
        (*store) = ft_strjoin((*store), buffer);
        free(aux);
        if (!(*store))
            return (-1);
    }
    return (0);
}

static char *get_line(char **store)
{
    size_t  len;
    size_t  i;
    char    *res;
    char    *aux;

    len = 0;
	i = -1;
	aux = 0;
    if (!(*store)[len])
        return (NULL);
    while ((*store)[len] && (*store)[len] != '\n')
        len++;
    if ((*store)[len] == '\n')
        len++;
    res = ft_calloc(sizeof(char), len + 1);
    if (!res)
        return (NULL);
    while ((*store)[++i] && i < len)
        res[i] = (*store)[i];
    aux = (*store);
    (*store) = ft_strdup((*store) + len);
    if (!(*store))
        return (free(aux), free(res), NULL);
    return (free(aux), res);
}

void	*del(char **s)
{
	free((*s));
	(*s) = 0;
	return (NULL);
}

char    *get_next_line(int fd)
{
    static char *store;
    char        *res;
    int         aux;

    if (fd < 0 || BUFFER_SIZE < 0)
        return (NULL);
    if (!store || (*store && !ft_strchr(store, '\n')))
        aux = get_buffer(fd, &store);
    if (aux < 0 || !store)
        return (del(&store));
    if (store && *store)
        res = get_line(&store);
    if (!res)
        return (del(&store));
    return (res);
}
/*
int main()
{
	int fd;
    char    *aux;

	fd = open("lol.txt", O_RDONLY); // Changed O_WRONLY to O_RDONLY
	aux = get_next_line(fd);
    printf("%s", aux);
	return (0);
}*/
