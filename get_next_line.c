#include "get_next_line.h"

char    *get_next_line(int fd)
{
    int sz;
    char* c = (char*)calloc(100, sizeof(char));

    if (fd < 0) {
        perror("r1");
        exit(1);
    }
    
    sz = read(fd, c, 3);
    c[sz] = '\0';
    printf("Those bytes are as follows: %s\n", c);
    return (NULL);
}

int main()
{
	int fd;

	fd = open("lol.txt", O_RDONLY); // Changed O_WRONLY to O_RDONLY
	get_next_line(fd);
	return (0);
}
