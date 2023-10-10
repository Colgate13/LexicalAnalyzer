#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/Error.h"
#include "../includes/Scanners.h"
#include "../includes/Token.h"
#include "../includes/Utils.h"

#define INITIAL_STATE 0

unsigned short int position = 0;

Token nextToken(char *content, size_t count)
{
  char *term = (char *)malloc(1000 * sizeof(char));

  unsigned short int currentState = INITIAL_STATE;
  while (position <= count + 1)
  {
    char currentChar = content[position];

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
      else if (isEOF(currentChar))
      {
        currentState = 9;
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
      else
      {
        currentState = 2;
      }
      break;
    case 3:
      if (isDigit(currentChar) || currentChar == '.')
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
      return constructToken(TOKEN_TYPE_OPERATOR, term);
      break;
    case 7:
      return constructToken(TOKEN_TYPE_OPERATOR, term);
      break;
    case 8:
      return constructToken(TOKEN_TYPE_SEMICOLON, term);
      break;
    case 9:
      return constructToken(TOKEN_TYPE_END, NULL);
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
