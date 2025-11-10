#ifndef BINARY_CONVERTER_H
#define BINARY_CONVERTER_H

#include <vector>
#include <iostream>
#include <cstdint>


class BinaryConverter {
public:
    BinaryConverter();
    std::vector<uint8_t> encodeToBits(const std::vector<uint8_t>& bytes);
    std::vector<uint8_t> decodeToBytes(const std::vector<uint8_t>& bits);
    void printBits(const std::vector<uint8_t>& bits);
private:
    std::vector<uint8_t> bits;
    std::vector<uint8_t> bytes;
};

#endif