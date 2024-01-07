#ifndef TOKEN_H
#define TOKEN_H

// Token types
#define TOKEN_TYPE_INITIALIZE 1000
#define TOKEN_TYPE_END 1001
#define TOKEN_TYPE_END_LINE 1002
#define TOKEN_TYPE_IDENTIFIER 0
#define TOKEN_TYPE_NUMBER 1
#define TOKEN_TYPE_OPERATOR 2
#define TOKEN_TYPE_SEMICOLON 3
#define TOKEN_TYPE_ASSIGN 4
#define TOKEN_TYPE_KEYWORDS 5
#define TOKEN_TYPE_STRING 6
#define TOKEN_TYPE_RIGHT_PARENTHESIS 7
#define TOKEN_TYPE_LEFT_PARENTHESIS 8

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