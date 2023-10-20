#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

size_t charCount(FILE *attachFile);
char *readLine(FILE *file, size_t MAX_LINE_SIZE);

#endif