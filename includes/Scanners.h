#ifndef SCANNERS_H
#define SCANNERS_H

unsigned short int isDigit(char c);
unsigned short int isLetter(char c);
unsigned short int isLetterLowCase(char c);
unsigned short int isLetterUpperCase(char c);
unsigned short int isSpace(char c);
unsigned short int isNewLine(char c);
unsigned short int isString(char c);
unsigned short int isRightParenthesis(char c);
unsigned short int isLeftParenthesis(char c);
unsigned short int isOperator(char c);
unsigned short int isSemicolon(char c);
unsigned short int isEOF(char c);

#endif