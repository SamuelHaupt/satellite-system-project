# cat -e -t Makefile  # view makefile tabulated commands

CXX := g++

CXXFLAGS := -std=c++17 -Wall -Wextra

SOURCES := \
udp_server.cpp 

OBJECTS := $(patsubst %/src/%.cpp, %/build/%.o, $(SOURCES))

TARGET := bin/GroundControl

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

build/%.o: %/src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/%.d: %/src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) -MMD $(CXXFLAGS) $< > $@

clean:
	rm -f build/* $(TARGET)