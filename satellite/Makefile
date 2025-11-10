PROJECT_ROOT := $(shell dirname $(CURDIR))
SAT_SRC_DIR := $(CURDIR)/src
SAT_INCLUDE_DIR := $(CURDIR)/include
SAT_BUILD_DIR := $(CURDIR)/build
SAT_BIN_DIR := $(CURDIR)/bin
COMMON_SRC_DIR := $(PROJECT_ROOT)/common/src
COMMON_INCLUDE_DIR := $(PROJECT_ROOT)/common/include
COMMON_BUILD_DIR := $(PROJECT_ROOT)/common/build

$(shell mkdir -p $(SAT_BUILD_DIR) $(SAT_BIN_DIR) $(COMMON_BUILD_DIR))

CXX = g++
SAT_CXXFLAGS = -std=c++17 -Wall -Wextra -I$(SAT_INCLUDE_DIR) -I$(SAT_SRC_DIR)
COMMON_CXXFLAGS = -std=c++17 -Wall -Wextra -I$(COMMON_INCLUDE_DIR) -I$(COMMON_SRC_DIR)


all: $(SAT_BIN_DIR)/Satellite

satellite: $(SAT_BIN_DIR)/Satellite

$(SAT_BIN_DIR)/Satellite: $(SAT_BUILD_DIR)/main.o $(SAT_BUILD_DIR)/sat_downlink.o $(COMMON_BUILD_DIR)/bit_converter.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(SAT_BUILD_DIR)/%.o: $(SAT_SRC_DIR)/%.cpp
	$(CXX) $(SAT_CXXFLAGS) -c $< -o $@

$(COMMON_BUILD_DIR)/%.o: $(COMMON_SRC_DIR)/%.cpp
	$(CXX) $(COMMON_CXXFLAGS) -c $< -o $@

clean:
	rm -f $(SAT_BUILD_DIR)/*.o $(COMMON_BUILD_DIR)/*.o $(SAT_BIN_DIR)/Satellite