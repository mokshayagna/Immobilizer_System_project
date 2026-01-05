#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

struct data{
    char cmd[16];
    int a;
    int b;
};

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    char buffer[1024];
    int a, b;
    struct data cdata;


    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 1);

    client_fd = accept(server_fd, NULL, NULL);


    recv(client_fd, &cdata, sizeof(cdata), 0);

    printf("cmd=%s a=%d b=%d\n", cdata.cmd, cdata.a, cdata.b);

    sprintf(buffer, "result=%d", cdata.a + cdata.b);
    send(client_fd, buffer, strlen(buffer), 0);

    close(client_fd);
    close(server_fd);
    return 0;
}
