#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8081
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET sockfd;
    char buffer[BUFFER_SIZE];
    char *response = "Hello from UDP Server!";
    struct sockaddr_in servaddr, cliaddr;
    int len = sizeof(cliaddr);

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("WSAStartup failed.\n");
        return 1;
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed.\n");
        WSACleanup();
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == SOCKET_ERROR) {
        printf("Bind failed.\n");
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    printf("UDP Server running on port %d...\n", PORT);
    int n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0, (struct sockaddr *)&cliaddr, &len);
    if (n > 0) {
        buffer[n] = '\0';
        printf("Client says: %s\n", buffer);
    }

    sendto(sockfd, response, (int)strlen(response), 0, (struct sockaddr *)&cliaddr, len);
    printf("Response sent.\n");

    closesocket(sockfd);
    WSACleanup();

    return 0;
}