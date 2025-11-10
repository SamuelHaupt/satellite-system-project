#include <iostream>
#include <vector>
#include <cstdint>
#include "binary_converter.h"


/**
 * explain bitwise operation
 */
std::vector<uint8_t> BinaryConverter::encodeToBits(const std::vector<uint8_t>& bytes) {
    std::vector<uint8_t> bits;

    // Pre-allocated space on heap.
    bits.reserve(bytes.size() * 8);

    for (uint8_t byte : bytes) {

        for (int i = 7; i >= 0; i--) {
            uint8_t bit = (byte >> i) & 0x01; // Shift and mask to get single bit
            bits.push_back(bit);
        }
    }

    return bits;
}


std::vector<uint8_t> BinaryConverter::decodeToBytes(const std::vector<uint8_t>& bits) {
    std::vector<uint8_t> bytes;
    
    // Validate: must have complete bytes
    if (bits.size() % 8 != 0) {
        throw std::invalid_argument("Bit stream size must be multiple of 8");
    }
    
    bytes.reserve(bits.size() / 8);
    
    // Combine every 8 bits into a byte
    for (size_t i = 0; i < bits.size(); i += 8) {
        uint8_t byte = 0;
        
        // Reconstruct byte from 8 bits (MSB to LSB)
        for (int j = 0; j < 8; j++) {
            byte = (byte << 1) | (bits[i + j] & 0x01);
        }
        
        bytes.push_back(byte);
    }
    
    return bytes;
}

void BinaryConverter::printBits(const std::vector<uint8_t>& bits) {
    for (size_t i = 0; i < bits.size(); i++) {
        std::cout << (int)bits[i];
        
        // Add space every 8 bits for readability
        if ((i + 1) % 8 == 0) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}