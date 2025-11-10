CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I../include

SRC_DIR = ..
TEST_DIR = .
BUILD_DIR = build
BIN_DIR = bin

$(shell mkdir -p $(BUILD_DIR) $(BIN_DIR))

# Build the test executable
$(BIN_DIR)/test_binary_converter: $(BUILD_DIR)/test_binary_converter.o $(BUILD_DIR)/binary_converter.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo ""
	@echo "Test executable built: $(BIN_DIR)/test_binary_converter"
	@echo "Run with: ./$(BIN_DIR)/test_binary_converter"

test_binary_converter: $(BIN_DIR)/test_binary_converter

# Compile test file
$(BUILD_DIR)/test_binary_converter.o: $(TEST_DIR)/test_binary_converter.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile binary_converter
$(BUILD_DIR)/binary_converter.o: $(SRC_DIR)/src/binary_converter.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run tests
test: $(BIN_DIR)/test_binary_converter
	@echo ""
	@echo "Running tests..."
	@echo ""
	./$(BIN_DIR)/test_binary_converter

# Clean build artifacts
clean:
	rm -f $(BUILD_DIR)/*.o $(BIN_DIR)/*

.PHONY: test clean
