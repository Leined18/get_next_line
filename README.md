# Get Next Line

## Description
`get_next_line` is a C function designed to read and return the next line from a text file each time it's called. This function is useful when you need to process a file line by line, such as reading text files, logs, or any other file where lines are meaningful units of information.

## Usage
### Prototype

    int get_next_line(int fd, char **line);

fd: The file descriptor of the file to be read.
line: The address of a pointer to an area of memory where the read line from the file will be stored.

Return

    Returns 1 if a line was successfully read.
    Returns 0 when the end of the file is reached.
    Returns -1 in case of an error.

Example Usage
```c
#include "get_next_line.h"

int main(void) {
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return (1);
    }
    while (get_next_line(fd, &line) > 0) {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
```
# Operation

    File Reading: The get_next_line function reads the content of the file referenced by fd in fixed-size blocks using the read function and stores the result in an internal buffer.
    Line Search: It searches for a line terminated by a newline ('\n') character in the internal buffer.
    Line Return: When a line is found, it copies it into the pointer line passed as an argument and advances the internal file cursor to the end of the line.
    Handling Multiple Calls: If the function is called repeatedly, it continues reading the file from where it left off last time and returns the next line. Each call maintains its own internal state, allowing multiple files to be read concurrently without interference.

# Compilation

    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=xx file.c get_next_line.c get_next_line_utils.c -o program

Make sure to replace xx with the desired buffer size.
Authors
