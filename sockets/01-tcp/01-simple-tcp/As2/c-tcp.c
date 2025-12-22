#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int sockfd = 0;
    char sendBuff[1024] = "hello world";
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(5000);

    connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    send(sockfd, sendBuff, strlen(sendBuff), 0);

    printf("C: Message sent to server\n");

    close(sockfd);
    return 0;
}
