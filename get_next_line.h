#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define MAX_FD 1024

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>

// get_next_line
char	*get_next_line(int fd);

// utils
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
#endif