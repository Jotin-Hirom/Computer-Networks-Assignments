#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

void receive_file(int sock) {
    char filename[100];
    int bytes;
    FILE *fp;
    char buffer[1024];

    recv(sock, filename, sizeof(filename), 0);
    printf("Uploading file: %s\n", filename);

    fp = fopen(filename, "wb");
    while ((bytes = recv(sock, buffer, 1024, 0)) > 0) {
        fwrite(buffer, 1, bytes, fp);
        if (bytes < 1024) break;
    }
    fclose(fp);
    printf("Uploaded successfully.\n");
}

void send_file(int sock) {
    char filename[100];
    FILE *fp;
    char buffer[1024];
    int bytes;

    recv(sock, filename, sizeof(filename), 0);

    fp = fopen(filename, "rb");
    if (!fp) { 
        printf("File not found!\n"); 
        return; 
    }

    while ((bytes = fread(buffer, 1, 1024, fp)) > 0) {
        send(sock, buffer, bytes, 0);
    }
    fclose(fp);
    printf("File sent successfully.\n");
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    char command[10];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);

    printf("Server waiting...\n");

    while (1) {
        new_socket = accept(server_fd, NULL, NULL);
        recv(new_socket, command, sizeof(command), 0);

        if (strcmp(command, "DOWNLOAD") == 0)
            send_file(new_socket);
        else if (strcmp(command, "UPLOAD") == 0)
            receive_file(new_socket);

        close(new_socket);
    }

    return 0;
}
