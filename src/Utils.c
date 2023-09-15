#include <stdio.h>

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