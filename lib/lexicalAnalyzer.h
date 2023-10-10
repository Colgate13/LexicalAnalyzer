#pragma once

#ifndef ERROR_H
#define ERROR_H

typedef struct
{
  int code;
  char *message;
} Error;

void throwError(int code, char *message);

#endif
#pragma once

#ifndef SCANNERS_H
#define SCANNERS_H

unsigned short int isDigit(char c);
unsigned short int isLetter(char c);
unsigned short int isLetterLowCase(char c);
unsigned short int isLetterUpperCase(char c);
unsigned short int isSpace(char c);
unsigned short int isOperator(char c);
unsigned short int isSemicolon(char c);
unsigned short int isEOF(char c);

#endif
#pragma once

#ifndef TOKEN_H
#define TOKEN_H

// Token types
#define TOKEN_TYPE_INITIALIZE 1000
#define TOKEN_TYPE_END 1001
#define TOKEN_TYPE_IDENTIFIER 0
#define TOKEN_TYPE_NUMBER 1
#define TOKEN_TYPE_OPERATOR 2
#define TOKEN_TYPE_SEMICOLON 3
#define TOKEN_TYPE_ASSIGN 4

typedef struct
{
  unsigned short int type;
  char *value;
} Token;

Token constructToken(unsigned short int type, char *value);
char *tokenTypeName(unsigned short int typeId); //#static function
void destructToken(Token *token);
void destructTokenNode(Token *token);
unsigned short int getType(Token *token);
void setType(Token *token, unsigned short int type);
char *getValue(Token *token);
void setValue(Token *token, char *value);

#endif
#pragma once

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

size_t charCount(FILE *attachFile);

#endif
#pragma once

#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <stdio.h>

#define INITIAL_STATE 0

Token nextToken(char *content, size_t count);

#endif
