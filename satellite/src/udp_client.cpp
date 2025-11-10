#include <iostream>
#include <cstring>
#include <array>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "udp_client.h"

constexpr int PORT = 8080;
constexpr size_t BUFFER_SIZE = 1024;

int udp_client() {
    int sockfd;
    std::array<char, BUFFER_SIZE> buffer{};
    struct sockaddr_in server_addr{};
    socklen_t server_len = sizeof(server_addr);
    
    // Create UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return -1;
    }
    
    // Configure server address (already zero-initialized)
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
    // Convert localhost to binary
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address" << std::endl;
        close(sockfd);
        return -1;
    }
    
    std::cout << "Sat Downlink started. Type messages to send (or 'quit' to exit):" << std::endl;
    
    // Send messages
    while (true) {
        std::cout << "> ";
        std::cin.getline(buffer.data(), buffer.size());
        
        if (strcmp(buffer.data(), "quit") == 0) {
            break;
        }
        
        // Send message to server
        sendto(sockfd, buffer.data(), strlen(buffer.data()), 0,
               (const struct sockaddr *)&server_addr, server_len);
        
        // Receive response
        buffer.fill(0);
        ssize_t n = recvfrom(sockfd, buffer.data(), buffer.size(), 0,
                        (struct sockaddr *)&server_addr, &server_len);
        
        if (n > 0) {
            buffer[n] = '\0';
            std::cout << "Server response: " << buffer.data() << std::endl;
        }
    }
    
    close(sockfd);
    std::cout << "Client closed" << std::endl;
    return 0;
}
