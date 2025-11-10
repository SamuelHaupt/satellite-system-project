#include <iostream>
#include <iomanip>
#include "sat_downlink.h"
#include "binary_converter.h"

int main() {
    // sat_downlink();

    BinaryConverter binaryConverter;
    SatDownlink satDownlink;

    // Convert to bits
    std::vector<uint8_t> data = {0x48, 0x65};  // "He"
    std::vector<uint8_t> bits = binaryConverter.encodeToBits(data);
    // bits = {0,1,0,0,1,0,0,0, 0,1,1,0,0,1,0,1}

    // Print bits
    binaryConverter.printBits(bits);
    // Output: "01001000 01100101"

    satDownlink.send(bits);
    

    return 0;
}
