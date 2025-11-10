#include <vector>
#include <iostream>
#include <cstdint>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "sat_downlink.h"
#include "binary_converter.h"

constexpr int PORT = 8080;

SatDownlink::SatDownlink() {};

int SatDownlink::send(const std::vector<uint8_t>& bits) {
    int sockfd;
    struct sockaddr_in server_addr{};
    socklen_t server_len = sizeof(server_addr);
    
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address" << std::endl;
        close(sockfd);
        return -1;
    }

    std::cout << "Sat Downlink started. Sending bit data now." << std::endl;

    // for (size_t idx = 0; idx < bits.size(); idx ++) {
    //     std::cout << bits[idx] << std::endl;
    // }
    int spacer = 0;
    for (uint8_t bit : bits) {
        std::cout << static_cast<int>(bit);
        spacer++;
        if (spacer == 8){ 
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    // BinaryConverter binaryConverter;
    // binaryConverter.printBits(bits);
    return 0;
};
