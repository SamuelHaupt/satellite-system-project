CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -Isrc

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

$(shell mkdir -p $(BUILD_DIR) $(BIN_DIR))

all: $(BIN_DIR)/satellite

satellite: $(BIN_DIR)/satellite

$(BIN_DIR)/satellite: $(BUILD_DIR)/main.o $(BUILD_DIR)/sat_downlink.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.o $(BIN_DIR)/satellite