#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 100

int clients[MAX_CLIENTS];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

/* -------- Broadcast function -------- */
void broadcast(char *msg, int sender_fd) {
    pthread_mutex_lock(&lock);
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if(clients[i] != 0 && clients[i] != sender_fd) {
            send(clients[i], msg, strlen(msg), 0);
        }
    }
    pthread_mutex_unlock(&lock);
}

/* -------- Write chat log -------- */
void log_message(char *msg) {
    FILE *f = fopen("log.txt", "a");
    if(f) {
        fprintf(f, "%s\n", msg);
        fclose(f);
    }
}

/* -------- Thread function for each client -------- */
void *client_handler(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char msg[1024];

    while(1) {
        int read_size = recv(sock, msg, sizeof(msg), 0);
        if(read_size <= 0) break;   // client disconnected
        
        msg[read_size] = '\0';

        log_message(msg);      // save to log
        broadcast(msg, sock);  // send to others
        printf("%s\n", msg);   // print on server
    }

    // Remove client
    pthread_mutex_lock(&lock);
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if(clients[i] == sock) {
            clients[i] = 0;
            break;
        }
    }
    pthread_mutex_unlock(&lock);

    close(sock);
    pthread_exit(NULL);
}

/* -------------------- MAIN SERVER -------------------- */
int main() {
    int server_fd, newfd;
    struct sockaddr_in server, client;
    pthread_t thread_id;
    socklen_t c = sizeof(struct sockaddr_in);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&server, sizeof(server));
    listen(server_fd, 10);

    printf("Chat Server started on port %d...\n", PORT);

    while((newfd = accept(server_fd, (struct sockaddr *)&client, &c))) {
        printf("Client connected\n");

        pthread_mutex_lock(&lock);
        for(int i = 0; i < MAX_CLIENTS; i++) {
            if(clients[i] == 0) {
                clients[i] = newfd;
                break;
            }
        }
        pthread_mutex_unlock(&lock);

        if(pthread_create(&thread_id, NULL, client_handler, (void *)&newfd) < 0) {
            perror("Thread creation failed");
            return 1;
        }
    }

    return 0;
}

