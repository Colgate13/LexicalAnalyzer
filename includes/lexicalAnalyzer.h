#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include "../includes/Token.h"
#include <stdio.h>

#define INITIAL_STATE 0

Token nextToken(char *content, size_t count);

#endif