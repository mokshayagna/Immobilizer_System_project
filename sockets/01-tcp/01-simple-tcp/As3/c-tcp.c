#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define NUM_SENDS 5

int main()
{
    int sockfd;
    char sendBuff[1024] = "hello world";
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(5000);

    connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    for (int i = 0; i < NUM_SENDS; i++) {
        send(sockfd, sendBuff, strlen(sendBuff), 0);
        printf("C: Sent %d time(s)\n", i + 1);
        sleep(1);   // just to see output clearly
    }

    close(sockfd);
    return 0;
}
