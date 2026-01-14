#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd;
    char buffer[256];
    ssize_t bytesRead;

    fd = open("1.txt", O_RDONLY);
    if (fd < 0) {
        perror("File open failed");
        return 1;
    }

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    close(fd);
    return 0;
}
