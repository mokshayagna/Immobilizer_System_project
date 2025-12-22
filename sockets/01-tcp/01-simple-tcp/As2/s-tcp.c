#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>

int main()
{
    int sockfd = 0, newfd = 0;
    socklen_t len;
    int retval = 0, i;
    struct sockaddr_in serv_addr, client;
    char recvBuff[1025];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000);

    bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(sockfd, 10);

    len = sizeof(client);
    newfd = accept(sockfd, (struct sockaddr*)&client, &len);

    retval = recv(newfd, recvBuff, sizeof(recvBuff)-1, 0);
    recvBuff[retval] = '\0';

    printf("S: Client request : %s\n", recvBuff);

    // Convert to CAPS and print
    for (i = 0; recvBuff[i] != '\0'; i++) {
        recvBuff[i] = toupper((unsigned char)recvBuff[i]);
    }

    printf("S: CAPS OUTPUT : %s\n", recvBuff);

    close(newfd);
    close(sockfd);
    return 0;
}
