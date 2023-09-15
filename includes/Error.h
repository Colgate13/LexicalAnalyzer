#ifndef ERROR_H
#define ERROR_H

typedef struct
{
  int code;
  char *message;
} Error;

void throwError(int code, char *message);

#endif