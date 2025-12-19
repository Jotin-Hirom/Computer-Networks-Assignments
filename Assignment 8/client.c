#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8080

int sock;

/* -------- Receive thread -------- */
void *receive_handler(void *arg) {
    char msg[1024];

    while(1) {
        int read_size = recv(sock, msg, sizeof(msg), 0);
        if(read_size > 0) {
            msg[read_size] = '\0';
            printf("\n%s\n", msg);
        }
    }
    return NULL;
}

/* -------------------- MAIN CLIENT -------------------- */
int main() {
    struct sockaddr_in server;
    pthread_t recv_thread;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");  // use Mininet IP if needed

    connect(sock, (struct sockaddr *)&server, sizeof(server));

    pthread_create(&recv_thread, NULL, receive_handler, NULL);

    printf("Connected to chat. Type messages:\n");

    while(1) {
        char msg[1024];
        fgets(msg, sizeof(msg), stdin);
        send(sock, msg, strlen(msg), 0);
    }

    return 0;
}

