#include <stdio.h>
#include <stdlib.h>

size_t charCount(FILE *attachFile)
{
  size_t count = 0;
  char c;

  while ((c = fgetc(attachFile)) != EOF)
  {
    count++;
  }

  fseek(attachFile, 0, SEEK_SET);
  return count;
}

char *readLine(FILE *file, size_t MAX_LINE_SIZE)
{
  char *line = (char *)malloc(MAX_LINE_SIZE * sizeof(char));

  if (!line)
  {
    fprintf(stderr, "Error: Memory allocation failed\n");
    exit(1);
  }

  if (fgets(line, MAX_LINE_SIZE, file) == NULL)
  {
    free(line);
    return NULL;
  }

  return line;
}
