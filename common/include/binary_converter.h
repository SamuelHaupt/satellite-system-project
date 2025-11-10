#ifndef BINARY_CONVERTER_H
#define BINARY_CONVERTER_H

#include <vector>
#include <iostream>
#include <cstdint>


class BinaryConverter {
public:
    BinaryConverter();

    /**
     * Convert bytes to individual bits
     * @param bytes Vector of bytes to convert
     * @return Vector where each element is a single bit (0 or 1)
     * 
     * Example: {0x48} -> {0,1,0,0,1,0,0,0}
     */
    std::vector<uint8_t> encodeToBits(const std::vector<uint8_t>& bytes);

    /**
     * Convert bits back to bytes (inverse operation)
     * @param bits Vector of individual bits
     * @return Vector of bytes
     * @throws std::invalid_argument if bits.size() is not multiple of 8
     * 
     * Example: {0,1,0,0,1,0,0,0} -> {0x48}
     */
    std::vector<uint8_t> decodeToBytes(const std::vector<uint8_t>& bits);

    /**
     * Print bits in readable format (groups of 8)
     * @param bits Vector of bits to print
     */
     void printBits(const std::vector<uint8_t>& bits);
};

#endif