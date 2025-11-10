#include <vector>
#include <iostream>
#include <cstdint>
#include "sat_downlink.h"
#include "binary_converter.h"

SatDownlink::SatDownlink() {};

int SatDownlink::send(const std::vector<uint8_t>& bits) {
    BinaryConverter binaryConverter;
    binaryConverter.printBits(bits);
    return 0;
};
