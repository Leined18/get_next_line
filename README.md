
## Get Next Line

### Description
**get_next_line** is a C function designed to read and return the next line from a file each time it is called. It is useful for processing files line by line, such as reading text files, logs, or any file where lines represent meaningful units of data.

---

## Usage

### Prototype:
```c
int get_next_line(int fd, char **line);
```

- **fd**: The file descriptor of the file to be read.
- **line**: A pointer to a memory area where the function will store the next read line.

### Return Values:
- **1**: A line has been successfully read.
- **0**: End of file (EOF) has been reached.
- **-1**: An error occurred (e.g., invalid file descriptor or memory allocation error).

### Example:
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
This example opens a file, reads it line by line, prints each line, and frees the allocated memory before closing the file descriptor.

---

## How It Works

### 1. File Reading:
`get_next_line` reads the file referenced by `fd` in fixed-size blocks using the `read` function. The size of each block is defined by the **BUFFER_SIZE** macro. It stores the data read in an internal buffer.

### 2. Line Search:
The function searches the internal buffer for a newline character (`\n`), which indicates the end of a line.

### 3. Line Return:
When a newline is found, the function copies the line (including any characters up to but not including `\n`) into the pointer `line` passed as an argument. It then updates the internal file cursor to begin reading from the next character.

### 4. Multiple Calls:
Successive calls to `get_next_line` continue reading from where the last call left off. The function maintains an internal state, allowing for multiple lines to be processed without needing to reopen the file. It also supports reading from multiple files concurrently by keeping independent states for each file descriptor.

---

## Compilation

To compile your program with **get_next_line**, use the following command:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=xx file.c get_next_line.c get_next_line_utils.c -o program
```

- Replace **xx** with your desired buffer size, which controls how much data is read at a time from the file.
- Include `get_next_line.h` in your program to use the function.

---

## Notes:
- Choose an appropriate **BUFFER_SIZE** depending on the size of the file you are processing. A larger buffer size can lead to fewer system calls but might use more memory.
- Make sure to handle memory allocation properly by freeing the lines returned by `get_next_line` after use.
