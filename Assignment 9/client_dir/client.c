#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PORT 8080

void download_file(int sock) {
    struct timeval start, end;
    char filename[100];
    int bytes;
    char buffer[1024];
    FILE *fp;

    printf("Enter server filename to download: ");
    scanf("%s", filename);

    send(sock, filename, sizeof(filename), 0);

    fp = fopen(filename, "wb");

    gettimeofday(&start, NULL);

    while ((bytes = recv(sock, buffer, 1024, 0)) > 0) {
        fwrite(buffer, 1, bytes, fp);
        if (bytes < 1024) break;
    }

    gettimeofday(&end, NULL);
    fclose(fp);

    double time_taken = (end.tv_sec - start.tv_sec)*1000.0 +
                        (end.tv_usec - start.tv_usec)/1000.0;

    printf("Download completed in %.3f ms\n", time_taken);
}

void upload_file(int sock) {
    struct timeval start, end;
    char filename[100];
    FILE *fp;
    char buffer[1024];
    int bytes;

    printf("Enter client filename to upload: ");
    scanf("%s", filename);

    send(sock, filename, sizeof(filename), 0);

    fp = fopen(filename, "rb");
    if (!fp) { printf("File not found.\n"); return; }

    gettimeofday(&start, NULL);

    while ((bytes = fread(buffer, 1, 1024, fp)) > 0) {
        send(sock, buffer, bytes, 0);
    }

    gettimeofday(&end, NULL);

    double time_taken = (end.tv_sec - start.tv_sec)*1000.0 +
                        (end.tv_usec - start.tv_usec)/1000.0;

    fclose(fp);

    printf("Upload completed in %.3f ms\n", time_taken);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char choice[10];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("10.0.0.1"); // server IP in Mininet

    connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));

    printf("1. Download\n2. Upload\nEnter choice: ");
    scanf("%s", choice);

    send(sock, choice[0] == '1' ? "DOWNLOAD" : "UPLOAD", 10, 0);

    if (choice[0] == '1')
        download_file(sock);
    else
        upload_file(sock);

    close(sock);
    return 0;
}




