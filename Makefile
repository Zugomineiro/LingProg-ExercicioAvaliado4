CPP = g++
LD = g++

CPPFLAGS = -Wall -I$(INC_DIR)

ifeq ($(OS),Windows_NT)
	TARGET = main.exe
else
	TARGET = main
endif

# Pastas
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

SRC = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(INC_DIR)/*.cpp)
OBJ = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(notdir $(SRC)))


all: $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(INC_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CPP) $(CPPFLAGS) -o $@ $^

clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)
