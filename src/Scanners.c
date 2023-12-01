#include <stdio.h>

unsigned short int isDigit(char c)
{
  return c >= '0' && c <= '9';
}

unsigned short int isString(char c)
{
  return c == '"';
}

unsigned short int isLetter(char c)
{
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

unsigned short int isLetterLowCase(char c)
{
  return c >= 'a' && c <= 'z';
}

unsigned short int isLetterUpperCase(char c)
{
  return c >= 'A' && c <= 'Z';
}

unsigned short int isSpace(char c)
{
  return c == ' ' || c == '\t' || c == '\r';
}

unsigned short int isNewLine(char c)
{
  return c == '\n';
}

unsigned short int isOperator(char c)
{
  return c == '=' || c == '<' || c == '>' || c == '!' || c == '+' || c == '-' || c == '*' || c == '/';
}

unsigned short int isSemicolon(char c)
{
  return c == ';';
}

unsigned short int isEOF(char c)
{
  return c == '\0';
}
