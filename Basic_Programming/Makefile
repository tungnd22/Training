CC := gcc
CFLAGS := -Wall -O2 -g

TARGET := final_program

SRC_DIR := ./src
BUILD_DIR := ./build

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:%.o=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/$(TARGET): $(OBJS)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -Iinclude $^ -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/$(TARGET)