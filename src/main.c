#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/Error.h"
#include "../includes/Scanners.h"
#include "../includes/Token.h"
#include "../includes/Utils.h"
#include "../includes/lexicalAnalyzer.h"

#define INITIAL_STATE 0

void lexialMachine(char *content, size_t count)
{
  Token token = token = nextToken(content, count);

  short int i = 0;
  do {
    printf("{ count: %d, token: { name: %s, type: %d, value: %s }\n", i, tokenTypeName(token.type), token.type, token.value);
    i++;
  } while (token = nextToken(content, count), token.type != TOKEN_TYPE_END);
}

int main(int argc, char *argv[] )
{
  printf("Lexical Analyzer\n");
  printf("File attach: %s\n", argv[1]);

  if (argc < 2)
  {
    throwError(1, "Error: File not found\n");
    exit(1);
  }

  FILE *attachFile;
  attachFile = fopen(argv[1], "r");

  if (attachFile == NULL)
  {
    throwError(1, "Error: File not found\n");
    exit(1);
  }

  size_t count = charCount(attachFile);

  if (count == 0)
  {
    throwError(1, "Error: File is empty");
    return 1;
  }

  char *content = (char *)malloc(count * sizeof(char));

  if (content == NULL)
  {
    throwError(1, "Error: Memory not allocated");
    return 1;
  }

  size_t content_size = fread(content, 1, count, attachFile);

  lexialMachine(content, content_size);

  fclose(attachFile);
  free(content);
  return 0;
}
