#include <iostream>
#include <cassert>
#include <vector>
#include <cstdint>
#include "binary_converter.h"

// Test helper to compare vectors
bool vectorsEqual(const std::vector<uint8_t>& a, const std::vector<uint8_t>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// Test helper to print test results
void printTestResult(const std::string& testName, bool passed) {
    std::cout << "[" << (passed ? "PASS" : "FAIL") << "] " << testName << std::endl;
}

// Test 1: Single byte conversion
void testSingleByte() {
    BinaryConverter converter;
    
    // Test 'H' (0x48 = 01001000)
    std::vector<uint8_t> input = {0x48};
    std::vector<uint8_t> expected = {0, 1, 0, 0, 1, 0, 0, 0};
    
    std::vector<uint8_t> result = converter.encodeToBits(input);
    
    bool passed = vectorsEqual(result, expected);
    printTestResult("testSingleByte - 'H' (0x48)", passed);
    assert(passed);
}

// Test 2: Multiple bytes conversion
void testMultipleBytes() {
    BinaryConverter converter;
    
    // Test "Hi" (0x48, 0x69)
    std::vector<uint8_t> input = {0x48, 0x69};  // 'H', 'i'
    std::vector<uint8_t> expected = {
        0, 1, 0, 0, 1, 0, 0, 0,  // 0x48
        0, 1, 1, 0, 1, 0, 0, 1   // 0x69
    };
    
    std::vector<uint8_t> result = converter.encodeToBits(input);
    
    bool passed = vectorsEqual(result, expected);
    printTestResult("testMultipleBytes - 'Hi'", passed);
    assert(passed);
}

// Test 3: All zeros
void testAllZeros() {
    BinaryConverter converter;
    
    std::vector<uint8_t> input = {0x00};
    std::vector<uint8_t> expected = {0, 0, 0, 0, 0, 0, 0, 0};
    
    std::vector<uint8_t> result = converter.encodeToBits(input);
    
    bool passed = vectorsEqual(result, expected);
    printTestResult("testAllZeros - 0x00", passed);
    assert(passed);
}

// Test 4: All ones
void testAllOnes() {
    BinaryConverter converter;
    
    std::vector<uint8_t> input = {0xFF};
    std::vector<uint8_t> expected = {1, 1, 1, 1, 1, 1, 1, 1};
    
    std::vector<uint8_t> result = converter.encodeToBits(input);
    
    bool passed = vectorsEqual(result, expected);
    printTestResult("testAllOnes - 0xFF", passed);
    assert(passed);
}

// Test 5: Empty input
void testEmptyInput() {
    BinaryConverter converter;
    
    std::vector<uint8_t> input = {};
    std::vector<uint8_t> expected = {};
    
    std::vector<uint8_t> result = converter.encodeToBits(input);
    
    bool passed = vectorsEqual(result, expected);
    printTestResult("testEmptyInput", passed);
    assert(passed);
}

// Test 6: Decode single byte
void testDecodeSingleByte() {
    BinaryConverter converter;
    
    std::vector<uint8_t> input = {0, 1, 0, 0, 1, 0, 0, 0};
    std::vector<uint8_t> expected = {0x48};
    
    std::vector<uint8_t> result = converter.decodeToBytes(input);
    
    bool passed = vectorsEqual(result, expected);
    printTestResult("testDecodeSingleByte - 0x48", passed);
    assert(passed);
}

// Test 7: Decode multiple bytes
void testDecodeMultipleBytes() {
    BinaryConverter converter;
    
    std::vector<uint8_t> input = {
        0, 1, 0, 0, 1, 0, 0, 0,  // 0x48
        0, 1, 1, 0, 1, 0, 0, 1   // 0x69
    };
    std::vector<uint8_t> expected = {0x48, 0x69};
    
    std::vector<uint8_t> result = converter.decodeToBytes(input);
    
    bool passed = vectorsEqual(result, expected);
    printTestResult("testDecodeMultipleBytes", passed);
    assert(passed);
}

// Test 8: Round-trip conversion (encode then decode)
void testRoundTrip() {
    BinaryConverter converter;
    
    std::vector<uint8_t> original = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0};
    
    // Encode to bits
    std::vector<uint8_t> bits = converter.encodeToBits(original);
    
    // Decode back to bytes
    std::vector<uint8_t> decoded = converter.decodeToBytes(bits);
    
    bool passed = vectorsEqual(original, decoded);
    printTestResult("testRoundTrip - multiple bytes", passed);
    assert(passed);
}

// Test 9: Decode invalid input (not multiple of 8)
void testDecodeInvalidInput() {
    BinaryConverter converter;
    
    // Only 7 bits (should throw exception)
    std::vector<uint8_t> input = {0, 1, 0, 0, 1, 0, 0};
    
    bool exceptionThrown = false;
    try {
        converter.decodeToBytes(input);
    } catch (const std::invalid_argument& e) {
        exceptionThrown = true;
    }
    
    printTestResult("testDecodeInvalidInput - exception thrown", exceptionThrown);
    assert(exceptionThrown);
}

// Test 10: Edge case - maximum byte value
void testMaxByteValue() {
    BinaryConverter converter;
    
    std::vector<uint8_t> input = {0xFF, 0x00, 0xFF};
    std::vector<uint8_t> bits = converter.encodeToBits(input);
    std::vector<uint8_t> decoded = converter.decodeToBytes(bits);
    
    bool passed = vectorsEqual(input, decoded);
    printTestResult("testMaxByteValue - 0xFF patterns", passed);
    assert(passed);
}

// Test 11: Typical CCSDS packet data
void testCCSDSPacketData() {
    BinaryConverter converter;
    
    // Simulate CCSDS header + data
    std::vector<uint8_t> packet = {
        0x08, 0x00,  // Primary header word 1
        0xC0, 0x00,  // Primary header word 2
        0x00, 0x05,  // Data length
        0x42, 0x17, 0x89  // Telemetry data
    };
    
    std::vector<uint8_t> bits = converter.encodeToBits(packet);
    std::vector<uint8_t> decoded = converter.decodeToBytes(bits);
    
    bool passed = vectorsEqual(packet, decoded);
    printTestResult("testCCSDSPacketData - packet integrity", passed);
    assert(passed);
}

// Test 12: Bit count validation
void testBitCountCorrect() {
    BinaryConverter converter;
    
    std::vector<uint8_t> input = {0x12, 0x34, 0x56};
    std::vector<uint8_t> bits = converter.encodeToBits(input);
    
    bool passed = (bits.size() == input.size() * 8);
    printTestResult("testBitCountCorrect - 3 bytes = 24 bits", passed);
    assert(passed);
}

int main() {
    std::cout << "======================================" << std::endl;
    std::cout << "  Binary Converter Test Suite" << std::endl;
    std::cout << "======================================" << std::endl << std::endl;
    
    try {
        // Encoding tests
        std::cout << "--- Encoding Tests ---" << std::endl;
        testSingleByte();
        testMultipleBytes();
        testAllZeros();
        testAllOnes();
        testEmptyInput();
        testBitCountCorrect();
        
        std::cout << std::endl << "--- Decoding Tests ---" << std::endl;
        testDecodeSingleByte();
        testDecodeMultipleBytes();
        testDecodeInvalidInput();
        
        std::cout << std::endl << "--- Integration Tests ---" << std::endl;
        testRoundTrip();
        testMaxByteValue();
        testCCSDSPacketData();
        
        std::cout << std::endl << "======================================" << std::endl;
        std::cout << "  All tests passed! ✓" << std::endl;
        std::cout << "======================================" << std::endl;
        
        return 0;
        
    } catch (const std::exception& e) {
        std::cerr << std::endl << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    }
}
