#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <stdio.h>
#include "../includes/Token.h"

#define INITIAL_STATE 0
#define MAX_LINE_SIZE 1024
#define MAX_TERM_SIZE 1000

typedef struct
{
  FILE *file;
  char *line;
  short int globalTokensCount;
  int newLine;
  unsigned short int positionCount;
  unsigned int lineCount;
  unsigned short int isEOF;
} LexicalAnalyzer;

LexicalAnalyzer *createLexicalAnalyzer(const char *filePath);
void closeLexicalAnalyzer(LexicalAnalyzer *lexicalAnalyzer);
Token nextToken(LexicalAnalyzer *lexicalAnalyzer);

#endif