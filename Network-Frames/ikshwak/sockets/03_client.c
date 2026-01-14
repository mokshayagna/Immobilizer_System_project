#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

struct data{
    char cmd[16];
    int a;
    int b;
};

struct data client_frame_request(char *cmd, int a, int b)
{
    struct data cdata;

    cdata.a = a;
    cdata.b = b;
    strcpy(cdata.cmd, cmd);

    return cdata;
}

int main() {
    int sock;
    struct sockaddr_in addr;
    char buffer[1024];
    char cmd[] = "add";
    int a = 10;
    int b = 20;
    struct data c_request;
    int retval;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    connect(sock, (struct sockaddr*)&addr, sizeof(addr));

    c_request = client_frame_request(cmd, a, b);
    send(sock, &c_request, sizeof(c_request), 0);

    retval = recv(sock, buffer, sizeof(buffer), 0);
    buffer[retval] = '\0';
    printf("%s\n", buffer);

    close(sock);
    return 0;
}
