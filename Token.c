#include "Token.h"
#include <stdio.h>
#include <stdlib.h>

Token constructToken(unsigned short int type, char *value)
{
  Token token;
  token.type = type;
  token.value = value;

  return token;
}

void destructToken(Token *token)
{
  free(token);
}

void destructTokenNode(Token *token)
{
  free(token->value);
}

unsigned short int getType(Token *token)
{
  return token->type;
}

void setType(Token *token, unsigned short int type)
{
  token->type = type;
}

char *getValue(Token *token)
{
  return token->value;
}

void setValue(Token *token, char *value)
{
  token->value = value;
}
