#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/socket.h>

#define PORT 9000
#define BUF_SIZE 4096

int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr;
    char buffer[BUF_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(sockfd, 20);

    FILE *log = fopen("server_log.txt", "w");

    while (1) {
        connfd = accept(sockfd, NULL, NULL);

        while (1) {
            int bytes = recv(connfd, buffer, BUF_SIZE, 0);
            if (bytes <= 0) break;

            struct timeval tv;
            gettimeofday(&tv, NULL);

            fprintf(log, "Time: %ld.%06ld Bytes: %d\n",
                    tv.tv_sec, tv.tv_usec, bytes);
            fflush(log);
        }
        close(connfd);
    }
}

