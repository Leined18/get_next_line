#include "get_next_line_bonus.h"
#include "get_next_line_utils_bonus.c"

static size_t	find_next_line_break(char *str, size_t i)
{
	char	*ptr;

	ptr = str + i;
	while (*ptr && *ptr != '\n')
		ptr++;
	if (*ptr == '\n')
		ptr++;
	return (ptr - str);
}

static char	*create_substring(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*str)
		return (free(str), NULL);
	i = find_next_line_break(str, i);
	new_str = (char *)ft_calloc(sizeof(char), ft_strlen(str - i) + 1);
	if (!new_str)
		return (free(new_str), NULL);
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = 0;
	if (!*new_str)
		return (free(str), free(new_str), NULL);
	free(str);
	return (new_str);
}

static char	*read_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str || *str == 0)
		return (NULL);
	i = find_next_line_break(str, i);
	line = (char *)ft_calloc(sizeof(char), i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

static char	*free_null(char *buff1, char *buff2)
{
	free(buff1);
	free(buff2);
	buff2 = NULL;
	return (buff2);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			rd;
	static char	*store[MAX_FD];

	rd = 1;
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(store[fd], '\n') && rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			store[fd] = free_null(buffer, store[fd]);
			return (NULL);
		}
		buffer[rd] = 0; //0 == \0
		store[fd] = ft_strjoin(store[fd], buffer);
	}
	free(buffer);
	buffer = read_line(store[fd]);
	store[fd] = create_substring(store[fd]);
	return (buffer);
}
/*
int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);

    char *line;
    while ((line = get_next_line(fd1)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
	printf("\n");
    while ((line = get_next_line(fd2)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd1);
    close(fd2);
    
    return (0);
}*/