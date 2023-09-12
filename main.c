#include <stdio.h>
#include <stdlib.h>

// Local Modules import
#include "Error.h"
#include "Scanners.h"
#include "Token.h"

#define MAX_LINES 100
#define MAX_CHARS 10000

size_t
charCount(FILE *attachFile)
{
  size_t count = 0;
  char c;

  while ((c = fgetc(attachFile)) != EOF) {
    count++;
  }

  fseek(attachFile, 0, SEEK_SET);
  return count;
}

int main(void)
{
  FILE *attachFile;
  attachFile = fopen("analisador_lexico.code", "r");

  if (attachFile == NULL) {
    throwError(1, "Error: File not found\n");
    exit(1);
  }

  size_t count = charCount(attachFile);

  if (count == 0) {
    throwError(1, "Error: File is empty");
    return 1;
  }

  char *content = (char *)malloc(count * sizeof(char));

  if (content == NULL) {
    throwError(1, "Error: Memory not allocated");
    return 1;
  }

  size_t bytes_lidos = fread(content, 1, count, attachFile);

  printf("count: %zu\n", count);
  printf("content: %s\n", content);
  printf("bytes_lidos: %zu\n", bytes_lidos);

  Token token = constructToken(TOKEN_TYPE_IDENTIFIER, "let");

  printf("token.type: %d\n", token.type);
  printf("token.value: %s\n", token.value);

  fclose(attachFile);
  free(content);
  return 0;
}
