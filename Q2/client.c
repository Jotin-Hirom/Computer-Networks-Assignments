#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 9000
#define SERVER_IP "10.0.0.1"
#define DATA_SIZE (2 * 1024 * 1024)
#define THREADS 8

void* send_data(void* arg) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servaddr;

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &servaddr.sin_addr);

    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    char *data = malloc(DATA_SIZE);
    memset(data, 'A' + (long)arg, DATA_SIZE);

    int sent = 0;
    while (sent < DATA_SIZE) {
        sent += send(sockfd, data + sent, 4096, 0);
    }

    close(sockfd);
    free(data);
    return NULL;
}

int main() {
    pthread_t threads[THREADS];

    for (long i = 0; i < THREADS; i++)
        pthread_create(&threads[i], NULL, send_data, (void*)i);

    for (int i = 0; i < 8; i++)
        pthread_join(threads[i], NULL);

    return 0;
}

