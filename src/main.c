#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/Error.h"
#include "../includes/Scanners.h"
#include "../includes/Token.h"
#include "../includes/Utils.h"

// Machine states
#define INITIAL_STATE 0

unsigned short int position = 0;

Token nextToken(char *content, size_t count)
{
  char *term = (char *)malloc(100 * sizeof(char));

  unsigned short int currentState = INITIAL_STATE;

  while (position <= count)
  {
    char currentChar = content[position];

    if (currentChar == '\0')
    {
      break;
    }

    switch (currentState)
    {
    case INITIAL_STATE:
      if (isLetter(currentChar))
      {
        strncat(term, &currentChar, 1);
        currentState = 1;
      }
      else if (isDigit(currentChar))
      {
        strncat(term, &currentChar, 1);
        currentState = 3;
      }
      else if (isOperator(currentChar))
      {
        strncat(term, &currentChar, 1);
        currentState = 5;
      }
      else if (isSemicolon(currentChar))
      {
        strncat(term, &currentChar, 1);
        currentState = 8;
      }
      else if (isSpace(currentChar))
      {
        currentState = 0;
      }
      else
      {
        throwError(1, "Error: Invalid character");
        exit(1);
      }
      break;
    case 1:
      if (isLetter(currentChar) || isDigit(currentChar))
      {
        currentState = 1;
        strncat(term, &currentChar, 1);
      }
      else if (isSpace(currentChar) || isSemicolon(currentChar))
      {
        currentState = 2;
      }
      break;
    case 3:
      if (isDigit(currentChar))
      {
        currentState = 3;
        strncat(term, &currentChar, 1);
      }
      else
      {
        currentState = 4;
      }
      break;
    case 5:
      if (isOperator(currentChar))
      {
        currentState = 7;
        strncat(term, &currentChar, 1);
      }
      else
      {
        currentState = 6;
      }
      break;
    case 2:
      position--;
      return constructToken(TOKEN_TYPE_IDENTIFIER, term);
      break;
    case 4:
      position--;
      return constructToken(TOKEN_TYPE_NUMBER, term);
      break;
    case 6:
      position--;
      return constructToken(TOKEN_TYPE_ASSIGN, term);
      break;
    case 7:
      return constructToken(TOKEN_TYPE_OPERATOR, term);
      break;
    case 8:
      return constructToken(TOKEN_TYPE_SEMICOLON, term);
      break;
    default:
      throwError(currentState, "Error: Invalid state");
      exit(1);
    }
    position++;
  }

  free(term);
  return constructToken(TOKEN_TYPE_END, NULL);
}

void lexialMachine(char *content, size_t count)
{
  Token token = token = nextToken(content, count);

  short int i = 0;
  do {
    printf("{ token.count: %d, token.type: %d, token.value: %s }\n", i, token.type, token.value);
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
