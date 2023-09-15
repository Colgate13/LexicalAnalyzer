SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = bin

CC = clang # compiler
CFLAGS =-g -Wall -Wextra # compiler flags
TARGET = main # output file
SOURCE_FILE = $(SRC_DIR)/main.c # source file

SOURCES = $(SRC_DIR)/Error.c $(SRC_DIR)/Scanners.c $(SRC_DIR)/Token.c $(SRC_DIR)/Utils.c # sources
HEADERS = $(INCLUDE_DIR)/Error.h $(INCLUDE_DIR)/Scanners.h $(INCLUDE_DIR)/Token.h $(INCLUDE_DIR)/Utils.h # headers

OUTPUT_FILE = $(BIN_DIR)/$(TARGET)

$(info Compile Project with: $(CC))
$(info OUTPUT_FILE: $(OUTPUT_FILE))

all: $(OUTPUT_FILE)

$(OUTPUT_FILE): $(SOURCES) $(SOURCE_FILE) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(OUTPUT_FILE) $(SOURCES) $(SOURCE_FILE)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
