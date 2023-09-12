#!/bin/sh

set -ex

CFLAGS="-Wall -Wextra"

# Main source file
SOURCE_FILE="main.c"

# Local Modules
MODULES_LOCAL="Error.c Scanners.c Token.c"

# Output file
OUTPUT_FILE="main"

# Compilação
clang $CFLAGS -o $OUTPUT_FILE $MODULES_LOCAL $SOURCE_FILE