#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/Error.h"
#include "../includes/Scanners.h"
#include "../includes/Token.h"
#include "../includes/Utils.h"
#include "../includes/lexicalAnalyzer.h"

#define INITIAL_STATE 0
#define MAX_LINE_SIZE 1024

int main(int argc, char *argv[])
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

  char *line = (char *)malloc(MAX_LINE_SIZE * sizeof(char));

  while (fgets(line, MAX_LINE_SIZE, attachFile) != NULL)
  {
    size_t count = strlen(line);
    lexialMachine(line, count, 1);
  }

  fclose(attachFile);
  free(line);
  return 0;
}
