SRC_DIR = src
INCLUDE_DIR = includes
BUILD_DIR = build
BIN_DIR = bin
LIB_DIR = lib

CC = clang # compiler
CFLAGS =-g -Wall -Wextra # compiler flags
TARGET = main # output file
SOURCE_FILE = $(SRC_DIR)/main.c # source file
LIBRARY_SO_FILE = liblexicalAnalyzer.so
LIBRARY_HEADER_FILE = lexicalAnalyzer.h

SOURCES = $(SRC_DIR)/Error.c $(SRC_DIR)/Scanners.c $(SRC_DIR)/Token.c $(SRC_DIR)/Utils.c $(SRC_DIR)/lexicalAnalyzer.c # sources
HEADERS = $(INCLUDE_DIR)/Error.h $(INCLUDE_DIR)/Scanners.h $(INCLUDE_DIR)/Token.h $(INCLUDE_DIR)/Utils.h $(INCLUDE_DIR)/lexicalAnalyzer.h # headers

OUTPUT_LIBRARY_FILE = $(LIB_DIR)/$(LIBRARY_SO_FILE)
CONSOLIDATED_HEADER := $(LIB_DIR)/$(LIBRARY_HEADER_FILE)
OUTPUT_FILE = $(BIN_DIR)/$(TARGET)

$(info Compile Project with: $(CC))
$(info OUTPUT_FILE: $(OUTPUT_FILE))
$(info OUTPUT_LIBRARY_FILE: $(LIBRARY))

all: $(CONSOLIDATED_HEADER) $(OUTPUT_LIBRARY_FILE) $(OUTPUT_FILE)

$(OUTPUT_FILE): $(SOURCES) $(SOURCE_FILE) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(OUTPUT_FILE) $(SOURCES) $(SOURCE_FILE)

$(OUTPUT_LIBRARY_FILE): $(SOURCES) | $(LIB_DIR)
	$(CC) $(CFLAGS) -fPIC -shared -o $(OUTPUT_LIBRARY_FILE) $(SOURCES)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

$(CONSOLIDATED_HEADER): $(HEADERS) | $(INCLUDE_DIR) $(LIB_DIR)
	@for header in $(HEADERS); do \
	  echo "#pragma once" >> $(CONSOLIDATED_HEADER); \
	  echo "" >> $(CONSOLIDATED_HEADER); \
	  sed '/#include "\.\.\//d' $$header >> $(CONSOLIDATED_HEADER); \
	  echo "" >> $(CONSOLIDATED_HEADER); \
	done

install: $(OUTPUT_FILE)
	sudo cp $(OUTPUT_LIBRARY_FILE) /usr/local/lib
	sudo cp $(LIB_DIR)/$(LIBRARY_HEADER_FILE) /usr/local/include

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR) $(LIB_DIR)
	sudo rm -rf /usr/local/lib/$(LIBRARY_SO_FILE)
	sudo rm -rf /usr/local/include/$(LIBRARY_HEADER_FILE)
