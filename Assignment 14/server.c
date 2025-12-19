#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd, newsock;
    char buffer[1024];
    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr*)&server, sizeof(server));
    listen(sockfd, 3);

    printf("Server waiting...\n");
    newsock = accept(sockfd, (struct sockaddr*)&client, &len);

    read(newsock, buffer, sizeof(buffer));
    printf("Received from client: %s\n", buffer);

    char *msg = "Hello from server\n";
    write(newsock, msg, strlen(msg));

    close(newsock);
    close(sockfd);
    return 0;
}

