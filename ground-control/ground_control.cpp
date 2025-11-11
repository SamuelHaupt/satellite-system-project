#include <iostream>
#include <cstring>
#include <array>
#include <string_view>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

constexpr int PORT = 8080;

int main() {
    int sockfd;
    uint8_t bit;
    struct sockaddr_in server_addr{}, client_addr{};
    socklen_t client_len = sizeof(client_addr);
    
    // Create UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return -1;
    }
    
    // Configure server address (already zero-initialized)
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind socket to port
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        close(sockfd);
        return -1;
    }
    
    std::cout << "UDP Server listening on port " << PORT << std::endl;
    
    // Receive messages
    while (true) {
        
        ssize_t n = recvfrom(sockfd, &bit, sizeof(bit), 0,
                        (struct sockaddr *)&client_addr, &client_len);
        
        if (n < 0) {
            std::cerr << "Receive failed" << std::endl;
            continue;
        }
        
        std::cout << "Received from " << inet_ntoa(client_addr.sin_addr) 
                  << ":" << ntohs(client_addr.sin_port) 
                  << " - " << static_cast<int>(bit) << std::endl;
        
        // Echo back to client
        constexpr std::string_view response = "Message received";
        sendto(sockfd, response.data(), response.length(), 0,
               (const struct sockaddr *)&client_addr, client_len);
    }
    
    close(sockfd);
    return 0;
}
