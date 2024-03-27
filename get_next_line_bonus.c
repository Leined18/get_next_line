#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{

}

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

    while ((line = get_next_line(fd2)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd1);
    close(fd2);
    
    return (0);
}